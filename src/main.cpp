
#include "head.h"
//#include <utility>

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


	//-------------------------------------------������---------------------------------------------------------
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

			// ������warning
			fStack = iStack;
			std::cout << "fStack.top():" << fStack.top() << std::endl;
		}
	}

	{


		std::shared_ptr<TestSharedPtr::Base> a = TestSharedPtr::Create<TestSharedPtr::Base>();

		std::cout << "���ܶ���a = " << &a << std::endl;
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
			_7_1_::printV(s); // ������һ��lvalue�����ʹ��std::string��copy constructor��
			_7_1_::printV(std::string("hi")); //���ﴫ�ݵ���prvalue(���ֽ�������ʱ������ߺ������ص���ʱ����)��ͨ��״���±���������в������ݵ��Ż���������ʹcopy constructor 
			_7_1_::printV(returnString());//���ﴫ�ݵ���prvalue(���ֽ�������ʱ������ߺ������ص���ʱ����)��ͨ��״���±���������в������ݵ��Ż���������ʹcopy constructor 
			_7_1_::printV(std::move(s));//���ݵ���xvalue(һ��ʹ�ù�std::move��Ķ���)��������move constructor��
			//��Ȼ����4��״��ֻ�е�һ�ֲŻ����copy constructor����������״�����������ġ�
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
					//_7_3_0_::printString(std::move(s));error ��������ʱ����(prvalue)����ͨ��std::move()��������Ѵ��ڵ�(xvalue)�����������
					std::cout << sizeof(_7_3_0_::Date) << ":" << sizeof(unsigned int) << std::endl;
				}
			}

			// ������ͨ�����ݲ����ĵ�ַʵ�ֵġ� �����������˻���
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
			std::cout << "ģ��Ԫ���:" << _8_1_1_::IsPrime<11>::value << std::endl;
			std::cout << "ģ��Ԫ��� helper:" << _8_1_1_::Helper<11>::value << std::endl;
			std::cout << "ģ��Ԫ���:" << _8_1_1_::IsPrime<10>::value << std::endl;
			std::cout << "ģ��Ԫ��� helper:" << _8_1_1_::Helper<10>::value << std::endl;
			{
				unsigned a = 10;
				constexpr bool isprime1 = _8_2_1_::IsPrime(11);
				std::cout << "constexpr:" << isprime1 << std::endl; //������
				std::cout << "constexpr:" << _8_2_1_::IsPrime(11) << std::endl; //������
				std::cout << "constexpr helper:" << _8_2_1_::Helper<11>::value << std::endl; //������
				std::cout << "constexpr:" << _8_2_1_::IsPrime(a) << std::endl; // ������
				std::cout << "constexpr helper:" << _8_2_1_::Helper<10>::value << std::endl;

				std::cout << "_8_2_1_::constexpr b1:" << _8_2_1_::b1 << std::endl;
				std::cout << "_8_2_1_::constexpr fiftySevenIsPrime:" << _8_2_1_::fiftySevenIsPrime() << std::endl;
			}
			{
				unsigned a = 10;
				constexpr bool isprime1 = _8_2_2_::isPrime(11);//������
				bool isprime2 = _8_2_2_::isPrime(a);
				std::cout << "_8_2_2_constexpr:" << isprime1 << std::endl; //������
				std::cout << "_8_2_2_constexpr:" << _8_2_2_::isPrime(11) << std::endl; //������
				std::cout << "_8_2_2_constexpr:" << isprime2 << std::endl; // ������
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
			// ����
			int a[10];
			std::cout << "_8_4_0_ no size():" << _8_4_0_::len(a) << std::endl;
			std::cout << "_8_4_0_ no size():" << _8_4_0_::len("tmp") << std::endl;
			// �������ݽṹ
			std::vector<int> v;
			v.push_back(1);
			std::cout << "_8_4_0_ has size():" << _8_4_0_::len(v) << std::endl;
			// ָ��
			int* p = new int(0);
			std::cout << "_8_4_0_ has point:" << _8_4_0_::len(p) << std::endl;
			// allocator û��ƥ����
			std::allocator<int> x;
			//std::cout << "_8_4_0_ allocator:" << _8_4_0_::len(x) << std::endl;
		}
		//4.1
		{
			// ����
			int a[10];
			std::cout << "_8_4_1_ no size():" << _8_4_1_::len(a) << std::endl;
			std::cout << "_8_4_1_ no size():" << _8_4_1_::len("tmp") << std::endl;
			// �������ݽṹ
			std::vector<int> v;
			v.push_back(1);
			std::cout << "_8_4_1_ has size():" << _8_4_1_::len(v) << std::endl;
			// ָ��
			int* p = new int(0);
			std::cout << "_8_4_1_ has point:" << _8_4_1_::len(p) << std::endl;
			// allocator û��ƥ����
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
				std::cout << "�����" << a << ":" << i << std::endl;
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
		// ���M�Ʋ���
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
			std::cout << "�Ӹ�λ���λ����" << index << std::endl;
			uint32_t index1;
			_BitScanForward((unsigned long*)&index1, a);
			std::cout << "�ӵ�λ���λ����" << index1 << std::endl;
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

			//RefMem<int&> rm3; // ��Ҫ��ֵ
			//RefMem<int&, 0>rm4; // ���ܴ�int ת����int&

			//Arr<int&, size> x;// error ���������vector;
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
		FPrint print("��18��");
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
	{
		FPrint print("��19��");
		// 19_1_1_
		{
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_1_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_1_::accum(name, name + lenght) / lenght << std::endl;
		}

		// 19_1_2_ ֵ��ȡ
		{
			std::cout << "-----------------19_1_2_" << std::endl;
			int num[] = { 1,2,3,4,5 };
			std::cout << "the average value of the integer values is " << _19_1_2_::accum(num, num + 5) / 5 << std::endl;
			char name[] = "template";
			int lenght = sizeof(name) - 1;
			std::cout << "the average value of the char in " << name << " is " << _19_1_2_::accum(name, name + lenght) / lenght << std::endl;

		}

		// 19_1_2_1411 ֵ��ȡ
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

		// _19_1_2_17_ ֵ��ȡ
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

		// _19_1_3_17_ ֵ��ȡ
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

		// _19_2_1_ ֵ��ȡ
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

		// _19_2_2_ ֵ��ȡ
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

		//_19_3_1_ Ԫ������
		{
			std::cout << "-----------------_19_3_1_" << std::endl;
			std::vector<bool> s;
			_19_3_1_::printElementType(s);
			int arr[42];
			_19_3_1_::printElementType(arr);
		}

		// _19_3_2_1 ɾ������
		{
			int a = 0;
			int& i = a;
			_19_3_2_1_::RemoveReference<int&> b = 0;
		}
		// _19_3_2_4_ �˻�
		{
			using namespace _19_3_2_4_;
			printParameterType(&f<int>);
			printParameterType(&f<int const>);
			printParameterType(&f<int[7]>);
			printParameterType(&f<int(int)>);
			std::cout << "�Զ���decayT---------------------" << std::endl;
			printDecayedType<int>();
			printDecayedType<int const>();
			printDecayedType<int[7]>();
			printDecayedType<int(int)>();

		}
		// _19_3_3_1_ Ԥ������ȡ
		{
			std::cout << "_19_3_3_1_........................" << std::endl;
			std::cout << " is int and int* same = " << _19_3_3_1_::isSameT<int, int*>::value << std::endl;
			std::cout << " is int and int same = " << _19_3_3_1_::isSame<int, int> << std::endl;
		}

		//_19_3_3_2_ true_type��false_type
		{
			FPrint print("_19_3_3_2_");
			std::cout << _19_3_3_2_::IsSameT<int, int>::value << std::endl;
			std::cout << _19_3_3_2_::IsSameT<int, int*>::value << std::endl;
			std::cout << _19_3_3_2_::IsSameV<int, int> << std::endl;
			std::cout << _19_3_3_2_::IsSameV<int, int*> << std::endl;
		}
		//_19_3_4_ ���ؽ��������ȡ
		{
			FPrint print("_19_3_4_");
			std::vector<char> v1{ 't','e','m','p','l','a','t','e' };
			std::vector<char> v2{ 't','e','m','p','l','a','t','e' };
			auto v3 = _19_3_4_::operator+(v1, v2);
			_19_3_1_::printElementType(v3);
		}
		////_19_3_4_2_ ���ؽ��������ȡ
		{
			FPrint print("_19_3_4_2_���ؽ��������ȡ");
			std::vector<char> v1{ 't','e','m','p','l','a','t','e' };
			std::vector<char> v2{ 't','e','m','p','l','a','t','e' };
			auto v3 = _19_3_4_2_::operator+(v1, v2);
			_19_3_1_::printElementType(v3);

		}
		// _19_4_1_�� SFINAE �ų�ĳЩ���غ���
		{
			FPrint print("_19_4_1_�� SFINAE �ų�ĳЩ���غ���");
			std::cout << _19_4_1_::IsDefaultConstructibleT<int>::value << std::endl;
			std::cout << _19_4_1_::IsDefaultConstructibleT<int&>::value << std::endl;
			std::cout << _19_4_1_::IsDefaultConstructibleT1<int>::value << std::endl;
			std::cout << _19_4_1_::IsDefaultConstructibleT1<int&>::value << std::endl;
		}
		// _19_4_2_�� SFINAE �ų�ĳЩ���غ���
		{
			FPrint print("_19_4_2_�� SFINAE �ų�ĳЩ���غ���");
			std::cout << _19_4_2_::IsDefaultConstructibleT<int>::value << std::endl;
			std::cout << _19_4_2_::IsDefaultConstructibleT<int&>::value << std::endl;
		}
		////_19_4_3_ ������ Lambdas ���� SFINAE
		{
			FPrint print{ "_19_4_3_" };
			std::cout << _19_4_3_::isDefaultConstructible(_19_4_3_::type<int>) << std::endl;
			std::cout << _19_4_3_::isDefaultConstructible(_19_4_3_::type<int&>) << std::endl;
			std::cout << _19_4_3_::isDefaultConstructible(_19_4_3_::type<_19_4_3_::Test>) << std::endl;
			std::cout << "Has first Test: " << _19_4_3_::HasFirst(_19_4_3_::type<_19_4_3_::Test>) << std::endl;
			std::cout << "Has first int: " << _19_4_3_::HasFirst(_19_4_3_::type<int>) << std::endl;
		}

		////_19_4_4_ ������ Lambdas ���� SFINAE
		{
			FPrint print{ "_19_4_4_" };
			using namespace _19_4_4_;
			std::vector a{ 1,2,3,4,5 };
			std::vector b{ 1,2,3,4,5 };
			std::vector c = _19_4_4_::operator+(a, b);
			for (int i = 0; i < c.size(); i++)
			{
				std::cout << "c[" << i << "] = " << c[i] << std::endl;
			}


			std::vector a1{ A(),A(),A(),A(),A() };
			std::vector b1{ B(),B(),B(),B(),B() };

			std::vector c1 = _19_4_4_::operator+(a1, b1);
		}

		// _19_5_1 IsConvertibleT ת��
		{
			FPrint print("_19_5_1 IsConvertibleT ת��");
			struct MyStruct {};

			std::cout << "MyStruct " << (_19_5_1_::isConvertible<MyStruct, int> ? "Can" : "Can't") << " convertible to int" << std::endl;
			std::cout << "int " << (_19_5_1_::isConvertible<int, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "double " << (_19_5_1_::isConvertible < double, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "std::string " << (_19_5_1_::isConvertible < std::string, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "int* " << (_19_5_1_::isConvertible < int*, int[]> ? "Can" : "Can't") << " convertible to int[] " << std::endl; // error �������ʵ�ʲ���ת��
			std::is_convertible<int, int>;
		}

		// _19_5_2_ IsConvertibleT ת��
		{
			FPrint print("_19_5_2_ IsConvertibleT ת��");
			struct MyStruct {};

			std::cout << "MyStruct " << (_19_5_2_::isConvertible<MyStruct, int> ? "Can" : "Can't") << " convertible to int" << std::endl;
			std::cout << "int " << (_19_5_2_::isConvertible<int, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "double " << (_19_5_2_::isConvertible < double, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "std::string " << (_19_5_2_::isConvertible < std::string, int> ? "Can" : "Can't") << " convertible to int " << std::endl;
			std::cout << "int* " << (_19_5_2_::isConvertible < int*, int[]> ? "Can" : "Can't") << " convertible to int[] " << std::endl; // error �������ʵ�ʲ���ת��
			std::is_convertible<int, int>;
		}
		// _19_6_1_ ̽�����ͳ�Ա
		{
			FPrint print("_19_6_1_ ̽�����ͳ�Ա");
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
		//_19_6_2_ ̽���������ͳ�Ա
		{
			FPrint print("_19_6_2_ ̽���������ͳ�Ա");

			std::cout << "int::value_type: " << _19_6_2_::HasTypeT_value_type<int>::value << std::endl;
			std::cout << "int::char_type: " << _19_6_2_::HasTypeT_char_type<int>::value << std::endl;
			std::cout << "std::iostream::value_type: " << _19_6_2_::HasTypeT_value_type<std::iostream>::value << std::endl;
			std::cout << "std::iostream::char_type: " << _19_6_2_::HasTypeT_char_type<std::iostream>::value << std::endl;
			std::cout << "std::vector::value_type: " << _19_6_2_::HasTypeT_value_type<std::vector<int>>::value << std::endl;
			std::cout << "std::vector::char_type: " << _19_6_2_::HasTypeT_char_type<std::vector<int>>::value << std::endl;
		}
		//_19_6_3_ ̽������ͳ�Ա
		{
			FPrint print("_19_6_2_ ̽���������ͳ�Ա");
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

		// 19_7_2_ ̽�ⲻ�׳��쳣
		{
			FPrint print("19_7_2_ ̽�ⲻ�׳��쳣");
			using namespace _19_7_2_;
			Pair a{ 1,2 };
			Pair b{ 1,E() };
			//decltype(b) d = std::move(b); // ʧ��
			std::pair c{ 1,2 };
		}

		// _19_8_1_ �жϻ�������
		{
			FPrint print{ "_19_8_1_ �жϻ�������" };
			_19_8_1_::Test(7);
			_19_8_1_::Test("hello");
		}
		// _19_8_2_ �ж���������
		{
			FPrint print("_19_8_2_ �ж���������");
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

		// _19_8_3_ ʶ��������
		{
			FPrint print("_19_8_3_ ʶ��������");

			using namespace _19_8_3_;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<int(int, int)>::value << std::endl;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<int(int, int) const>::value << std::endl;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<int(int) volatile>::value << std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_function_v<int(int) volatile> << std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_function_v<int> << std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_const_v<int(int, int)> << std::endl;
			std::cout << "int Test(int i) is function ? " << std::is_reference_v<int(int, int)> << std::endl;
			std::cout << "int Test(int i) is function ? " << IsFunctionT<decltype(Test)>::value << std::endl;


		}

		// _19_8_4_ �ж�class����
		{
			FPrint print("_19_8_4_ �ж�class����");
			struct Test {};
			enum ETest
			{

			};

			enum class MyEnumClass
			{

			};
			std::cout << "int is class ? " << std::is_class_v<int> << std::endl;
			std::cout << "int is class ? " << _19_8_4_::IsClass_v<int> << std::endl;
			std::cout << "Test is class ? " << std::is_class_v<Test> << std::endl;
			std::cout << "Test is class ? " << _19_8_4_::IsClass_v<Test> << std::endl;
			std::cout << "ETest is class ? " << std::is_class_v<ETest> << std::endl;
			std::cout << "ETest is class ? " << _19_8_4_::IsClass_v<ETest> << std::endl;
			std::cout << "uint16_t is class ? " << std::is_class_v<uint16_t> << std::endl;
			std::cout << "uint16_t is class ? " << _19_8_4_::IsClass_v<uint16_t> << std::endl;
			std::cout << "MyEnumClass is class ? " << std::is_class_v<MyEnumClass> << std::endl;
			std::cout << "MyEnumClass is class ? " << _19_8_4_::IsClass_v<MyEnumClass> << std::endl;
		}

		// _19_8_5_ ʶ��ö������
		{
			FPrint print("_19_8_5_ ʶ��ö������");
			struct Test {};
			enum ETest {};
			enum class MyEnumClass {};

			std::cout << "is Test enum ? " << std::is_enum_v<Test> << std::endl;
			std::cout << "is ETest enum ? " << std::is_enum_v<ETest> << std::endl;
			std::cout << "is MyEnumClass enum ? " << std::is_enum_v<MyEnumClass> << std::endl;
			std::cout << "is int enum ? " << std::is_enum_v<int> << std::endl;

		}

	}
	
{
}
	{
	FPrint print("����֮��");
		auto func = [](std::vector<int>& nums) ->bool
	{
		std::unordered_set<int> mpa;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (mpa.find(nums[i])!=mpa.end())
			{
				return true;
			}
			mpa.insert(nums[i]);
		}
		return false;
	};
		std::vector nums{ 1,2,3,1 };
		std::cout<< func(nums)<<std::endl;
		std::vector nums1{ 1,2,3,4 };
		std::cout << func(nums1) << std::endl;
		
		std::sort(nums.begin(), nums.end());

		using namespace std;
		auto func1 = [](vector<int>& nums, int target) ->vector<int>
		{
			std::map<int, int> map;
			for (int i = 0; i < nums.size(); i++)
			{
				auto other = map.find(target - nums[i]);
				if (other != map.end())
				{
					return { other->second, i};
				}
				map[nums[i]] = i;
			}
			return {};
		};
		std::vector nums2{ 3,2,4 };
		int target = 6;
		func1(nums2, target);
	}

	{
		FPrint print("�������");
		struct ListNode 
		{
			int val;
			ListNode* next;
			ListNode() : val(0), next(nullptr) {}
			ListNode(int x) : val(x), next(nullptr) {}
			ListNode(int x, ListNode* next) : val(x), next(next) {}
		};
		ListNode* tl1 = new ListNode(2);
		ListNode* tl1_1 = new ListNode(4);
		ListNode* tl1_2 = new ListNode(3);
		tl1->next = tl1_1;
		tl1_1->next = tl1_2;

		ListNode* tl2 = new ListNode(5);
		ListNode* tl2_1 = new ListNode(6);
		ListNode* tl2_2 = new ListNode(4);
		tl2->next = tl2_1;
		tl2_1->next = tl2_2;

		
		ListNode* head = nullptr, * tail = nullptr;
		int carry = 0;
		while (tl1 || tl2)
		{
			int num1 = tl1 ? tl1->val : 0;
			int num2 = tl2 ? tl2->val : 0;
			int sum = num1 + num2 + carry;
			if (!head) {
				head = tail = new ListNode(sum % 10);
			}
			else {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			carry = sum / 10;
			if (tl1)
			{
				tl1 = tl1->next;
			}
			if (tl2)
			{
				tl2 = tl2->next;
			}
		}
		if (carry)
		{
			tail->next = new ListNode(carry);
		}
	}
	{
		//���ظ��ַ�����Ӵ�
		FPrint print("���ظ��ַ�����Ӵ�");
		std::string s = "aab";
		std::string max = "";
		std::string cur = "";
		int index = 0;
		for (size_t i = 0; i < s.size(); )
		{
			char c = s[i];
			std::string tmp;
			tmp.push_back(c);
			std::cout << tmp << ' ';
			if (cur.find(tmp) == std::string::npos)
			{
				cur.push_back(s[i]);
				i++;
			}
			else
			{
				if (cur.size() > max.size())
				{
					max = cur;
				}
				i = index + 1;
				index++;
				cur = "";
				std::cout << std::endl;
			}
		}
		if (cur.size() > max.size())
		{
			max = cur;
		}
		
		std::cout << "max = " << max << " size = " << max.size() << std::endl;

		auto findMaxStrfunc = [](std::string s)->std::string
		{
			std::string Max = ""; 
			int maxStr = 0;
			std::unordered_set<char> lookup;
			int left = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				while (lookup.find(s[i]) != lookup.end())
				{
					lookup.erase(s[left]);
					left++;
				}

				maxStr = maxStr > i - left + 1 ? maxStr : i - left + 1;
				lookup.insert(s[i]);
			}
			for (const char& character : lookup)
				Max += character;
			return Max;
		};

		std::string maxss = findMaxStrfunc(s);

		std::cout << maxss << maxss.size() << std::endl;
	}
	{
		FPrint print("�����ڴ�ռ��");
		using std::cout;
		using std::endl;
		struct A
		{
			int x : 20;
			int y : 10;
			int z : 2;
			int m : 1;

			void* operator new(size_t size)
			{
				void* a = malloc(size);
				return a;
			}

			void* operator new[](size_t size)
			{
				void* a = malloc(size);
				return a;
			}

			void operator delete(void* p, void*)
			{
				cout << "operator delete(void* p, void*), p = " << p << " size = " << sizeof(p) << endl;
				free(p);
			}

			void  operator delete[](void* p, size_t size)
			{
				cout << "operator delete(), p = " << p << " size = " << size << endl;
				free(p);
			}
		};

		std::cout << sizeof(A)<<std::endl;

		A* buf = (A*)(new A[10]);
		//A* buf = new A();

		char* temp = reinterpret_cast<char*>(buf);

		delete[] buf;
	}

	// _20_1_.........
	{
		FPrint print("��20��");
		{
			// 20_1 �㷨�ػ�
			FPrint print("��20�µ�һ��");
			int a = 1;
			int b = 2;
			_20_1_::swap(a, b);
			std::cout << "a = " << a << " " << "b = " << b << std::endl;

			std::vector<int> va = { 1,2,3 };
			std::vector<int> vb = { 5,6,7 };
			_20_1_::swap(va, vb);
			for (size_t i = 0; i < va.size(); i++)
			{
				std::cout << "�����������Ϊ��" << va[i] << std::endl;
			}
			std::vector<int>::iterator itera = va.begin();
			auto iterb = vb.begin();
			_20_1_::advanceIter(itera, 2);
			std::advance(iterb, 2);
			std::cout << *itera << " " << *iterb << std::endl;
		}
		{

			FPrint print("��20�µ�һ�� ����ɷ���Tag Dispatching��");
			std::vector<int> va = { 1,2,3 };
			std::list<int> la = { 1,2,3 };

			auto iva = va.begin();
			auto ila = la.begin();
			_20_2_::advanceIter(iva, 2);
			_20_2_::advanceIter(ila, 2);
			std::cout << *iva << " " << *ila << std::endl;
		}

		{

FPrint print("��20�� Enable/disable����ģ��");
std::vector<int> va = { 1,2,3 };
std::list<int> la = { 1,2,3 };

auto iva = va.begin();
auto ila = la.begin();
_20_3_::advanceIter(iva, 2);
_20_3_::advanceIter(ila, 2);
std::cout << *iva << " " << *ila << std::endl;
		}

		{

		FPrint print("��20�� �ṩ�����ػ��汾");
		std::vector<int> va = { 1,2,3 };
		std::list<int> la = { 1,2,3 };

		auto iva = va.begin();
		auto ila = la.begin();
		_20_3_1_::advanceIter(iva, 2);
		_20_3_1_::advanceIter(ila, 2);
		std::cout << *iva << " " << *ila << std::endl;
		}

		{

			FPrint print("��20�� ������ if");
			std::vector<int> va = { 1,2,3 };
			std::list<int> la = { 1,2,3 };

			auto iva = va.begin();
			auto ila = la.begin();
			_20_3_3_::advanceIter(iva, 2);
			_20_3_3_::advanceIter(ila, 2);
			std::cout << *iva << " " << *ila << std::endl;
		}

		{

			FPrint print("��20�� Concepts");
			std::vector<int> va = { 1,2,3 };
			std::list<int> la = { 1,2,3 };

			auto iva = va.begin();
			auto ila = la.begin();
			_20_3_4_::advanceIter(iva, 2);
			_20_3_4_::advanceIter(ila, 2);
			std::cout << *iva << " " << *ila << std::endl;
		}

		{
			FPrint print("��20�� ����/������ģ��");

			struct MyStruct
			{
				MyStruct() : x(0) {}
				MyStruct(int tx) : x(tx) {}

				/*bool operator<(const MyStruct& other)
				{
					return x < other.x;
				}*/
				int x = 0;
			};
			using namespace _20_4_1_;
			_20_4_1_::Dictionnary<int, int> a;
			_20_4_1_::Dictionnary<MyStruct, int> b;
			std::cout << "MyStruct Has less ? " << _20_4_1_::HasLessT<MyStruct, MyStruct>::value << std::endl;
		}

		{

			FPrint print("��20�� ��ģ��ı���ɷ�");
			std::vector<int> va = { 1,2,3 };
			std::list<int> la = { 1,2,3 };

			auto iva = va.begin();
			auto ila = la.begin();

			_20_4_2_::advanceIter(iva, 2);
			_20_4_2_::advanceIter(ila, 2);

			std::cout << *iva << " " << *ila << std::endl;
		}

		{
			FPrint print("��20�� ʵ������ȫ��ģ��");
			using namespace _20_5_;
			min(X1(), X1());
			min(X2(), X2());
			//min(X3(), X3()); // error δ�ҵ�ƥ������غ���
			//min(X4(), X4());// error δ�ҵ�ƥ������غ���
			min(X5(), X5()); // error δ�ҵ�ƥ������غ���
			//min(X6(), X6());// error δ�ҵ�ƥ������غ���
			//min(X7(), X7());// error δ�ҵ�ƥ������غ���
		}
	}

	// ��21��
	{}
	{
		FPrint PrintT("��21��");
		{
			using namespace _21_1_1_1_;
			FPrint print("��21�� ����ԭ��(1)");
			std::cout << "sizeof(Empty)" << sizeof(Empty) << std::endl;
			std::cout << "sizeof(EmptyToo)" << sizeof(EmptyToo) << std::endl;
			std::cout << "sizeof(EmptyThree)" << sizeof(EmptyThree) << std::endl;
		}

		{
			using namespace _21_1_1_2_;
			FPrint print("��21�� ����ԭ��(2)");
			std::cout << "sizeof(Empty)" << sizeof(Empty) << std::endl;
			std::cout << "sizeof(EmptyToo)" << sizeof(EmptyToo) << std::endl;
			std::cout << "sizeof(NonEmpty)" << sizeof(NonEmpty) << std::endl;
		}
		{
			FPrint print("��21�� Facades");
			using namespace _21_2_3_;
			std::vector<Person> authors = { 
				{"David", "Vandevoorde"}, 
				{"Nicolai", "Josuttis"}, 
				{"Douglas", "Gregor"}
			}; 
			std::copy(project(authors.begin(), &Person::lastName),
				project(authors.end(), &Person::lastName),
				std::ostream_iterator<std::string>(std::cout, "\n"));

			std::vector<Person> copyPersons;

		}

		{
			using namespace _21_2_2_1_;
			FPrint print("��21�� CRTP");

			FTest<int> t;
			{
				FTest<int> t1 = t;
				std::cout << "t1 live(): " << t1.live() << std::endl;
			}
			std::cout <<"t1 live(): " << t.live() << std::endl;
			
		}
		{
			using namespace _21_2_3_;
			std::vector<Person> authors = {
				{"David", "Vandevoorde"},
				{"Nicolai", "Josuttis"},
				{"Douglas", "Gregor"}
			};
			std::vector<int> a{ 1,2,3 };
			auto aBeg = authors.begin();
			auto aEnd = authors.end();
			auto tmp = aEnd - aBeg;
			std::cout << "tmp = " << tmp << std::endl;

			Person aa[] = { {"David", "Vandevoorde"},
				{"Nicolai", "Josuttis"} };
			Person* bb = aa;
		
			 
			int cc = (&bb[1] - &bb[0]);

			std::cout << "cc = " << cc << std::endl;

		}

		{
			using namespace _21_3_1_4_;

			FPrint print("��21�� Curious Mixins");
			Point<Color> ColorPoint{ 4,2 };
			Point<Color, Label> ColorAndLabelPoint{ 1,3 };

			std::cout <<"ColorPoint : " << ColorPoint.x << " : " << ColorPoint.y << std::endl;
			std::cout <<"ColorAndLabelPoint : " << ColorAndLabelPoint.x << " : " << ColorAndLabelPoint.y << std::endl;
		}
		{
			using namespace _21_3_2_;
			FPrint print("��21�� �����ԵĲ�����");

			Base<NotVirtual>* p1 = new Base<NotVirtual>;
			p1->foo();

			Base<Virtual>* p2 = new Derived<Virtual>();
			p2->foo();
		}

		{
			FPrint print("��21�� ������ģ�����");
			using namespace _21_4_;
			BreadSlicer<> bc1;
			bc1.print();

			BreadSlicer<Policy3_is<CustomPolicy> > bc2;
			bc2.print();
		}
	}



	// ��22��
	{}
	{
		FPrint PrintT("��22��");
		{
			FPrint Print("��22�� ��������");
			using namespace _22_1_1_;
			std::vector<int> values;

			forUpTo(5, [&values](int i) {
				values.push_back(i);
				});

			forUpTo(5, printInt);
			std::cout << std::endl;
		}

		{
			FPrint Print("��22�� std:function<>");
			using namespace _22_1_2_;
			std::vector<int> values;

			forUpTo(5, [&values](int i) {
				values.push_back(i);
				});

			forUpTo(5, printInt);
			std::cout << std::endl;
		}

		{
			FPrint Print("��22�� ָ��");
			using namespace _22_1_3_;
			std::vector<int> values{ 1,2,3,4,5 };

			/*auto func = [&values](int i) {
				values.push_back(i);
			};

			forUpTo(5, &func); error*/

			forUpTo(5, printInt);
			std::cout << std::endl;
		}

		{
			FPrint Print("��22�� �Զ���Function");
			using namespace _22_2_;
			std::vector<int> values;

			auto func = [&values](int i) {
				values.push_back(i);
			};

			forUpTo(5, func);

			FunctionPtr<void(int)> f1 = func;
			FunctionPtr<void(int)> f2 = func;
			std::cout << "f1 == f2 " << (f1==f2) << std::endl;

			forUpTo(5, printInt);
			std::cout << std::endl;
		}
	}

	// ��23��
	{}
	{
		FPrint printt("��23��");
		{
			FPrint print("ֵԪ���");
			std::cout << _23_1_1_::sqrt(17) << std::endl;
		}
		{
			FPrint print("����Ԫ���");
			using namespace _23_1_2_;
			std::cout << typeid(RemoveAllExtents<int[]>).name() << std::endl;
			std::cout << typeid(RemoveAllExtents<int[5][10]>).name() << std::endl;
			std::cout << typeid(RemoveAllExtents<int[][10]>).name() << std::endl;
			std::cout << typeid(RemoveAllExtents<int(*)[]>).name() << std::endl;
		}
		{
			FPrint print("���Ԫ��� _23_1_3_1_");
			std::array<int,4> ia{ 1,2,3,4 };
			std::array<int, 4> ib{ 10,10,10,10 };
			std::cout << "_23_1_3_1_ ia dot ib = " << _23_1_3_1_::dotProduct(ia, ib) << std::endl;
		}
		{
			FPrint print("���Ԫ��� _23_1_3_2_");
			std::array<int, 4> ia{ 1,2,3,4 };
			std::array<int, 4> ib{ 10,10,10,10 };
			// һ�´���vs2019����
#if 0
			std::cout << "vs2019 ���g��bug" << std::endl;
#else
			int result1 = _23_1_3_2_::dotProduct(ia, ib);
			std::cout << "_23_1_3_2_ ia dot ib = " << result1 << std::endl;
#endif // HAS_CPP_14

		}
		{
			FPrint print("�����Ԫ������ڡ���λ���͡� _23_1_4_");
			using namespace _23_1_4_;

			int x = 1;
			int y = 10;
			auto a = Duration<int, Ratio<1, 1000>>(x);
			auto b = Duration<int, Ratio<1, 60000>>(y);
			auto c = a + b;
			std::cout << "c = " << c.value() << std::endl; 

		}
		{
			FPrint print("����Ԫ��̵�ά�� _23_2_");
			using namespace _23_2_;
			std::cout << Sqrt<100>::value << std::endl;
		}

		{
			FPrint print("׷�����е�ʵ�������� _23_3_");
			using namespace _23_3_1_;
			std::cout << Sqrt<100>::value << std::endl;
		}
		{
			FPrint print("ö��ֵ���Ǿ�̬���� _23_6_");
			using namespace _23_4_;
			std::cout << PowM<2,3>::value << std::endl;
			std::cout << Pow<3,3> << std::endl;
			std::cout << Pow<3,3> << std::endl;
		}

	}
	{
		FPrint printT("��24�� TypeList");
		using TestType = _24_::TypeList<short, int, long, signed char, long long>;
		using TestType1 = _24_::FrontPush<_24_::FrontPop<TestType>,bool>;
		using TestType2 = _24_::NthElement<TestType1, 4>; 
		using LargestType = _24_::LargestType<TestType>;
		using PushBack_OldType = _24_::PushBack_Old<TestType, bool>;
		using PushBackType = _24_::PushBack<TestType, bool>;
		using NullType = _24_::TypeList<>;
		using PushBack_OldType2 = _24_::PushBack_Old<NullType, bool>;
		using ReverseType = _24_::Reverse<TestType>;
		using TranformType = _24_::Transform<TestType>;
		using ResultType = _24_::Accumulate<TestType, _24_::FrontPushT, NullType>;
		using LargestType_New = _24_::LargestTypeAcc<TestType>;
		using ST = _24_::InsertionSort<TestType, _24_::SmallerThanT>;
		int ResultPrimes = _24_::Accumulate<_24_3_1_::Primes, _24_3_1_::MultiplyT, _24_3_1_::CTValue<int, 1>>::value;
		int ResultCTPrimes = _24_::Accumulate<_24_3_1_::CTPrimes, _24_3_1_::MultiplyT, _24_3_1_::CTValue<int, 1>>::value;
		using Integers = _24_::Valuelist<int, 6, 2, 4, 9, 5, 2, 1, 7>;
		using SortedIntegers = _24_::InsertionSort<Integers, _24_::GreaterThanT>;
		int ResultCTPrimess = _24_::Accumulate<_24_::Primes, _24_::MultiplyT, _24_::CTValue<int, 1>>::value;
		using SelectType = _24_::Select<TestType, 1, 3, 4>;
		using SortedTypes = _24_::InsertionSort<_24_::SignedIntegralTypes, _24_::BiggerThanT>;
		std::cout << "ԭʼ��" << typeid(TestType).name() << std::endl;
		std::cout << "��ӣ�" << typeid(TestType1).name() << std::endl;
		std::cout << "ȡ��4��Ԫ�ص����ͣ�" << typeid(TestType2).name() << std::endl;
		std::cout <<"������͵Ĵ�С��"<< sizeof(LargestType) << std::endl;
		std::cout << typeid(PushBack_OldType).name() << std::endl;
		std::cout << typeid(PushBackType).name() << std::endl;
		std::cout << typeid(PushBack_OldType2).name() << std::endl;
		std::cout << typeid(ReverseType).name() << std::endl;
		std::cout <<" TranformType = " << typeid(TranformType).name() << std::endl;
		std::cout <<" ResultType = " << typeid(ResultType).name() << std::endl;
		std::cout << "������͵Ĵ�С_New��" << sizeof(LargestType_New) << std::endl;
		std::cout << "ST��" << typeid(ST).name() << std::endl;
		std::cout << "ResultPrimes = " << ResultPrimes << std::endl;
		std::cout << "ResultCTPrimes = " << ResultCTPrimes << std::endl;
		std::cout << "SortedIntegers��" << typeid(SortedIntegers).name() << std::endl; 
		std::cout << "ResultCTPrimess = " << ResultCTPrimess << std::endl;
		std::cout << "SelectType��" << typeid(SelectType).name() << std::endl;
		std::cout << "SortedTypes��" << typeid(SortedTypes).name() << std::endl;
		int i = 0;

	}
	return 0;
}