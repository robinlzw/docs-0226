#include <iostream>
 
using namespace std;
 
class X
{
public:
	int m_i;
	X(int value = 0) :m_i(value) //类型转换构造函数
	{
		printf("this = %p", this);
		cout << "X类的X(int)构造函数被调用" << endl;
	}
	X(const X& tmpv)
	{
		printf("this = %p", this);
		cout << "X类的拷贝构造函数被调用" << endl;
	}
	X& operator=(const X& tmpTime)
	{
		printf("this = %p", this);
		cout << "X类的拷贝赋值运算符被调用" << endl;
		return *this; //返回一个该对象的引用
	}
	~X()
	{
		printf("this = %p", this);
		cout << "X类的析构函数被调用" << endl;
	}
};
 
class XA
{
public:
	X  xobj;
	int m_test;
	XA(int tmpvalue)
	{
		// xobj 的初始化放在了 XA 类的构造函数中
		xobj = 1000;
		// 针对 xobj = 1000; 编译器的角度
		// X tmpobj;						// 生成一个临时对象
		// tmpobj.X::X(1000);				// 临时对象调用构造函数
		// xobj.X::operator=(tmpobj);		// 调用 xobj 的拷贝复制运算符
		// tmpobj.X::~X();					// 调用析构函数销毁临时对象
 
		m_test = 500;
	}
};
 
int main()
{
	{
		// 在执行类 XA 构造函数的函数体之前便构造了 xobj 对象
		// 调用了类 X 的构造函数
		// 编译器角度
		// X xobj;
		// xobj.X::X();
		XA myaobj(1000);
	}
	return 0;
 
}
 
/**
 * 结果
 * this = 00B3F9B4X X类的X(int)构造函数被调用
 * this = 00B3F9B8X X类的X(int)构造函数被调用
 * this = 00B3F9B4X X类的拷贝赋值运算符被调用
 * this = 00B3F9B8X X类的析构函数被调用
 * this = 00B3F9B4X X类的析构函数被调用
 */