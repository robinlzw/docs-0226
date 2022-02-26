#include <iostream>
 
using namespace std;
 
class X
{
public:
	int m_i;
	X() 
	{
		m_i = 0;
		cout << "X类的构造函数被调用" << endl;
	}
	~X()
	{
		cout << "X类的析构函数被调用" << endl;
	}
	X(int value) :m_i(value)
	{
		cout << "X类的X(int)构造函数被调用" << endl;
	}
};
 
int main()
{
	{
		X x0;
		x0.m_i = 150;
		X x1(x0);
		// 即使 X 类没有拷贝构造函数，x1.m_i = 150
		// 原因 : 编译器本身支持针对成员变量的 bitwise 复制
		cout << x1.m_i << endl;
	}
 
	return 0;
 
}