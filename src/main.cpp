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

    
    template<typename RT = long, typename T1,typename T2>
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
                 os << s.elems[i] << ";" ;
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
    template<typename T1,typename T2>
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

    template<typename T1,typename T2>
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

    template<typename T,typename Cont>
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

    }

    template<typename T,std::size_t Maxsize>
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
    template<int Val,typename T>
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
    public :
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

    template<typename T,auto Maxsize>
    Stack<T,Maxsize>::Stack()
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
        (std::cout<< ... << AddSpace<Types>(args)) << std::endl;
    }

    template<typename ...Types>
    void printDoubled(Types const& ... args)
    {
        print(args + args...);
    }

    template<typename T1,typename... TN>
    constexpr bool isHomogeneous(T1, TN...)
    {
        return (std::is_same<T1, TN>::value && ...);
    }

    template<typename C, typename... Idx>
    void printElems(C const& coll, Idx... idx)
    {
        print(coll[idx]...);
    }

    template<std::size_t... Idx,typename C>
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
        Customer(std::string const& n) : name(n){}
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
            B(){}
            ~B(){}

        private:

        };
    public:
        A(){}
        ~A(){}

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
    template<typename T,int N,int M>
    bool less(T(&a)[N], T(&b)[M])
    {
        for (int i = 0; i < N && i < M; i++)
        {
            if (a[i]<b[i])
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

    template<int N,int M>
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

    template<typename T,std::size_t SZ>
    struct MyClass<T[SZ]>
    {
        static void print() 
        { 
            std::cout << "print() for T[" << SZ << "]\n"; 
        }
    };

    template<typename T,std::size_t SZ>
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


    template<typename T1,typename T2,typename T3>
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

        template<typename T2,typename Cont2>
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
    Stack<T,Cont>& Stack<T, Cont>::operator=(Stack<T1, Cont1> const& op1)
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
        template<typename T1,typename T2>
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
    template<typename T,template<typename Elem, typename _Alloc = std::allocator<Elem>> typename Cont = std::deque>
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

    template<typename T,typename... Types>
    std::shared_ptr<T> Create(Types... args)
    {
        return std::make_shared<T>(args...);;
   }
    const auto& test1()
    {
        const Base b;
        return b;
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
        template<typename STR,typename = EnableIfString<STR> /*std::enable_if_t<std::is_convertible_v<STR,std::string>>*/>
        explicit Person(STR&& n) :name(std::forward<STR>(n))
        {
            std::cout << "TMPL-CONSTR for '" << name << "'\n";
        }

        template<typename T,std::enable_if_t<std::is_convertible_v<T, Person>> >
            Person(T&& p) :name(p.name)
        {
            std::cout << "TMPL-Copy Person for '" << name << "'\n";
        }

        Person(Person const& p) : name(p.name)
        {
            std::cout << "COPY-CONSTR Person'" << name << "'\n";
        }

        Person(Person&& p) : name(std::move(p.name))
        {
            std::cout << "Move-CONSTR Person'"<< name << "'\n";
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

int main(  )
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
            Person p3( p1 );
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
        }
    }
    

    return 0;
}