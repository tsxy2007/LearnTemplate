#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <deque>
#include <array>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <bitset>
#include <thread>

class FPrint
{
public:
	FPrint(std::string a)
	{
		Val = a;
		std::cout << "-----------" << Val << "----------" << "Begin" << std::endl;
	}
	~FPrint()
	{
		std::cout << "-----------" << Val << "----------" << "End" << std::endl;
	}

private:
	std::string Val;
};

namespace _001
{
	template<typename T>
	T max(T a, T b)
	{
		return b < a ? a : b;
	}

	//template<typename T1, typename T2>
	//T1 max(T1 a, T2 b)
	//{
	//    return b < a ? a : b;
	//}


	template<typename RT = long, typename T1, typename T2>
	RT max(T1 a, T2 b)
	{
		return b < a ? a : b;
	}
};

namespace _2_1_
{
	template<typename T>
	class Stack
	{
	public:
		void push(T const& elem);
		void pop();
		T const& top()const;
		//1. 在模板类里定义
		bool empty() const
		{
			return elems.empty();
		}
	private:
		std::vector<T> elems;
	};
	//2.第二种方法 类外
	template<typename T>
	void Stack<T>::push(T const& elem)
	{
		elems.push_back(elem);
	}

	template<typename T>
	void Stack<T>::pop()
	{
		assert(!elems.empty());
		T elem = elems.back();
		elems.pop_back();
	}

	template<typename T>
	T const& Stack<T>::top() const
	{
		assert(!elems.empty());
		return elems.back();
	}

	template <typename T>
	class C
	{
		static_assert(std::is_default_constructible<T>::value, "Class c Requaires default constructible elements");
	public:
		//C(){}
		//~C(){}

	private:

	};

	class Test
	{
	public:
		Test() = default;
	};

}

namespace _2_4_
{

	//template<typename T>
	//class Stack;
	//template<typename T>
	//std::ostream& operator<< (std::ostream&, Stack<T> const&);
	template<typename T>
	int Test1()
	{
		std::cout << "ni hao wohao";
		return 1;
	}
	template<typename T>
	class Stack
	{
	public:
		void push(T const& elem);
		void pop();
		T const& top()const;
		//1. 在模板类里定义
		bool empty() const
		{
			return elems.empty();
		}

		void printOn(std::ostream& strm) const
		{
			size_t Num = elems.size();
			for (size_t i = 0; i < Num; i++)
			{
				elems[i].printOn(strm);
			}
		}

		template<typename U>
		friend std::ostream& operator<<(std::ostream& strm, Stack<U> const& s)
		{
			//U u;
			//Test(u);
			std::cout << "-------------------" << Test1<U>() << std::endl;
			s.printOn(strm);
			return strm;
		}

		const T& operator[](size_t Index) const
		{
			assert(Index < elems.size());
			return elems[Index];
		}
	private:
		std::vector<T> elems;

	};

	template<typename T>
	void Stack<T>::push(T const& elem)
	{
		elems.push_back(elem);
	}

	template<typename T>
	void Stack<T>::pop()
	{
		assert(!elems.empty());
		T elem = elems.back();
		elems.pop_back();
		return elem;
	}

	template<typename T>
	T const& Stack<T>::top() const
	{
		assert(!elems.empty());
		return elems.back();
	}



	template<>
	class Stack<std::string>
	{
	public:
		void push(std::string const& str);
		void pop();
		std::string const& top()const;
		bool empty()const
		{
			return elems.empty();
		}

		friend std::ostream& operator<< (std::ostream& os, Stack<std::string> const& s)
		{
			size_t Num = s.elems.size();
			for (size_t i = 0; i < Num; i++)
			{
				os << s.elems[i] << ";";
			}
			return os;
		}
	private:
		std::deque<std::string> elems;
	};

	void Stack<std::string>::push(std::string const& elem)
	{
		elems.push_back(elem);
	}

	void Stack<std::string>::pop()
	{
		assert(!elems.empty());
		elems.pop_back();
	}

	std::string const& Stack<std::string>::top()const
	{
		assert(!elems.empty());
		return elems.back();
	}

	template<typename T>
	class Stack<T*>
	{
	private:
		std::vector<T*> elems;
	public:
		void push(T* elem);
		void pop();
		T* top()const;
		bool empty()const
		{
			return elems.empty();
		}
	};

	template<typename T>
	void Stack<T*>::push(T* elem)
	{
		elems.push_back(elem);
	}

	template<typename T>
	void Stack<T*>::pop()
	{
		assert(!elems.empty());
		elems.pop_back();
	}

	template<typename T>
	T* Stack<T*>::top()const
	{
		assert(!elems.empty());
		return elems.back();
	}

	class Test
	{
	public:
		Test() = default;

		void printOn(std::ostream& strm) const
		{
			strm << "hello" << std::endl;
		}
	};
}

namespace _2_5_
{
	template<typename T1, typename T2>
	class MyClass
	{

	};

	template<typename T>
	class MyClass<T, T>
	{

	};

	template<typename T>
	class MyClass<T, int>
	{

	};

	template<typename T1, typename T2>
	class MyClass<T1*, T2*>
	{

	};
}

namespace _2_7_
{
	template<typename T, typename Cont = std::vector<T>>
	class Stack
	{
	private:
		Cont elems;
	public:
		void push(T const& elem);
		void pop();
		T const& top()const;
		bool empty()const
		{
			return elems.empty();
		}
	};

	template<typename T, typename Cont>
	void Stack<T, Cont>::push(T const& elem)
	{
		elems.push_back(elem);
	}

	template<typename T, typename Cont>
	void Stack<T, Cont>::pop()
	{
		assert(!elems.empty());
		elems.pop_back();
	}

	template<typename T, typename Cont>
	T const& Stack<T, Cont>::top()const
	{
		assert(!elems.empty());
		return elems.back();
	}
}

namespace _2_9_
{
	template<typename T>
	class Stack
	{
	private:
		std::vector<T> elems;
	public:
		Stack() = default;
		Stack(T const& elem)
			:elems({ elem })
		{}

		T const& top()const
		{
			assert(!elems.empty());
			return elems.back();
		}
	};

	_2_9_::Stack(const char*)->_2_9_::Stack<std::string>;
	Stack(const bool)->Stack<int>;
}

namespace _2_10_
{
	template<typename T>
	struct ValueWithComment
	{
		T value;
		std::string comment;
	};

	ValueWithComment(char const*, char const*)->ValueWithComment<std::string>;
}

typedef  _2_7_::Stack<int> IntStack;
using IntStack2 = _2_7_::Stack<int>;

namespace _3_1_
{
	template<typename T, std::size_t Maxsize>
	class Stack
	{
	public:
		Stack();
		void push(T const& elem);
		void pop();
		T const& top()const;
		bool empty()const
		{
			return numElems == 0;
		}

		std::size_t size()const
		{
			return numElems;
		}
	private:
		std::array<T, Maxsize> elems;
		std::size_t numElems;
	};

	template<typename T, std::size_t Maxsize>
	Stack<T, Maxsize>::Stack() :
		numElems(0)
	{
		elems.empty();
	}

	template<typename T, std::size_t Maxsize>
	void Stack<T, Maxsize>::push(T const& elem)
	{
		assert(numElems < Maxsize);
		elems[numElems] = elem;
		++numElems;
	}

	template<typename T, std::size_t Maxsize>
	void Stack<T, Maxsize>::pop()
	{
		assert(!elems.empty());
		--numElems;
	}

	template<typename T, std::size_t Maxsize>
	T const& Stack<T, Maxsize>::top() const
	{
		assert(!elems.empty());
		return elems[numElems - 1];
	}
}

namespace _3_2_
{
	template<int Val, typename T>
	T addValue(T x)
	{
		return x + Val;
	}
}

namespace _3_3_
{
	template<typename T, auto Maxsize>
	class Stack
	{
	public:
		using size_type = decltype(Maxsize);
	private:
		std::array<T, Maxsize> elems;
		size_type numElems;
	public:
		Stack();
		void push(T const& elem);
		void pop();
		T const& top()const;
		bool empty()const
		{
			return numElems == 0;
		}
		size_type size()const
		{
			return numElems;
		}
	};

	template<typename T, auto Maxsize>
	Stack<T, Maxsize>::Stack()
		:numElems(0)
	{}

	template<typename T, auto Maxsize>
	void Stack<T, Maxsize>::push(T const& elem)
	{
		assert(numElems < Maxsize);
		elems[numElems] = elem;
		++numElems;
	}

	template<typename T, auto Maxsize>
	void Stack<T, Maxsize>::pop()
	{
		assert(!elems.empty());
		--numElems;
	}

	template<typename T, auto Maxsize>
	T const& Stack<T, Maxsize>::top()const
	{
		assert(!elems.empty());
		return elems[numElems - 1];
	}
}

namespace _4_1_
{
	void print()
	{

	}

	template<typename T>
	void print(T arg)
	{
		std::cout << arg << std::endl;
	}

	template<typename T, typename ... Types>
	void print(T FirstArg, Types... args)
	{
		//std::cout << FirstArg << std::endl;
		std::cout << sizeof...(Types) << " " << sizeof...(args) << std::endl;
		//print(FirstArg);
		//print();
	}
}

namespace _4_2_
{
	template<typename T>
	T Test(const T& t)
	{
		return t;
	}
	template<typename... T>
	auto foldSum(T ... s)
	{
		return (... + Test(s));
	}

	template<typename T>
	class AddSpace
	{
	private:
		T const& ref;
	public:
		AddSpace(T const& r) : ref(r) {}

		friend std::ostream& operator<<(std::ostream& os, AddSpace<T> s)
		{
			return os << s.ref << ' ';
		}
	};

	template<typename... Args>
	void print(Args... args)
	{
		(std::cout << ... << AddSpace<Args>(args)) << std::endl;
	}
}

namespace _4_4_
{

	template<typename T>
	class AddSpace
	{
	private:
		T const& ref;
	public:
		AddSpace(T const& r) : ref(r) {}

		friend std::ostream& operator<<(std::ostream& os, AddSpace<T> s)
		{
			return os << s.ref << ' ';
		}
	};

	template<typename... Types>
	void print(Types... args)
	{
		(std::cout << ... << AddSpace<Types>(args)) << std::endl;
	}

	template<typename ...Types>
	void printDoubled(Types const& ... args)
	{
		print(args + args...);
	}

	template<typename T1, typename... TN>
	constexpr bool isHomogeneous(T1, TN...)
	{
		return (std::is_same<T1, TN>::value && ...);
	}

	template<typename C, typename... Idx>
	void printElems(C const& coll, Idx... idx)
	{
		print(coll[idx]...);
	}

	template<std::size_t... Idx, typename C>
	void printIdx(C const& Coll)
	{
		print(Coll[Idx]...);
	}
}

namespace _4_4_5_
{
	class Customer
	{
	public:
		Customer(std::string const& n) : name(n) {}
		std::string getName()const { return name; }
	private:
		std::string name;
	};

	struct CustomerEq
	{
		bool  operator()(Customer const& c1, Customer const& c2) const
		{
			return c1.getName() == c2.getName();
		}
	};

	struct CusomerHash
	{
		std::size_t operator()(Customer const& c)const
		{
			return std::hash<std::string>()(c.getName());
		}
	};

	template<typename... Bases>
	struct Overloader : Bases...
	{
		using Bases::operator()...;
	};
}

namespace _5_1_
{
	class A
	{
	public:
		class B
		{
		public:
			B() {}
			~B() {}

		private:

		};
	public:
		A() {}
		~A() {}

	private:

	};

	template<typename T>
	class MyClass
	{
	public:
		typename T::B* Ptr;

	private:

	};
}

namespace _5_2_
{
	template<typename T>
	void foo()
	{
		T x{}; // c++11 after
		//T x = T();// c++ 11 Before
		std::cout << x << std::endl;
	}
}

namespace _5_3_
{
	template<typename T>
	class Base
	{
	public:
		void bar()
		{
			std::cout << "this is base bar()" << std::endl;
		}
	private:

	};

	template<typename T>
	class Derived : public Base<T>
	{
	public:
		void foo()
		{
			//bar(); // error Derived没有bar方法
			//this->bar(); // 正确 通过this调用Base类方法；
			Base<T>::bar();// 正确 通过Base<T>::调用Base类方法；
		}
	};
}

namespace _5_4_
{
	template<typename T, int N, int M>
	bool less(T(&a)[N], T(&b)[M])
	{
		for (int i = 0; i < N && i < M; i++)
		{
			if (a[i] < b[i])
			{
				return true;
			}
			if (b[i] < a[i])
			{
				return false;
			}
		}
		return N < M;
	}

	template<int N, int M>
	bool less(char(&a)[N], char(&b)[M])
	{
		for (int i = 0; i < N && i < M; i++)
		{
			if (a[i] < b[i])
			{
				return true;
			}
			if (b[i] < a[i])
			{
				return false;
			}
		}
		return N < M;
	}

	template<typename TT>
	struct MyClass
	{

	};

	template<typename T, std::size_t SZ>
	struct MyClass<T[SZ]>
	{
		static void print()
		{
			std::cout << "print() for T[" << SZ << "]\n";
		}
	};

	template<typename T, std::size_t SZ>
	struct MyClass<T(&)[SZ]>
	{
		static void print()
		{
			std::cout << "print() for T(&)[" << SZ << "]\n";
		}
	};

	template<typename T>
	struct MyClass<T[]>
	{
		static void print()
		{
			std::cout << "print() for T[]" << std::endl;
		}
	};

	template<typename T>
	struct MyClass<T(&)[]>
	{
		static void print()
		{
			std::cout << "print() for T(&)[]" << std::endl;
		}
	};

	template<typename T>
	struct MyClass<T*>
	{
		static void print()
		{
			std::cout << "print() for T*" << std::endl;
		}
	};


	template<typename T1, typename T2, typename T3>
	void foo(int a1[7], int a2[], int(&a3)[42], int(&x0)[], T1 x1, T2& x2, T3&& x3)
	{
		MyClass<decltype(a1)>::print(); // 使用MyClass<T*> 退化成指针
		MyClass<decltype(a2)>::print();// 使用MyClass<T*> 退化成指针
		MyClass<decltype(a3)>::print();// 使用MyClass<T(&)[SZ]> 
		MyClass<decltype(x0)>::print(); //  使用MyClass<T(&)[]> 
		MyClass<decltype(x1)>::print();//  使用MyClass<T*>
		MyClass<decltype(x2)>::print();//  使用MyClass<T(&)[]>
		MyClass<decltype(x3)>::print();//  使用MyClass<T(&)[]> 万能引用， 引用折叠
	}
}

namespace _5_5_
{
	template<typename T>
	class Stack
	{
	private:
		std::deque<T> elems;
	public:
		void push(T const&);
		void pop();
		T const& top() const;
		bool empty()const
		{
			return elems.empty();
		}

		template<typename T2>
		Stack& operator= (Stack<T2> const&);

		void print()
		{
			for (size_t i = 0; i < elems.size(); i++)
			{
				std::cout << elems[i] << std::endl;
			}
		}

		template<typename> friend class Stack;
	};

	template<typename T>
	void Stack<T>::push(T const& a)
	{
		elems.push_back(a);
	}


	template<typename T>
	void Stack<T>::pop()
	{
		assert(!elems.empty());
		elems.pop_back();
	}

	template<typename T>
	T const& Stack<T>::top()const
	{
		assert(!elems.empty());
		return elems.back();
	}

	template<typename T>
	template<typename T2>
	Stack<T>& Stack<T>::operator= (Stack<T2> const& op2)
	{
		/* Stack<T2> tmp(op2);
		 elems.clear();
		 while (!tmp.empty())
		 {
			 elems.push_front(tmp.top);
			 tmp.pop();
		 }
		 return *this;*/

		elems.clear();
		elems.insert(elems.begin(),
			op2.elems.begin(),
			op2.elems.end());
		return *this;
	}
}

namespace _5_5_0_
{
	template<typename T, typename Cont = std::deque<T>>
	class Stack
	{
	private:
		Cont elems;
	public:
		void push(T const&);
		void pop();
		T const& top()const;
		bool empty()const
		{
			return elems.empty();
		}

		template<typename T2, typename Cont2>
		Stack& operator=(Stack<T2, Cont2> const&);

		template<typename, typename> friend class Stack;
	};

	template<typename T, typename Cont>
	void Stack<T, Cont>::push(T const& item)
	{
		elems.push_back(item);
	}

	template<typename T, typename Cont>
	void Stack<T, Cont>::pop()
	{
		ASSERT(!elems.empty());
		elems.pop_back();
	}

	template<typename T, typename Cont>
	T const& Stack<T, Cont>::top()const
	{
		ASSERT(!elems.empty());
		return elems.back();
	}

	template<typename T, typename Cont>
	template<typename T1, typename Cont1>
	Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T1, Cont1> const& op1)
	{
		elems.clear();
		elems.insert(elems.begin(),
			op1.elems.begin(),
			op1.elems.end());
		return *this;
	}
}

namespace _5_5_1_
{
	template<unsigned long N>
	void printBitset(std::bitset<N> const& bs)
	{
		std::cout << bs.template to_string<char, std::char_traits<char>,
			std::allocator<char>>();
	}

	class BoolString
	{
	private:
		std::string value;
	public:
		BoolString(std::string const& s) : value(s)
		{}

		template<typename T = std::string>
		T get() const {
			// get value (converted to T) 
			return value;
		}
	};

	template<>
	inline bool BoolString::get<bool>() const
	{
		return value == "true" || value == "1" || value == "on";
	}
}

namespace _5_5_2_
{
	class SomeCompilerSpecificName
	{
	public:
		template<typename T1, typename T2>
		auto operator()(T1  x, T2 y) const
		{
			return x + y;
		}
	};

}

namespace _5_6_
{
	template<typename T = long double>
	constexpr T pi{ 3.1415926535897932385 };
}

namespace _5_7_
{
	template<typename T, template<typename Elem, typename _Alloc = std::allocator<Elem>> typename Cont = std::deque>
	class Stack
	{
	private:
		Cont<T> elems;
	public:
		void push(T const&);
		void pop();
		T const& top()const;
		bool empty()const
		{
			return elems.empty();
		}

		template<typename T2, template<typename Elem2, typename _Alloc = std::allocator<Elem2>> typename Cont2>
		Stack<T, Cont>& operator=(Stack<T2, Cont2> const& op2);

		template<typename, template<typename, typename>class>
		friend class Stack;
	};

	template<typename T, template<typename, typename>class Cont>
	void Stack<T, Cont>::push(T const& elem)
	{
		elems.push_back(elem);
	}

	template<typename T, template<typename, typename>class Cont>
	void Stack<T, Cont>::pop()
	{
		assert(!elems.empty());
		elems.pop_back();
	}

	template<typename T, template<typename, typename>class Cont>
	T const& Stack<T, Cont>::top()const
	{
		assert(!elems.empty());
		return elems.back();
	}

	template<typename T, template<typename, typename>class Cont>
	template<typename T2, template<typename, typename> typename Cont2>
	Stack<T, Cont>& Stack<T, Cont>::operator=(Stack<T2, Cont2> const& op1)
	{
		elems.clear();
		elems.insert(elems.begin(),
			op1.elems.begin(),
			op1.elems.end());
		return *this;
	}

}

namespace TestSharedPtr
{
	class Base
	{
	public:
		Base()
		{
			std::cout << "Base Initialize" << std::endl;
		}
		~Base()
		{
			i = 0;
			std::cout << "Base Release()" << std::endl;
		}
	public:
		int i = 3;
	};

	template<typename T, typename... Types>
	std::shared_ptr<T> Create(Types... args)
	{
		return std::make_shared<T>(args...);;
	}


	struct FTest
	{
		int a;
		int b;
	};
}

namespace _6_1_0_
{
	class X
	{
	public:
	private:

	};

	void g(X&)
	{
		std::cout << "g() for variable" << std::endl;
	}

	void g(X const&)
	{
		std::cout << "g() for constant" << std::endl;
	}

	void g(X&&)
	{
		std::cout << "g() for movable object" << std::endl;
	}

	void f(X& val)
	{
		g(val);
	}

	void f(X const& val)
	{
		g(val);
	}

	void f(X&& val)
	{
		g(std::move(val));
	}
}

namespace _6_1_1_
{
	class X
	{

	};

	void g(X&)
	{
		std::cout << "g() for variable" << std::endl;
	}

	void g(X const&)
	{
		std::cout << "g() for constant" << std::endl;
	}

	void g(X&&)
	{
		std::cout << "g() for movable object" << std::endl;
	}

	template<typename T>
	void f(T&& val)
	{
		g(std::forward<T>(val));
	}
}

namespace _6_2_0_
{
	class Person
	{
	public:
		explicit Person(std::string const& n) : name(n)
		{
			std::cout << "copying string-CONSTR for '" << name << "'" << std::endl;
		}

		explicit Person(std::string&& n) : name(std::move(n))
		{
			std::cout << "moving string-CONSTR for '" << name << "'" << std::endl;
		}

		Person(Person const& p) : name(p.name)
		{
			std::cout << "COPY-CONSTR Person'" << name << "'\n";
		}

		Person(Person&& p) :name(std::move(p.name))
		{
			std::cout << "MOVE-CONSTR Person ’" << name << "’\n";
		}
	private:
		std::string name;
	};
}

namespace _6_2_1_
{
	class Person;
	template<typename T>
	using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;

	template<typename T>
	using EnableIfPerson = std::enable_if_t<std::is_convertible_v<T, Person>>;

	class Person
	{
	private:
		std::string name;
	public:
		template<typename STR, typename = EnableIfString<STR> /*std::enable_if_t<std::is_convertible_v<STR,std::string>>*/>
		explicit Person(STR&& n) :name(std::forward<STR>(n))
		{
			std::cout << "TMPL-CONSTR for '" << name << "'\n";
		}

		template<typename T, std::enable_if_t<std::is_convertible_v<T, Person>> >
		Person(T&& p) : name(p.name)
		{
			std::cout << "TMPL-Copy Person for '" << name << "'\n";
		}

		Person(Person const& p) : name(p.name)
		{
			std::cout << "COPY-CONSTR Person'" << name << "'\n";
		}

		Person(Person&& p) : name(std::move(p.name))
		{
			std::cout << "Move-CONSTR Person'" << name << "'\n";
		}
	};
}

namespace _6_5_0_
{
	class Person;
	template<typename T>
	concept ConvertibleToString = std::is_convertible_v<T, std::string>;

	template<typename T>
	concept ConvertibleToPerson = std::is_convertible_v< T, Person>;

	class Person
	{
	private:
		std::string name;
	public:
		template<typename STR>
		requires ConvertibleToString<STR>
			explicit Person(STR&& n) :name(std::forward<STR>(n))
		{
			std::cout << "TMPL-CONSTR for '" << name << "'\n";
		}

		template<typename T>
		requires ConvertibleToPerson<T>
			Person(T&& p) :name(p.name)
		{
			std::cout << "TMPL-Copy Person for '" << name << "'\n";
		}

		Person(Person& p) : name(p.name)
		{
			std::cout << "normal Copy Person for '" << name << "'\n";
		}

		Person(Person&& p) : name(p.name)
		{
			std::cout << "rvalue Copy Person for '" << name << "'\n";
		}

		Person(const Person& p) : name(p.name)
		{
			std::cout << "const Copy Person for '" << name << "'\n";
		}

	};
}

namespace _7_1_
{
	template<typename T>
	void printV(T arg)
	{

	}

	std::string returnString()
	{
		return "hi";
	}
}

namespace _7_2_1_
{
	template<typename T>
	void printR(T const& args)
	{
	}

	std::string returnString()
	{
		return "hi";
	}
}

namespace _7_2_2_
{
	//template<typename T,typename = std::enable_if_t<!std::is_const_v<T>>>
	//void printR(T& args)
	//{
	// /*   static_assert(!std::is_const<T>::value, "out parameter of foo<T>(T&) is const");
	//    if (std::is_array_v<T>) 
	//    { 
	//        std::cout << "got array of " << std::extent<T>::value << " elems\n"; 
	//    }*/
	//}

	//template<typename T>
	//void printR(T const& arg)
	//{

	//}

	template<typename T>
	void printR(T& args)
	{
		//static_assert(!std::is_const<T>::value, "out parameter of foo<T>(T&) is const");
		///* if (std::is_array_v<T>)
		// { 
		//     std::cout << "got array of " << std::extent<T>::value << " elems\n"; 
		// }*/
	}

	template<typename T>
	requires (!std::is_const_v<T>)
		void outR(T& args)
	{
		if (std::is_array_v<T>)
		{
			std::cout << "got array of " << std::extent<T>::value << " elems\n";
		}
	}
	template<typename T>
	void outR1(T const& args)
	{
		if (std::is_array_v<T>)
		{
			std::cout << "got array of " << std::extent<T>::value << " elems\n";
		}
	}

	template<typename T>
	void TestR(T& arg)
	{
		arg = {};
	}

	std::string returnString()
	{
		return "hi";
	}
	const std::string returnConstString()
	{
		return "hi";
	}
}

namespace _7_2_3_
{
	template<typename T>
	void passR(T&& arg)
	{
		//T x; //x 必須初始化
		//T x{}; //x 必須初始化

	}
}

namespace _7_3_
{
	void printString(std::string const& s)
	{
		std::cout << s << std::endl;
	}
	template<typename T>
	void printT(T arg)
	{
		printString(arg);
	}
}

namespace _7_4_1_
{
	template<typename T, std::size_t N1, std::size_t N2>
	void foo(T(&arg1)[N1], T(&arg2)[N2])
	{
		T* pa = arg1;
		T* bp = arg2;
	}
}

namespace _7_4_2_
{
	template<typename T, typename = std::enable_if_t<std::is_array_v<T>>>
	void foo(T&& arg1, T&& arg2)
	{

	}
}

namespace _7_5_1_
{
	std::shared_ptr<int>& getInt()
	{
		std::shared_ptr<int> ip = std::make_shared<int>(10);
		return ip;
	}
}

namespace _7_3_0_
{
	void printString(std::string& s)
	{
		std::cout << s << std::endl;
	}

	void printteststring(std::string const& s)
	{
		std::cout << s << std::endl;
	}

	template<typename T>
	void printT(T arg)
	{
		printString(arg);
	}

	struct Date {
		unsigned int nWeekDay : 3;    // 0..7   (3 bits)
		unsigned int nMonthDay : 6;    // 0..31  (6 bits)
		//unsigned int : 0;
		unsigned int nMonth : 5;    // 0..12  (5 bits)
		unsigned int nYear : 8;    // 0..100 (8 bits)
	};
}

namespace _8_1_1_
{
	template<unsigned p, unsigned d>
	struct DoIsPrime
	{
		static constexpr bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
	};

	template<unsigned p>
	struct DoIsPrime<p, 2>
	{
		static constexpr bool value = (p % 2 != 0);
	};

	template<unsigned p>
	struct IsPrime
	{
		static constexpr bool value = DoIsPrime<p, p / 2>::value;
	};

	template<> struct IsPrime<0> { static constexpr bool value = false; };
	template<> struct IsPrime<1> { static constexpr bool value = false; };
	template<> struct IsPrime<2> { static constexpr bool value = true; };
	template<> struct IsPrime<3> { static constexpr bool value = true; };

	template<int SZ, bool = IsPrime<SZ>::value>
	struct Helper;

	template<int SZ>
	struct Helper<SZ, false>
	{
		static constexpr bool value = false;
	};

	template<int SZ>
	struct Helper<SZ, true>
	{
		static constexpr bool value = true;
	};


	class MTest
	{
	public:
		std::vector<int>& operator*()
		{
			return a;
		}
	private:
		std::vector<int> a;
	};


}

namespace _8_2_1_
{
	constexpr bool doIsPrime(unsigned p, unsigned d)
	{
		return d != 2 ? (p % d != 0) && doIsPrime(p, d - 1) : (p % 2 != 0);
	}

	constexpr bool IsPrime(unsigned p)
	{
		return p < 4 ? !(p < 2) : doIsPrime(p, p / 2);
	}

	template<int SZ, bool = IsPrime(SZ)>
	struct Helper;

	template<int SZ>
	struct Helper<SZ, false>
	{
		static constexpr bool value = false;
	};

	template<int SZ>
	struct Helper<SZ, true>
	{
		static constexpr bool value = true;
	};

	// 运行期
	bool fiftySevenIsPrime()
	{
		return IsPrime(57);
	}

	const bool b1 = IsPrime(13);
}

namespace _8_2_2_
{
	constexpr bool isPrime(unsigned int p)
	{
		for (unsigned i = 2; i <= p / 2; i++)
		{
			if (p % i == 0)
			{
				return false;
			}
		}
		return p > 1;
	}

	const bool b1 = isPrime(13);

	// 运行期
	bool fiftySevenIsPrime()
	{
		return isPrime(57);
	}
}

namespace _8_4_0_
{
	template<typename T, unsigned N>
	std::size_t len(T(&)[N])
	{
		return N;
	}

	template<typename T>
	typename T::size_type len(T const& t)
	{
		return t.size();
	}

	std::size_t len(...)
	{
		return 0;
	}
}

namespace _8_4_1_
{
	template<typename T, unsigned N>
	std::size_t len(T(&)[N])
	{
		return N;
	}

	template<typename T>
	auto len(T const& t)->decltype((void)t.size(), T::size_type())
	{
		return t.size();
	}

	std::size_t len(...)
	{
		return 0;
	}
}

namespace _8_5_
{
	template <typename T, typename ... Types>
	void print(T const& firstArg, Types const& ... args)
	{
		std::cout << firstArg;
		if constexpr (sizeof...(args))
		{
			std::cout << ';';
			print(args...);
		}
		else
		{
			std::cout << std::endl;
		}
	}
}

// -----------------------------------------------------------------------------------------------------
namespace _11_1_1_
{
	template<typename Iter, typename Callable>
	void foreach(Iter current, Iter end, Callable op)
	{
		while (current != end)
		{
			op(*current);
			++current;
		}
	}

	void func(int i)
	{
		std::cout << "func() called for: " << i << std::endl;
	}

	class FuncObj
	{
	public:
		void operator()(int i) const
		{
			std::cout << "FuncObj::op() called for : " << i << std::endl;
		}

	};

}

namespace _11_1_2_
{
	class MyClass
	{
	public:
		void memfunc(std::string a, int i) const
		{
			std::cout << "MyClass::memfunc() call for:[" << i << "]" << a << std::endl;
		}
	private:

	};

	template<typename Iter, typename Callable, typename... Args>
	void foreach(Iter current, Iter end, Callable op, Args const... args)
	{
		while (current != end)
		{
			std::invoke(op, args..., *current);
			++current;
		}
	}

	void func(int i)
	{
		std::cout << "func() called for: " << i << std::endl;
	}

	class FuncObj
	{
	public:
		void operator()(std::string a, int i) const
		{
			std::cout << "FuncObj::op(" << a << ") called for : " << i << std::endl;
		}
		FuncObj() {}

	};
}

namespace _11_1_3_
{
	template<typename Callable, typename ... Types>
	decltype(auto) call(Callable&& op, Types&&... args)
	{
		if constexpr (std::is_same_v<std::invoke_result_t<Callable, Types...>, void>)
		{
			std::invoke(std::forward<Callable>(op), std::forward<Types>(args)...);
			return;
		}
		else
		{
			return std::invoke(std::forward<Callable>(op), std::forward<Types>(args)...);
		}
	}

	template<typename Iter, typename Callable, typename... Args>
	void foreach(Iter current, Iter end, Callable op, Args const... args)
	{
		while (current != end)
		{
			call(op, args..., *current);
			++current;
		}
	}
}

namespace _11_2_1
{
	template<typename T>
	class C
	{
		static_assert(!std::is_same_v<std::remove_cv_t<T>, void>, "invalid instantiation of class C for void type");
	public:
		template<typename V>
		void f(V&& v)
		{
			if constexpr (std::is_reference_v<T>)
			{

			}
			if constexpr (std::is_convertible_v<std::decay_t<V>, T>)
			{

			}
			if constexpr (std::has_virtual_destructor_v<V>)
			{

			}
		}
	};
}

namespace _11_4_
{
	template<typename T>
	void tmplParamIsReference(T)
	{
		std::cout << "T is reference: " << std::is_reference_v<T> << std::endl;
	}

	template<typename T, T Z = T{} >
	class RefMem
	{
	public:
		RefMem() : zero{ Z } {}
	private:
		T zero;
	};

	template<typename T, int& SZ>
	class Arr
	{
	private:
		std::vector<T> elems;
	public:
		Arr() : elems(SZ)
		{

			//use current SZ as initial vector size 
		}

		void print() const
		{
			for (int i = 0; i < SZ; ++i)
			{
				//loop over SZ elements 
				std::cout << elems[i] << ' ';
			}
		}
	};
}

namespace _11_5_
{

	template<typename T>
	class Cont
	{
	private:
		T* elems;
	public:
		template<typename D = T>
		typename std::conditional_t<std::is_move_constructible_v<D>, T&&, T&> foo() //
		{

		}
	};

	struct Node
	{
		std::string value;
		Cont<Node> next;
	};
}

namespace _18_1_
{
	struct Coord
	{
		int Type = 0;
	};

	class GeoObj
	{
	public:
		virtual void draw() const = 0;
		virtual Coord center_of_gravity() const = 0;
		virtual ~GeoObj() = default;
	};

	class Circle : public GeoObj
	{
	public:

		virtual void draw() const override
		{
			std::cout << "draw() Circle" << std::endl;
		}
		virtual Coord center_of_gravity() const override
		{
			return { 1 };
		}
	};

	class Line : public GeoObj
	{
	public:

		virtual void draw() const override
		{
			std::cout << "draw() Line" << std::endl;
		}
		virtual Coord center_of_gravity() const override
		{
			return { 2 };
		}
	};

	void myDraw(GeoObj const& obj)
	{
		obj.draw();
	}

	Coord distance(GeoObj const& x1, GeoObj const& x2)
	{
		Coord c1 = x1.center_of_gravity();
		Coord c2 = x2.center_of_gravity();
		return { c2.Type - c1.Type };
	}

	void drawElems(std::vector<GeoObj*> const& elems)
	{
		for (size_t i = 0; i < elems.size(); i++)
		{
			elems[i]->draw();
		}
	}
}

namespace _18_2_
{
	struct Coord
	{
		int Type = 0;
	};

	class Circle
	{
	public:

		virtual void draw() const
		{
			std::cout << "draw() Circle" << std::endl;
		}
		virtual Coord center_of_gravity() const
		{
			return { 1 };
		}
	};

	class Line
	{
	public:

		virtual void draw() const
		{
			std::cout << "draw() Line" << std::endl;
		}
		virtual Coord center_of_gravity() const
		{
			return { 2 };
		}
	};

	template <typename T>
	void myDraw(T const& obj)
	{
		obj.draw();
	}

	template<typename T>
	void drawElems(std::vector<T> const& elems)
	{
		for (size_t i = 0; i < elems.size(); i++)
		{
			elems[i].draw();
		}
	}
}

namespace _18_4_
{
	struct Coord
	{
		int Type = 0;
	};

	template<typename T>
	concept GeoObj = requires(T x)
	{
		{ x.draw() }-> std::convertible_to<void>;
		{ x.center_of_gravity() } ->std::convertible_to<Coord>;
	};

	template<typename T>
	requires GeoObj<T>
		void myDraw(T const& obj)
	{
		obj.draw();
	}


	class Circle
	{
	public:

		virtual void draw() const
		{
			std::cout << "draw() Circle" << std::endl;
		}
		virtual Coord center_of_gravity() const
		{
			return { 1 };
		}
	};

	class Line
	{
	public:

		virtual void draw() const
		{
			std::cout << "draw() Line" << std::endl;
		}
		virtual Coord center_of_gravity() const
		{
			return { 2 };
		}
	};

	class Test
	{
	public:

		virtual void draw() const
		{
			std::cout << "draw() Test" << std::endl;
		}

		virtual Coord center_of_gravity() const
		{
			return { 3 };
		}
	private:

	};

}

namespace _19_1_1_
{
	template<typename T>
	T accum(T const* beg, T const* end)
	{
		T total{};
		while (beg != end)
		{
			total += *beg;
			++beg;
		}
		return total;
	}
}

namespace _19_1_2_
{
	template<typename T>
	struct AccumulationTraits;

	template<>
	struct AccumulationTraits<char>
	{
		using Acct = int;
		static Acct const zero = 0;
	};

	template<>
	struct AccumulationTraits<short>
	{
		using Acct = int;
		static Acct const zero = 0;
	};

	template<>
	struct AccumulationTraits<int>
	{
		using Acct = long;
		static Acct const zero = 0;
	};

	template<typename T>
	auto accum(T  const* beg, T const* end)
	{
		using AccT = typename AccumulationTraits<T>::Acct;
		AccT total = AccumulationTraits<T>::zero;
		while (beg != end)
		{
			total += *beg;
			++beg;
		}
		return total;
	}
}

namespace _19_1_2_1411_
{
	struct BigInt
	{
		int value = 0;

		BigInt operator+(const BigInt& otherr) const
		{
			return { value + otherr.value };
		}

		BigInt operator+=(const BigInt& otherr)
		{
			value += otherr.value;
			return *this;
		}

		BigInt operator/(const int& num) const
		{
			return { value / num };
		}
	};

	template<typename T>
	struct AccumulationTraits;

	template<>
	struct AccumulationTraits<char>
	{
		using Acct = int;
		static constexpr Acct zero()
		{
			return 0;
		}
	};

	template<>
	struct AccumulationTraits<short>
	{
		using Acct = int;
		static constexpr Acct zero()
		{
			return 0;
		}
	};

	template<>
	struct AccumulationTraits<int>
	{
		using Acct = long;
		static constexpr Acct zero()
		{
			return 0;
		}
	};

	template<>
	struct AccumulationTraits<unsigned int>
	{
		using Acct = unsigned long;
		static constexpr Acct zero()
		{
			return 0;
		}
	};

	template<>
	struct AccumulationTraits<float>
	{
		using Acct = double;
		static constexpr Acct zero()
		{
			return 0;
		}
	};

	template<>
	struct AccumulationTraits<BigInt>
	{
		using Acct = BigInt;
		static constexpr Acct zero()
		{
			return BigInt{ 0 };
		}
	};

	template<typename T>
	auto accum(T  const* beg, T const* end)
	{
		using AccT = typename AccumulationTraits<T>::Acct;
		AccT total = AccumulationTraits<T>::zero();
		while (beg != end)
		{
			total += *beg;
			++beg;
		}
		return total;
	}
}

namespace _19_1_2_17_
{
	struct BigInt
	{
		int value = 0;

		BigInt(int v) : value(v) {}

		BigInt operator+(const BigInt& otherr) const
		{
			return { value + otherr.value };
		}

		BigInt operator+=(const BigInt& otherr)
		{
			value += otherr.value;
			return *this;
		}

		BigInt operator/(const int& num) const
		{
			return { value / num };
		}
	};

	template<typename T>
	struct AccumulationTraits;

	template<>
	struct AccumulationTraits<char>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<short>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<int>
	{
		using Acct = long;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<float>
	{
		using Acct = double;
		inline static Acct const zero = { 0.f };
	};

	template<>
	struct AccumulationTraits<BigInt>
	{
		using Acct = BigInt;
		inline static Acct const zero = Acct{ 0 };
	};

	template<typename T>
	auto accum(T  const* beg, T const* end)
	{
		using AccT = typename AccumulationTraits<T>::Acct;
		AccT total = AccumulationTraits<T>::zero;
		while (beg != end)
		{
			total += *beg;
			++beg;
		}
		return total;
	}
}

namespace _19_1_3_17_
{
	struct BigInt
	{
		int value = 0;

		BigInt(int v) : value(v) {}

		BigInt operator+(const BigInt& otherr) const
		{
			return { value + otherr.value };
		}

		BigInt operator+=(const BigInt& otherr)
		{
			value += otherr.value;
			return *this;
		}

		BigInt operator/(const int& num) const
		{
			return { value / num };
		}
	};

	template<typename T>
	struct AccumulationTraits;

	template<>
	struct AccumulationTraits<char>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<short>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<int>
	{
		using Acct = long;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<float>
	{
		using Acct = double;
		inline static Acct const zero = { 0.f };
	};

	template<>
	struct AccumulationTraits<BigInt>
	{
		using Acct = BigInt;
		inline static Acct const zero = Acct{ 0 };
	};

	template<typename T, typename AT = AccumulationTraits<T>>
	auto accum(T  const* beg, T const* end)
	{
		using AccT = typename AT::Acct;
		AccT total = AT::zero;
		while (beg != end)
		{
			total += *beg;
			++beg;
		}
		return total;
	}
}

namespace _19_2_1_
{
	class SumPolicy
	{
	public:
		template<typename T1, typename T2>
		static void accumulate(T1& total, T2 const& value)
		{
			total += value;
		}
	};

	struct BigInt
	{
		int value = 0;

		BigInt(int v) : value(v) {}

		BigInt operator+(const BigInt& otherr) const
		{
			return { value + otherr.value };
		}

		BigInt operator+=(const BigInt& otherr)
		{
			value += otherr.value;
			return *this;
		}

		BigInt operator/(const int& num) const
		{
			return { value / num };
		}
	};

	template<typename T>
	struct AccumulationTraits;

	template<>
	struct AccumulationTraits<char>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<short>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<int>
	{
		using Acct = long;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<float>
	{
		using Acct = double;
		inline static Acct const zero = { 0.f };
	};

	template<>
	struct AccumulationTraits<BigInt>
	{
		using Acct = BigInt;
		inline static Acct const zero = Acct{ 0 };
	};

	template<typename T, typename Policy = SumPolicy, typename AT = AccumulationTraits<T>>
	auto accum(T  const* beg, T const* end)
	{
		using AccT = typename AT::Acct;
		AccT total = AT::zero;
		while (beg != end)
		{
			Policy::accumulate(total, *beg);
			++beg;
		}
		return total;
	}
}

namespace _19_2_2_
{
	template<typename T1, typename T2>
	class SumPolicy
	{
	public:
		static void accumulate(T1& total, T2 const& value)
		{
			total += value;
		}
	};

	struct BigInt
	{
		int value = 0;

		BigInt(int v) : value(v) {}

		BigInt operator+(const BigInt& otherr) const
		{
			return { value + otherr.value };
		}

		BigInt operator+=(const BigInt& otherr)
		{
			value += otherr.value;
			return *this;
		}

		BigInt operator/(const int& num) const
		{
			return { value / num };
		}
	};

	template<typename T>
	struct AccumulationTraits;

	template<>
	struct AccumulationTraits<char>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<short>
	{
		using Acct = int;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<int>
	{
		using Acct = long;
		inline static Acct const zero = { 0 };
	};

	template<>
	struct AccumulationTraits<float>
	{
		using Acct = double;
		inline static Acct const zero = { 0.f };
	};

	template<>
	struct AccumulationTraits<BigInt>
	{
		using Acct = BigInt;
		inline static Acct const zero = Acct{ 0 };
	};

	template<typename T, template<typename, typename> typename Policy = SumPolicy, typename AT = AccumulationTraits<T>>
	auto accum(T  const* beg, T const* end)
	{
		using AccT = typename AT::Acct;
		AccT total = AT::zero;
		while (beg != end)
		{
			Policy<AccT, T>::accumulate(total, *beg);
			++beg;
		}
		return total;
	}
}

namespace _19_3_1_
{
	// 元素类型

	template<typename T>
	struct ElementT;

	template<typename T>
	struct ElementT<std::vector<T>>
	{
		using Type = T;
	};

	template<typename T>
	struct ElementT<std::list<T>>
	{
		using Type = T;
	};

	template<typename T, std::size_t N>
	struct ElementT<T[N]>
	{
		using Type = T;
	};

	template<typename T>
	struct ElementT<T[]>
	{
		using Type = T;
	};

	template<typename T>
	void printElementType(T const& c)
	{
		std::cout << "Container of " << typeid(typename ElementT<T>::Type).name() << " elements.\n";
	}
}

namespace _19_3_2_1_
{
	//删除引用

	template<typename T>
	struct RemoveReferenceT
	{
		using Type = T;
	};

	template<typename T>
	struct RemoveReferenceT<T&>
	{
		using Type = T;
	};

	template<typename T>
	struct RemoveReferenceT<T&&>
	{
		using Type = T;
	};

	template<typename T>
	using RemoveReference = typename RemoveReferenceT<T>::Type;
}

namespace _19_3_2_2_
{
	// 添加引用
	template<typename T>
	struct AddLValueReferenceT
	{
		using Type = T&;
	};

	template<>
	struct AddLValueReferenceT<void>
	{
		using Type = void;
	};

	template<>
	struct AddLValueReferenceT<void const>
	{
		using Type = void const;
	};

	template<>
	struct AddLValueReferenceT<void volatile>
	{
		using Type = void volatile;
	};

	template<>
	struct AddLValueReferenceT<void const volatile>
	{
		using Type = void const volatile;
	};

	template<typename T>
	using AddLValueReference = typename AddLValueReferenceT<T>::Type;


	template<typename T>
	struct AddRValueReferenceT
	{
		using Type = T&&;
	};

	template<typename T>
	using AddRValueReference = typename AddRValueReferenceT<T>::Type;

	template<typename T>
	using AddLValueReferenceT1 = T&;

	template<typename T>
	using AddRValueReferenceT1 = T&&;


}

namespace _19_3_2_3_
{
	template<typename T>
	struct RemoveConstT
	{
		using Type = T;
	};

	template<typename T>
	struct RemoveConstT<T const>
	{
		using Type = T;
	};

	template<typename T>
	using RemoveConst = typename RemoveConstT<T>::Type;

	template<typename T>
	struct RemoveVolatileT
	{
		using Type = T;
	};

	template<typename T>
	struct RemoveVolatileT<T volatile>
	{
		using Type = T;
	};

	template<typename T>
	using RemoveVolatile = typename RemoveVolatileT<T>::Type;

	template<typename T>
	struct RemoveCVT : RemoveConstT<typename RemoveVolatileT<T>::Type>
	{

	};
}

namespace _19_3_2_4_
{
	template<typename T>
	struct DecayT : _19_3_2_3_::RemoveCVT<T>
	{

	};

	template<typename T>
	struct DecayT<T[]>
	{
		using Type = T*;
	};

	template<typename T, std::size_t N>
	struct DecayT<T[N]>
	{
		using Type = T*;
	};

	template<typename R, typename... Args>
	struct DecayT<R(Args...)>
	{
		using Type = R(*)(Args...);
	};

	template<typename R, typename... Args>
	struct DecayT<R(Args..., ...)>
	{
		using Type = R(*)(Args..., ...);
	};

	template<typename T>
	using Decay = typename DecayT<T>::Type;

	template<typename T>
	void f(T)
	{

	}

	template<typename A>
	void printParameterType(void (*)(A))
	{
		std::cout << "Parameter type: " << typeid(A).name() << std::endl;
		std::cout << "- is int: " << std::is_same<A, int>::value << std::endl;
		std::cout << "- is const: " << std::is_const<A>::value << std::endl;
		std::cout << "- is pointer: " << std::is_pointer<A>::value << std::endl;
	}

	template<typename T>
	void printDecayedType()
	{
		using A = typename DecayT<T>::Type;
		using B = Decay<T>;

		std::cout << "Parameter type: " << typeid(A).name() << std::endl;
		std::cout << "- is int: " << std::is_same<A, int>::value << std::endl;
		std::cout << "- is const: " << std::is_const<A>::value << std::endl;
		std::cout << "- is pointer: " << std::is_pointer_v<A> << std::endl;
	}
}

namespace _19_3_3_1_
{
	template<typename T1, typename T2>
	struct isSameT
	{
		static constexpr bool value = false;
	};

	template<typename T>
	struct isSameT<T, T>
	{
		static constexpr bool value = true;
	};


	// 对于产生一个常量的萃取，我们没法为之定义一个别名模板，但是可以为之定义一个扮演相同角色的constexpr的变量模板
	template<typename T1, typename T2>
	constexpr bool isSame = isSameT<T1, T2>::value;
}

namespace _19_3_3_2_
{
	template<bool val>
	struct BoolConstant
	{
		using Type = BoolConstant<val>;
		static constexpr bool value = val;
	};

	using TrueType = BoolConstant<true>;
	using FalseType = BoolConstant<false>;

	template<typename T1, typename T2>
	struct IsSame : FalseType {};

	template<typename T>
	struct IsSame<T, T> : TrueType {};

	template<typename T1, typename T2>
	using IsSameT = typename IsSame<T1, T2>::Type;

	template<typename T1, typename T2>
	constexpr bool IsSameV = IsSame<T1, T2>::value;

	template<typename T>
	void fooImpl(T, TrueType)
	{
		std::cout << "fooImpl(T,true) for int called" << std::endl;
	}

	template<typename T>
	void fooImpl(T, FalseType)
	{
		std::cout << "fooImpl(T,false) for int called" << std::endl;
	}

	template<typename T>
	void foo(T t)
	{
		fooImpl(t, IsSameT<T, int>{});
	}
}

namespace _19_3_4_
{
	// 返回结果类型萃取
	template<typename T1, typename T2>
	struct PlusResultT
	{
		using Type = decltype(T1() + T2());
	};

	template<typename T1, typename T2>
	using PlusResult = typename PlusResultT<T1, T2>::Type;

	template<typename T1, typename T2>
	std::vector<std::remove_cv_t<std::remove_reference_t< PlusResult<T1, T2> > > >
		operator+(std::vector<T1> const& t1, std::vector<T2> const& t2)
	{
		std::vector<std::remove_cv_t<std::remove_reference_t< PlusResult<T1, T2> > > > arr;
		for (size_t i = 0; i < t1.size(); i++)
		{

			arr.push_back((t1[i] + t2[i]) / 2);
		}
		return arr;
	}
}

namespace _19_3_4_2_
{
	template<typename T1, typename T2>
	struct PlusResultT
	{
		using Type = decltype(std::declval<T1>() + std::declval<T2>());
	};

	template<typename T1, typename T2>
	using PlusResult = typename PlusResultT<T1, T2>::Type;


	template<typename T1, typename T2>
	std::vector<std::remove_cv_t<std::remove_reference_t< PlusResult<T1, T2> > > >
		operator+(std::vector<T1> const& t1, std::vector<T2> const& t2)
	{
		std::vector<std::remove_cv_t<std::remove_reference_t< PlusResult<T1, T2> > > > arr;
		for (size_t i = 0; i < t1.size(); i++)
		{

			arr.push_back((t1[i] + t2[i]) / 2);
		}
		return arr;
	}
}

namespace _19_4_1_
{
	template<typename T>
	struct IsDefaultConstructibleT
	{
	private:
		template<typename U, typename = decltype(U())>
		static char test(void*);

		template<typename>
		static long test(...);
	public:
		static constexpr bool value = _19_3_3_2_::IsSameV<decltype(test<T>(nullptr)), char>;
	};
}

namespace _19_4_2_
{
	template<typename, typename = std::void_t<>>
	struct IsDefaultConstructibleT : std::false_type
	{

	};

	template<typename T>
	struct IsDefaultConstructibleT<T, std::void_t<decltype(T())>> : std::true_type
	{

	};
}

namespace _19_4_3_
{
	struct Test
	{
		//Test() = delete;
		int First;
	};
	// 将泛型lambdas用于SFINAE
	template<typename F, typename... Args,
		typename = decltype(std::declval<F>()(std::declval<Args&&>()...))>
		std::true_type isValidImpl(void*);

	template<typename F, typename... Args>
	std::false_type isValidImpl(...);

	inline constexpr auto isValid = [](auto f)
	{
		return [](auto&&... args)
		{
			return decltype(isValidImpl<decltype(f), decltype(args)&&...>(nullptr)){};
		};
	};

	template<typename T>
	struct TypeT
	{
		using Type = T;
	};

	template<typename T>
	constexpr auto type = TypeT<T>();

	template<typename T>
	T valueT(TypeT<T>);

	constexpr auto isDefaultConstructible = isValid([](auto x) -> decltype((void)decltype(valueT(x))()) {});
	constexpr auto HasFirst = isValid([](auto x)->decltype((void)valueT(x).First) {});
}

namespace _19_5_1_
{
	template<typename FROM, typename TO>
	struct IsConvertibleHelper
	{
	private:
		static void aux(TO);

		template<typename F, typename = decltype(aux(std::declval<F>()))>
		static std::true_type test(void*);

		template<typename>
		static std::false_type test(...);

	public:
		using Type = decltype(test<FROM>(nullptr));
	};

	template<typename FROM, typename TO>
	struct IsConveribleT : IsConvertibleHelper<FROM, TO>::Type {};

	template <typename FROM, typename TO>
	using IsConvertible = typename IsConveribleT<FROM, TO>::Type;

	template<typename FROM, typename TO>
	constexpr bool isConvertible = IsConveribleT<FROM, TO>::value;
}

namespace _19_5_2_
{
	template<typename FROM, typename TO, bool = std::is_void_v<TO> || std::is_array_v<TO> || std::is_function_v<TO>>
	struct IsConvertibleHelper
	{
		using Type = std::integral_constant<bool, std::is_void_v<TO>&& std::is_void_v<FROM>>;
	};

	template<typename FROM, typename TO>
	struct IsConvertibleHelper<FROM, TO, false>
	{
	private:
		static void aux(TO);

		template<typename F, typename = decltype(aux(std::declval<F>()))>
		static std::true_type test(void*);

		template<typename>
		static std::false_type test(...);
	public:
		using Type = decltype(test<FROM>(nullptr));
	};

	template<typename FROM, typename TO>
	struct IsConveribleT : IsConvertibleHelper<FROM, TO>::Type {};

	template <typename FROM, typename TO>
	using IsConvertible = typename IsConveribleT<FROM, TO>::Type;

	template<typename FROM, typename TO>
	constexpr bool isConvertible = IsConveribleT<FROM, TO>::value;
}

namespace _19_6_1_
{
	template<typename, typename = std::void_t<>>
	struct HasSizeTypeT : std::false_type {};

	template<typename T>
	struct HasSizeTypeT<T, std::void_t<typename std::remove_reference_t<T>::size_type > > : std::true_type {};
}

namespace _19_6_2_
{
#define DEFINE_HAS_TYPE(MemType) \
    template<typename,typename = std::void_t<>> \
    struct HasTypeT_##MemType : std::false_type{}; \
    template<typename T> \
    struct HasTypeT_##MemType<T, std::void_t<typename std::remove_reference_t<T>::MemType > > : std::true_type {};

	DEFINE_HAS_TYPE(value_type);
	DEFINE_HAS_TYPE(char_type);
}

namespace _19_6_3_
{
#define DEFINE_HAS_MEMBER(Member) \
        template<typename,typename = std::void_t<>>\
        struct HasMemberT_##Member : std::false_type {}; \
        template<typename T> \
        struct HasMemberT_##Member<T,std::void_t<decltype(&T::Member)>> : std::true_type{};


	DEFINE_HAS_MEMBER(size);
	DEFINE_HAS_MEMBER(first);
	//DEFINE_HAS_MEMBER(begin);// error 重载函数不可以

#define DEFINE_HAS_FUNCTION(FUNC) \
    template<typename, typename = std::void_t<>>\
    struct HasMemberT_##FUNC : std::false_type {};\
    template<typename T>\
    struct HasMemberT_##FUNC<T, std::void_t<decltype(std::declval<T>().FUNC())>> : std::true_type {};

	DEFINE_HAS_FUNCTION(begin);


	template<typename, typename, typename = std::void_t<>>
	struct HasLessT : std::false_type {};

	template<typename T1, typename T2>
	struct  HasLessT < T1, T2, std::void_t< decltype(std::declval<T1>() < std::declval<T2>())> > : std::true_type{};

}

namespace _19_7_1_
{
	template<bool COND, typename TrueType, typename FalseType>
	struct  ifThenElseT
	{
		using Type = TrueType;
	};

	template<typename TrueType, typename FalseType>
	struct  ifThenElseT<false, TrueType, FalseType>
	{
		using Type = FalseType;
	};

	template<bool COND, typename TrueType, typename FalseType>
	using IfThenElse = typename ifThenElseT<COND, TrueType, FalseType>::Type;

	template<typename T>
	struct MakeUnsignedT
	{
		using Type = typename std::make_unsigned<T>::type;
	};
	template<typename T>
	struct IdentityT
	{
		using Type = T;
	};

	template<typename T>
	struct UnsignedT
	{
		using Type = IfThenElse<(std::is_integral_v<T> && !std::is_same_v<T, bool>), MakeUnsignedT<T>, IdentityT<T> >::Type;
	};
}

namespace _19_7_2_
{
	template<typename T, typename = std::void_t<>>
	struct IsNothrowMoveConstructibleT : std::false_type
	{ };
	template<typename T>
	struct IsNothrowMoveConstructibleT<T, std::void_t<decltype(T(std::declval<T>()))>>
		: std::bool_constant<noexcept(T(std::declval<T>()))>
	{

	};

	template<typename T1, typename T2>
	class Pair
	{
	public:
		Pair(Pair&& other)
			noexcept(IsNothrowMoveConstructibleT<T1>::value&& IsNothrowMoveConstructibleT<T2>::value)
			: first(std::forward<T1>(other.first)),
			second(std::forward<T2>(other.second)) { }

		Pair(const T1& _Val1, const T2& _Val2) : first(_Val1), second(_Val2) {}
	private:
		T1 first;
		T2 second;
	};

	class E
	{
	public:
		E(E&&) = delete;
		E() {};
		E(const E&) {};
	};
}

namespace _19_8_1_
{
	template<typename T>
	struct IsFundaT : std::false_type { };

#define MK_FUNDA_TYPE(T) \
    template<> struct IsFundaT<T> : std::true_type{ };

	MK_FUNDA_TYPE(void);
	MK_FUNDA_TYPE(bool);
	MK_FUNDA_TYPE(char);
	MK_FUNDA_TYPE(signed char);
	MK_FUNDA_TYPE(unsigned char);
	MK_FUNDA_TYPE(wchar_t);
	MK_FUNDA_TYPE(char16_t);
	MK_FUNDA_TYPE(char32_t);
	MK_FUNDA_TYPE(signed short);
	MK_FUNDA_TYPE(unsigned short);
	MK_FUNDA_TYPE(signed int);
	MK_FUNDA_TYPE(unsigned int);
	MK_FUNDA_TYPE(signed long);
	MK_FUNDA_TYPE(unsigned long);
	MK_FUNDA_TYPE(signed long long);
	MK_FUNDA_TYPE(unsigned long long);
	MK_FUNDA_TYPE(float);
	MK_FUNDA_TYPE(double);
	MK_FUNDA_TYPE(long double);
	MK_FUNDA_TYPE(std::nullptr_t);
#undef MK_FUNDA_TYPE


	template<typename T>
	void Test(T const& it)
	{
		if (IsFundaT<T>::value)
		{
			std::cout << "T is a fundamental type" << std::endl;
		}
		else
		{
			std::cout << "T is not a fundamental type" << std::endl;
		}
	}
}

namespace _19_8_2_
{

	template<typename T>
	struct IsPointerT : std::false_type
	{

	};

	template<typename T>
	struct IsPointerT<T*> : std::true_type
	{
		using BaseT = T;
	};

	template<typename T>
	struct IsLValueReferenceT : std::false_type
	{

	};
	template<typename T>
	struct IsLValueReferenceT<T&> : std::true_type
	{
		using BaseT = T;
	};

	template<typename T>
	struct IsRValueReferenceT : std::false_type
	{

	};

	template<typename T>
	struct IsRValueReferenceT<T&&> : std::true_type
	{
		using BaseT = T;
	};

	template<typename T>
	struct IsArrayT : std::false_type
	{

	};

	template<typename T, std::size_t N>
	struct IsArrayT<T[N]> : std::true_type
	{
		using BaseT = T;
		static constexpr std::size_t size = N;
	};

	template<typename T>
	struct IsArrayT <T[]> : std::true_type
	{
		using BaseT = T;
		static constexpr std::size_t size = 0;
	};

	template<typename T>
	struct IsPointerToMemberT : std::false_type
	{

	};

	template<typename T, typename C>
	struct IsPointerToMemberT<T C::*> : std::true_type
	{
		using MemberT = T;
		using ClassT = C;
	};
}

namespace _19_8_3_
{

	template<typename... Elements>
	class Typelist
	{
	};

	template<typename T>
	struct IsFunctionT : std::false_type
	{

	};

	template<typename R, typename... Params>
	struct IsFunctionT <R(Params...)> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = false;
	};

	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params..., ...)> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = true;
	};

	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params...) const> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = false;
	};

	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params...) volatile> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = true;
	};

	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params..., ...) volatile> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = true;
	};


	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params..., ...) const volatile> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = true;
	};

	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params..., ...)&> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = true;
	};

	template<typename R, typename ... Params>
	struct IsFunctionT<R(Params..., ...) const&> : std::true_type
	{
		using RType = R;
		using ParamsT = Typelist<Params...>;
		static constexpr bool variadic = true;
	};

	int Test(int i)
	{
		return 1;
	}
}

int size = 10;
int main()
{
	{
		std::cout << _001::max(3, 2) << std::endl;
		std::cout << _001::max(7.21, 3.9) << std::endl;
		std::string s1 = "mathmatrics";
		std::string s2 = "math";
		std::cout << _001::max(s1, s2) << std::endl;

		std::cout << _001::max(40, 60.66) << std::endl;


		_2_1_::Stack<int> intStack;
		intStack.push(7);
		std::cout << intStack.top() << std::endl;

		_2_1_::Stack<std::string> stringStack;
		stringStack.push("hello");
		std::cout << stringStack.top() << std::endl;

		_2_1_::C <_2_1_::Test> _2_1_C;

		_2_4_::Stack<_2_4_::Test> _2_4_Stack;

		_2_4_::Test _2_4_C;
		_2_4_Stack.push(_2_4_C);
		std::cout << _2_4_Stack;

		_2_4_Stack[0];

		_2_4_::Stack<std::string> _2_4_string;
		_2_4_string.push("aaaaaa");
		_2_4_string.push("bbbbbb");

		std::cout << _2_4_string << std::endl;

		_2_4_::Stack<int*> ptrStack;
		ptrStack.push(new int{ 42 });
		std::cout << *ptrStack.top() << std::endl;

		_2_5_::MyClass<int, float> mif;
		_2_5_::MyClass<float, float> mff;
		_2_5_::MyClass<float, int>mfi;
		_2_5_::MyClass<int*, float*>mp;
		//_2_5_::MyClass<int, int> mii;

		_2_7_::Stack<int> _27_Int;
		_27_Int.push(1);
		_27_Int.push(2);
		_27_Int.push(3);

		std::cout << _27_Int.top() << std::endl;

		IntStack _27_a;
		_27_a.push(11);
		_27_a.push(22);
		std::cout << _27_a.top() << std::endl;


		IntStack2 _27_b;
		_27_b.push(111);
		_27_b.push(222);
		std::cout << _27_b.top() << std::endl;

		_2_9_::Stack _29_a(1);
		_2_9_::Stack _29_b = 1;

		std::cout << _29_b.top() << std::endl;

		_2_9_::Stack _29_string{ "aaaaa" };

		std::cout << _29_string.top() << std::endl;

		_2_10_::ValueWithComment _210_VC = { "hello","initial value" };
		std::cout << _210_VC.value << ":" << _210_VC.comment << std::endl;

		_3_1_::Stack<int, 10> _31_intStack;
		_31_intStack.push(10);
		std::cout << _31_intStack.top() << std::endl;

		std::array<int, 10> bArray = { 1,2,3,4,5,6,7,8,9,10 };
		std::array<int, 10> aArray;
		std::transform(bArray.begin(), bArray.end(), aArray.begin(), _3_2_::addValue<10, int>);
		for (size_t i = 0; i < aArray.size(); i++)
		{
			std::cout << aArray[i] << std::endl;
		}


		_3_3_::Stack<int, 10> _33_intStack;
		_33_intStack.push(100);
		std::cout << _33_intStack.top() << std::endl;

		_4_1_::print("111", "222", "333", "444");

		std::cout << _4_2_::foldSum(1, 2, 3, 4, 5) << std::endl;

		_4_2_::print("111", 1020, 40.3f, "nihao");
		_4_4_::printDoubled(1020, 40.3f);

		std::cout << _4_4_::isHomogeneous(1, 2, 3, 'a') << std::endl;

		std::vector<std::string> stringVector{ "nihao","nihao1","nihao2" };
		_4_4_::printElems(stringVector, 1, 0);
		_4_4_::printIdx<0, 1, 2>(stringVector);

		std::array<int, 10> arrryint{ 1,2,3 };

		using CusomerOP = _4_4_5_::Overloader<_4_4_5_::CusomerHash, _4_4_5_::CustomerEq>;

		std::unordered_set<_4_4_5_::Customer, _4_4_5_::CusomerHash, _4_4_5_::CustomerEq> _4_4_5_Coll1;
		std::unordered_set<_4_4_5_::Customer, CusomerOP, CusomerOP> _4_4_5_Coll2;
	}


	//-------------------------------------------第五章---------------------------------------------------------
	{}
	{
		int i = 0;
		//_5_1_...................
		{
			_5_1_::MyClass<_5_1_::A> _51_A;
		}

		//_5_2_...................
		{
			_5_2_::foo<int>();
		}

		//_5_3_...................
		{
			_5_3_::Derived<int> _53_Derived;
			_53_Derived.foo();
		}

		// 5_4_...........................
		{
			int _54_x[] = { 1,2,3 };
			int _54_y[] = { 1,2,3,4,5 };
			std::cout << _5_4_::less(_54_x, _54_y) << std::endl;

			std::cout << _5_4_::less("abc", "abcd") << std::endl;

			int _54_a[42];
			_5_4_::MyClass<decltype(_54_a)>::print();
			_5_4_::MyClass<decltype(_54_x)>::print();

			_5_4_::foo(_54_a, _54_a, _54_a, _54_x, _54_x, _54_x, _54_x);

		}

		//5_5_...........................
		{
			//5_5_................
			_5_5_::Stack<int> a;
			a.push(1);
			a.push(1);
			a.push(1);
			_5_5_::Stack<int> b;
			b = a;
			b.print();
		}

		//5_5_0_...........................
		{
			_5_5_0_::Stack<int> _5_5_0_a;
			_5_5_0_a.push(2);
			_5_5_0_a.push(2);
			_5_5_0_a.push(2);
			_5_5_0_::Stack<int> _5_5_0_b;
			_5_5_0_b = _5_5_0_a;
		}

		//5_5_1_........................
		{
			_5_5_1_::BoolString _5_5_1_b("true");
			std::cout << "_5_5_1_b = " << _5_5_1_b.get<bool>() << std::endl;
		}

		//5_5_2.......................
		{
			_5_5_2_::SomeCompilerSpecificName Some;
			std::cout << Some(1, 2) << std::endl;
		}

		//_5_6_..............................
		{
			std::cout << _5_6_::pi<float> << std::endl;
			std::cout << _5_6_::pi<double> << std::endl;
			std::cout << _5_6_::pi<> << std::endl;
		}

		//_5_7_....................................
		{
			_5_7_::Stack<int> iStack;
			_5_7_::Stack<float> fStack;
			iStack.push(1);
			iStack.push(2);
			iStack.push(3);
			std::cout << "iStack.top():" << iStack.top() << std::endl;

			fStack.push(7.3);
			std::cout << "fStack.top():" << fStack.top() << std::endl;

			// 大量的warning
			fStack = iStack;
			std::cout << "fStack.top():" << fStack.top() << std::endl;
		}
	}

	{


		std::shared_ptr<TestSharedPtr::Base> a = TestSharedPtr::Create<TestSharedPtr::Base>();

		std::cout << "接受对象a = " << &a << std::endl;
		std::cout << "sizeof sharedptr = " << sizeof(a) << "sizeof(int*)" << sizeof(int*) << "---" << a->i << std::endl;

		TestSharedPtr::FTest ft = { .a = 1 };
	}
	// ------------------------------------------6----------------------------------------------------------------
	{
		{
			using namespace _6_1_0_;
			X v;
			X const c;
			f(v);
			f(c);
			f(X());
			f(std::move(v));
		}

		{
			using namespace _6_1_1_;
			X v;
			X const c;
			f(v);
			f(c);
			f(X());
			f(std::move(v));
		}

		{
			using namespace _6_2_0_;
			std::string s = "sname";
			Person p1(s);
			Person p2("tmp");
			Person p3(p1);
			Person p4(std::move(p1));
		}
		std::cout << "--------------------------------" << std::endl;
		{
			using namespace _6_2_1_;

			std::string s = "sname";
			Person p1(s);
			Person p2("tmp");
			Person p3(p1);
			Person p4(std::move(p1));
		}
		std::cout << "--------------------------------" << std::endl;
		{
			using namespace _6_5_0_;
			std::string s = "sname";
			Person p1(s);
			Person p2("tmp");
			Person p3(p1);
			Person p4{ std::move(p1) };
			const Person p5{ "1111" };
			Person p6(p5);
		}
		{

			class T
			{
			public:
				T&& operator++(int)
				{
					return  std::move(*this);
				}
				T& operator++()
				{
					return *this;
				}

			};

			T t, t1;
			++t = t;
			t++ = t;
			t1 = t++;
			//std::cout << &(t++) << std::endl;
			//std::cout << &(++t) << std::endl;

			auto reft = std::cref<>(t);
			auto reft2 = std::cref(reft);
			std::cout << "reft size = " << sizeof(reft) << std::endl;
			std::cout << std::boolalpha;
			std::cout << std::negation<std::bool_constant<true>>::value << '\n';
			std::cout << std::negation<std::bool_constant<false>>::value << '\n';
			std::conditional_t<false, int, float> conditional_a = 1.1;
			std::cout << conditional_a << std::endl;
		}
	}

	// ------------------------------------------7----------------------------------------------------------------
	{
		//7.1-------------
		{
			using namespace _7_1_;
			std::string s = "hi";
			_7_1_::printV(s); // 传递了一个lvalue，这会使用std::string的copy constructor。
			_7_1_::printV(std::string("hi")); //这里传递的是prvalue(随手建立的临时对象或者函数返回的临时对象)，通常状况下编译器会进行参数传递的优化，不会致使copy constructor 
			_7_1_::printV(returnString());//这里传递的是prvalue(随手建立的临时对象或者函数返回的临时对象)，通常状况下编译器会进行参数传递的优化，不会致使copy constructor 
			_7_1_::printV(std::move(s));//传递的是xvalue(一个使用过std::move后的对象)，这会调用move constructor。
			//虽然上面4种状况只有第一种才会调用copy constructor，可是这种状况才是最多见的。
		}
		//7.2.1
		{
			// ------------------------------------------7----------------------------------------------------------------
			{
				/// 7_3_
				{
					std::string s = "hello";
					_7_3_0_::printString(s);
					_7_3_0_::printT(std::ref(s));
					//_7_3_0_::printString(std::move(s));error 不允许将临时变量(prvalue)或者通过std::move()处理过的已存在的(xvalue)用作其参数。
					std::cout << sizeof(_7_3_0_::Date) << ":" << sizeof(unsigned int) << std::endl;
				}
			}

			// 本质是通过传递参数的地址实现的。 不会做类型退化。
			using namespace _7_2_1_;
			std::string s = "hi";
			std::string returnString1();

			printR(s);
			printR(std::string("hi"));
			printR(returnString());
			printR(std::move(s));

		}
		{
			//7.2.2
			using namespace _7_2_2_;
			std::string returnString();
			std::string s = "hi";
			const std::string& s1 = "";
			printR(s);/*
			printR(std::string("hi"));
			printR(returnString());
			printR(std::move(s));*/
			printR(s1);
			printR(std::move(s1));
			printR(returnConstString());
			printR("hi");
			//int arr[4];
			//printR(arr);

			//std::string const c = "hi";
			//outR1(c);
			//outR1(std::move(c));
			//outR1("hi");
		}
		{
			//7.2.3
			using namespace _7_2_3_;
			std::string s = "hi";
			passR(s); // T deduced as std::string
			passR(std::string("hi"));// T deduced as std::string
			passR(_7_2_2_::returnString());
			passR(std::move(s));
			int arr[4];
			passR(arr);
			int a;
			passR(a);

		}
		//7.3
		{
			using namespace _7_3_;
			std::string s = "hello";
			printT(s);
			printT(std::cref(s));

			std::make_pair(1, 2);

		}
		//7.5
		{
			const int& x = 0;
			auto& y = _7_5_1_::getInt();
			std::cout << *y.get() << std::endl;
		}
	}
	// ------------------------------------------8----------------------------------------------------------------
	{
		// 1,2,3
		{
			std::cout << "模板元编程:" << _8_1_1_::IsPrime<11>::value << std::endl;
			std::cout << "模板元编程 helper:" << _8_1_1_::Helper<11>::value << std::endl;
			std::cout << "模板元编程:" << _8_1_1_::IsPrime<10>::value << std::endl;
			std::cout << "模板元编程 helper:" << _8_1_1_::Helper<10>::value << std::endl;
			{
				unsigned a = 10;
				constexpr bool isprime1 = _8_2_1_::IsPrime(11);
				std::cout << "constexpr:" << isprime1 << std::endl; //编译期
				std::cout << "constexpr:" << _8_2_1_::IsPrime(11) << std::endl; //运行期
				std::cout << "constexpr helper:" << _8_2_1_::Helper<11>::value << std::endl; //编译期
				std::cout << "constexpr:" << _8_2_1_::IsPrime(a) << std::endl; // 运行期
				std::cout << "constexpr helper:" << _8_2_1_::Helper<10>::value << std::endl;

				std::cout << "_8_2_1_::constexpr b1:" << _8_2_1_::b1 << std::endl;
				std::cout << "_8_2_1_::constexpr fiftySevenIsPrime:" << _8_2_1_::fiftySevenIsPrime() << std::endl;
			}
			{
				unsigned a = 10;
				constexpr bool isprime1 = _8_2_2_::isPrime(11);//编译期
				bool isprime2 = _8_2_2_::isPrime(a);
				std::cout << "_8_2_2_constexpr:" << isprime1 << std::endl; //编译期
				std::cout << "_8_2_2_constexpr:" << _8_2_2_::isPrime(11) << std::endl; //运行期
				std::cout << "_8_2_2_constexpr:" << isprime2 << std::endl; // 运行期
				std::cout << "_8_2_2_::constexpr b1:" << _8_2_2_::b1 << std::endl;
				std::cout << "_8_2_2_::constexpr fiftySevenIsPrime:" << _8_2_2_::fiftySevenIsPrime() << std::endl;

			}

			std::allocator<int> x;
			std::vector<int> x1{ 1,2,3,4,5,6 };
			std::cout << std::size(x1) << std::endl;

			_8_1_1_::MTest test;
			(*test).push_back(1);
			(*test).push_back(2);
			(*test).push_back(3);
			for (size_t i = 0; i < (*test).size(); i++)
			{
				std::cout << (*test)[i] << std::endl;
			}


		}
		//8.4
		{
			// 数组
			int a[10];
			std::cout << "_8_4_0_ no size():" << _8_4_0_::len(a) << std::endl;
			std::cout << "_8_4_0_ no size():" << _8_4_0_::len("tmp") << std::endl;
			// 其他数据结构
			std::vector<int> v;
			v.push_back(1);
			std::cout << "_8_4_0_ has size():" << _8_4_0_::len(v) << std::endl;
			// 指针
			int* p = new int(0);
			std::cout << "_8_4_0_ has point:" << _8_4_0_::len(p) << std::endl;
			// allocator 没有匹配项
			std::allocator<int> x;
			//std::cout << "_8_4_0_ allocator:" << _8_4_0_::len(x) << std::endl;
		}
		//4.1
		{
			// 数组
			int a[10];
			std::cout << "_8_4_1_ no size():" << _8_4_1_::len(a) << std::endl;
			std::cout << "_8_4_1_ no size():" << _8_4_1_::len("tmp") << std::endl;
			// 其他数据结构
			std::vector<int> v;
			v.push_back(1);
			std::cout << "_8_4_1_ has size():" << _8_4_1_::len(v) << std::endl;
			// 指针
			int* p = new int(0);
			std::cout << "_8_4_1_ has point:" << _8_4_1_::len(p) << std::endl;
			// allocator 没有匹配项
			std::allocator<int> x;
			std::cout << "_8_4_1_ allocator:" << _8_4_1_::len(x) << std::endl;

			_8_5_::print(1);
		}
	}

	//------------------------------------------11----------------------------------------------------------------
	{
		// 11.1.1
		{
			std::vector<int> primes = { 1,2,3,4,5,6,7,8 };
			_11_1_1_::foreach(primes.begin(), primes.end(), _11_1_1_::func);
			_11_1_1_::foreach(primes.begin(), primes.end(), &_11_1_1_::func);
			_11_1_1_::FuncObj funcObj;
			_11_1_1_::foreach(primes.begin(), primes.end(), funcObj);
			_11_1_1_::foreach(primes.begin(), primes.end(), [](int i) {
				std::cout << "lambda func [" << i << "]" << std::endl;
				});
		}
		// 11.1.2
		{
			std::vector<int> primes = { 1,2,3,4,5,6,7,8 };
			_11_1_2_::foreach(primes.begin(), primes.end(), [](std::string a, int i) {
				std::cout << "输出：" << a << ":" << i << std::endl;
				}, "hello");
			_11_1_2_::MyClass obj;
			_11_1_2_::foreach(primes.begin(), primes.end(), &_11_1_2_::MyClass::memfunc, obj, "world");



			_11_1_2_::foreach(primes.begin(), primes.end(), _11_1_2_::func);
			_11_1_2_::FuncObj funcObj = _11_1_2_::FuncObj();
			_11_1_2_::foreach(primes.begin(), primes.end(), funcObj, "_11_1_2_");

			//std::for_each_n(primes.begin(), primes.end(), &_11_1_2_::MyClass::memfunc, obj, "world");
			std::addressof(obj);

			std::forward<_11_1_2_::MyClass>(obj);
			std::move(obj);
		}
		//11.1.3
		{
			auto func = []() ->std::string
			{
				return "hello world";
			};

			auto func1 = [](std::string arg1, int i)
			{
				std::cout << "hello world 2" << arg1 << i << std::endl;
			};

			std::cout << _11_1_3_::call(func) << std::endl;
			_11_1_3_::call(func1, "11111111111", 3333);

			std::vector<int> primes = { 1,2,3,4,5,6,7,8 };
			_11_1_3_::foreach(primes.begin(), primes.end(), [](int i) {
				std::cout << "---------" << i << std::endl;
				});

			_11_1_2_::FuncObj funcObj = _11_1_2_::FuncObj();
			_11_1_3_::foreach(primes.begin(), primes.end(), funcObj, "_11_1_3_");
		}
		// 二進制操作
		{

			auto func = [](int NumHandles, int Offset, int& a) {
				a |= ((1 << NumHandles) - 1) << Offset;
			};
			int a = 0;
			func(1, 2, a);
			func(2, 0, a);
			//func(1, 5, a);
			uint32_t index;
			_BitScanReverse((unsigned long*)&index, a);
			std::cout << "从高位向低位搜索" << index << std::endl;
			uint32_t index1;
			_BitScanForward((unsigned long*)&index1, a);
			std::cout << "从低位向高位搜索" << index1 << std::endl;
		}

		// 11.4
		{
			using namespace _11_4_;
			std::cout << std::boolalpha;
			int i;
			int& r = i;

			tmplParamIsReference(i);
			tmplParamIsReference(r);
			tmplParamIsReference<int&>(i);
			tmplParamIsReference<int&>(r);

			RefMem<int> rm1, rm2;
			rm1 = rm2;

			//RefMem<int&> rm3; // 需要左值
			//RefMem<int&, 0>rm4; // 不能从int 转换成int&

			//Arr<int&, size> x;// error 编译错误在vector;
			//Arr<int, size> y;
			//y.print();
			//size += 100; //modifies SZ in Arr<>
			//y.print();// run-time ERROR: invalid memory access: loops over 120 elements

			std::pair<int, int>a;

		}
	}
	//------------------------------------------------18-----------------------------------------------------------
	{}
	{
		// 18.1
		{
			using namespace _18_1_;
			Line l;
			Circle c, c1, c2;
			myDraw(l);
			myDraw(c1);
			std::vector<GeoObj*> coll;
			coll.push_back(&l);
			coll.push_back(&c2);
			coll.push_back(&c1);
			drawElems(coll);
		}
		std::cout << "18-2......................................." << std::endl;
		//18.2
		{
			using namespace _18_2_;

			Line l;
			Circle c;
			myDraw(l);
			myDraw(c);
			std::vector<Line> lV;
			lV.push_back(l);
			drawElems(lV);
		}
		//18.4
		{
			std::cout << "18-4......................................." << std::endl;
			using namespace _18_4_;

			Line l;
			Circle c;
			Test t;
			myDraw(l);
			myDraw(c);
			myDraw(t);
		}
	}

	//------------------------------------------19----------------------------------------------------------------

	{}
	{
		// 19_1_1_
		{
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_1_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_1_::accum(name, name + lenght) / lenght << std::endl;
		}

		// 19_1_2_ 值萃取
		{
			std::cout << "-----------------19_1_2_" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_2_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_2_::accum(name, name + lenght) / lenght << std::endl;

		}

		// 19_1_2_1411 值萃取
		{
			std::cout << "-----------------19_1_2_1411" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_2_1411_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_2_1411_::accum(name, name + lenght) / lenght << std::endl;
			_19_1_2_1411_::BigInt bigNum[] = { {1},{2},{3},{4},{5} };
			std::cout << "the average value of the BigInt in " << name << " is " << (_19_1_2_1411_::accum(bigNum, bigNum + 5) / 5).value << std::endl;
		}

		// _19_1_2_17_ 值萃取
		{
			std::cout << "-----------------_19_1_2_17_" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_2_17_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_2_17_::accum(name, name + lenght) / lenght << std::endl;
			_19_1_2_17_::BigInt bigNum[] = { {1},{2},{3},{4},{5} };
			std::cout << "the average value of the BigInt in " << name << " is " << (_19_1_2_17_::accum(bigNum, bigNum + 5) / 5).value << std::endl;
		}

		// _19_1_3_17_ 值萃取
		{
			std::cout << "-----------------_19_1_3_17_" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_3_17_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_3_17_::accum(name, name + lenght) / lenght << std::endl;
			_19_1_3_17_::BigInt bigNum[] = { {1},{2},{3},{4},{5} };
			std::cout << "the average value of the BigInt in " << name << " is " << (_19_1_3_17_::accum(bigNum, bigNum + 5) / 5).value << std::endl;
		}

		// _19_2_1_ 值萃取
		{
			std::cout << "-----------------_19_2_1_" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_2_1_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_2_1_::accum(name, name + lenght) / lenght << std::endl;
			_19_2_1_::BigInt bigNum[] = { {1},{2},{3},{4},{5} };
			std::cout << "the average value of the BigInt in " << name << " is " << (_19_2_1_::accum(bigNum, bigNum + 5) / 5).value << std::endl;
		}

		// _19_2_2_ 值萃取
		{
			std::cout << "-----------------_19_2_2_" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_2_2_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_2_2_::accum(name, name + lenght) / lenght << std::endl;
			_19_2_2_::BigInt bigNum[] = { {1},{2},{3},{4},{5} };
			std::cout << "the average value of the BigInt in " << name << " is " << (_19_2_2_::accum(bigNum, bigNum + 5) / 5).value << std::endl;
		}

		//_19_3_1_ 元素类型
		{
			std::cout << "-----------------_19_3_1_" << std::endl;
			std::vector<bool> s;
			_19_3_1_::printElementType(s);
			int arr[42];
			_19_3_1_::printElementType(arr);
		}

		// _19_3_2_1 删除引用
		{
			int a = 0;
			int& i = a;
			_19_3_2_1_::RemoveReference<int&> b = 0;
		}
		// _19_3_2_4_ 退化
		{
			using namespace _19_3_2_4_;
			printParameterType(&f<int>);
			printParameterType(&f<int const>);
			printParameterType(&f<int[7]>);
			printParameterType(&f<int(int)>);
			std::cout << "自定义decayT---------------------" << std::endl;
			printDecayedType<int>();
			printDecayedType<int const>();
			printDecayedType<int[7]>();
			printDecayedType<int(int)>();

		}
		// _19_3_3_1_ 预测型萃取
		{
			std::cout << "_19_3_3_1_........................" << std::endl;
			std::cout << " is int and int* same = " << _19_3_3_1_::isSameT<int, int*>::value << std::endl;
			std::cout << " is int and int same = " << _19_3_3_1_::isSame<int, int> << std::endl;
		}

		//_19_3_3_2_ true_type和false_type
		{
			FPrint print("_19_3_3_2_");
			std::cout << _19_3_3_2_::IsSameT<int, int>::value << std::endl;
			std::cout << _19_3_3_2_::IsSameT<int, int*>::value << std::endl;
			std::cout << _19_3_3_2_::IsSameV<int, int> << std::endl;
			std::cout << _19_3_3_2_::IsSameV<int, int*> << std::endl;
		}
		//_19_3_4_ 返回结果类型萃取
		{
			FPrint print("_19_3_4_");
			std::vector<char> v1{ 't','e','m','p','l','a','t','e' };
			std::vector<char> v2{ 't','e','m','p','l','a','t','e' };
			auto v3 = _19_3_4_::operator+(v1, v2);
			_19_3_1_::printElementType(v3);
		}
		////_19_3_4_2_ 返回结果类型萃取
		{
			FPrint print("_19_3_4_2_返回结果类型萃取");
			std::vector<char> v1{ 't','e','m','p','l','a','t','e' };
			std::vector<char> v2{ 't','e','m','p','l','a','t','e' };
			auto v3 = _19_3_4_2_::operator+(v1, v2);
			_19_3_1_::printElementType(v3);

		}
		// _19_4_1_用 SFINAE 排除某些重载函数
		{
			FPrint print("_19_4_1_用 SFINAE 排除某些重载函数");
			std::cout << _19_4_1_::IsDefaultConstructibleT<int>::value << std::endl;
			std::cout << _19_4_1_::IsDefaultConstructibleT<int&>::value << std::endl;
		}
		// _19_4_2_用 SFINAE 排除某些重载函数
		{
			FPrint print("_19_4_2_用 SFINAE 排除某些重载函数");
			std::cout << _19_4_2_::IsDefaultConstructibleT<int>::value << std::endl;
			std::cout << _19_4_2_::IsDefaultConstructibleT<int&>::value << std::endl;
		}
		////_19_4_3_ 将泛型 Lambdas 用于 SFINAE
		{
			FPrint print{ "_19_4_3_" };
			std::cout << _19_4_3_::isDefaultConstructible(_19_4_3_::type<int>) << std::endl;
			std::cout << _19_4_3_::isDefaultConstructible(_19_4_3_::type<int&>) << std::endl;
			std::cout << _19_4_3_::isDefaultConstructible(_19_4_3_::type<_19_4_3_::Test>) << std::endl;
			std::cout << "Has first Test: " << _19_4_3_::HasFirst(_19_4_3_::type<_19_4_3_::Test>) << std::endl;
			std::cout << "Has first int: " << _19_4_3_::HasFirst(_19_4_3_::type<int>) << std::endl;
		}

		// _19_5_1 IsConvertibleT 转换
		{
			FPrint print("_19_5_1 IsConvertibleT 转换");
			struct MyStruct {};

			std::cout << "MyStruct " << (_19_5_1_::isConvertible<MyStruct, int> ? "Can" : "Can't") << " convertible to int" << std::endl;
			std::cout << "int " << (_19_5_1_::isConvertible<int, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "double " << (_19_5_1_::isConvertible < double, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "std::string " << (_19_5_1_::isConvertible < std::string, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "int* " << (_19_5_1_::isConvertible < int*, int[]> ? "Can" : "Can't") << " convertible to int[] " << std::endl; // error 错误情况实际不能转换
			std::is_convertible<int, int>;
		}

		// _19_5_2_ IsConvertibleT 转换
		{
			FPrint print("_19_5_2_ IsConvertibleT 转换");
			struct MyStruct {};

			std::cout << "MyStruct " << (_19_5_2_::isConvertible<MyStruct, int> ? "Can" : "Can't") << " convertible to int" << std::endl;
			std::cout << "int " << (_19_5_2_::isConvertible<int, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "double " << (_19_5_2_::isConvertible < double, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "std::string " << (_19_5_2_::isConvertible < std::string, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "int* " << (_19_5_2_::isConvertible < int*, int[]> ? "Can" : "Can't") << " convertible to int[] " << std::endl; // error 错误情况实际不能转换
			std::is_convertible<int, int>;
		}
		// _19_6_1_ 探测类型成员
		{
			FPrint print("_19_6_1_ 探测类型成员");
			struct MyStruct
			{
				using size_type = std::size_t;
			};

			struct size_type
			{

			};

			struct Sizeable : size_type
			{

			};

			static_assert(_19_6_1_::HasSizeTypeT<Sizeable>::value, "Compiler bug: Injected class name missing");

			std::cout << _19_6_1_::HasSizeTypeT<int>::value << std::endl;
			std::cout << _19_6_1_::HasSizeTypeT<MyStruct>::value << std::endl;
			std::cout << _19_6_1_::HasSizeTypeT<MyStruct&>::value << std::endl;
		}
		//_19_6_2_ 探测任意类型成员
		{
			FPrint print("_19_6_2_ 探测任意类型成员");

			std::cout << "int::value_type: " << _19_6_2_::HasTypeT_value_type<int>::value << std::endl;
			std::cout << "int::char_type: " << _19_6_2_::HasTypeT_char_type<int>::value << std::endl;
			std::cout << "std::iostream::value_type: " << _19_6_2_::HasTypeT_value_type<std::iostream>::value << std::endl;
			std::cout << "std::iostream::char_type: " << _19_6_2_::HasTypeT_char_type<std::iostream>::value << std::endl;
			std::cout << "std::vector::value_type: " << _19_6_2_::HasTypeT_value_type<std::vector<int>>::value << std::endl;
			std::cout << "std::vector::char_type: " << _19_6_2_::HasTypeT_char_type<std::vector<int>>::value << std::endl;
		}
		//_19_6_3_ 探测非类型成员
		{
			FPrint print("_19_6_2_ 探测任意类型成员");
			std::vector<int> a{ 1,2,4 };
			std::cout << "int::size: " << _19_6_3_::HasMemberT_size<int>::value << std::endl;
			std::cout << "std::pair<int,int>::first: " << _19_6_3_::HasMemberT_first<std::pair<int, int>>::value << std::endl;
			std::cout << "std::vector<int>::size: " << _19_6_3_::HasMemberT_size<std::vector<int>>::value << std::endl;
			std::cout << "std::vector<int>::begin()" << _19_6_3_::HasMemberT_begin<std::vector<int>>::value << std::endl;

			std::cout << "string operator<()" << _19_6_3_::HasLessT<std::string, std::string>::value << std::endl;
			std::cout << "string operator<()" << _19_6_3_::HasLessT<std::string, int>::value << std::endl;
		}

		// 19_7_1_ if_then_else
		{
			FPrint print("19_7_1_ if_then_else");
			_19_7_1_::UnsignedT<int>::Type a = 1;
		}

		// 19_7_2_ 探测不抛出异常
		{
			FPrint print("19_7_2_ 探测不抛出异常");
			using namespace _19_7_2_;
			Pair a{ 1,2 };
			Pair b{ 1,E() };
			//decltype(b) d = std::move(b); // 失败
			std::pair c{ 1,2 };
		}

		// _19_8_1_ 判断基础类型
		{
			FPrint print{ "_19_8_1_ 判断基础类型" };
			_19_8_1_::Test(7);
			_19_8_1_::Test("hello");
		}
		// _19_8_2_ 判定复合类型
		{
			FPrint print("_19_8_2_ 判定复合类型");
			std::cout << "int is pointer ? " << _19_8_2_::IsPointerT<int>::value << std::endl;
			std::cout << "int* is pointer ? " << _19_8_2_::IsPointerT<int*>::value << std::endl;
			std::cout << "int is reference ? " << _19_8_2_::IsLValueReferenceT<int>::value << std::endl;
			std::cout << "int& is reference ? " << _19_8_2_::IsLValueReferenceT<int&>::value << std::endl;
			std::cout << "int is array ? " << _19_8_2_::IsArrayT<int>::value << std::endl;
			std::cout << "int[5] is array ? " << _19_8_2_::IsArrayT<int[5]>::value << " lenght = " << _19_8_2_::IsArrayT<int[5]>::size << std::endl;
			std::cout << "int[] is array ? " << _19_8_2_::IsArrayT<int[]>::value << " lenght = " << _19_8_2_::IsArrayT<int[]>::size << std::endl;

			struct A { int x; };

			int A::* pt = &A::x;

			std::cout << _19_8_2_::IsPointerToMemberT<A*>::value << std::endl;
			std::cout << _19_8_2_::IsPointerToMemberT<float  A::*>::value << std::endl;
			std::cout << _19_8_2_::IsPointerToMemberT<decltype(pt)>::value << std::endl;
		}

		// _19_8_3_ 识别函数类型
		{
			FPrint print("_19_8_3_ 识别函数类型");

			using namespace _19_8_3_;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<int(int, int)>::value << std::endl;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<int(int, int) const>::value << std::endl;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<int(int) volatile>::value << std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_function_v<int(int) volatile><< std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_function_v<int><< std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_const_v<int(int,int)><< std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_reference_v<int(int,int)><< std::endl;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<decltype(Test)>::value<< std::endl;

		}
	}
	return 0;
}