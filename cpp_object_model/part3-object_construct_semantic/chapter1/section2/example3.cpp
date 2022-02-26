#include <iostream>
 
using namespace std;
 
class X
{
public:
	int m_i;
	X(int value = 0) :m_i(value)
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
	XA(int tmpvalue) : xobj(1000)
	{
		m_test = 500;
	}
};
 
int main()
{
	{
		// 编译器角度
		// X xobj;
		// xobj.X::X();
		XA myaobj(1000);
	}
	return 0;
 
}
// 对于类类型成员变量的初始化，放在构造函数的初始化列表中进行初始化比放在构造函数中初始化效率更高
/**
 * 结果
 * this = 00B3F9B4X X类的X(int)构造函数被调用
 * this = 00B3F9B8X X类的析构函数被调用
 */