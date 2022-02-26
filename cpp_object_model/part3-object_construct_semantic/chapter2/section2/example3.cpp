#include <iostream>
 
using namespace std;
 
class X
{
public:
	int m_i;
	X(const X& tmpx)
	{
		cout << "X类的拷贝构造函数被调用" << endl;
	}
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
		// 添加拷贝构造函数导致编译器内置的 bitwise 复制功能失效
		// 添加拷贝构造函数需要对类中各个成员变量的初始化负责
		cout << x1.m_i << endl;
	}
 
	return 0;
 
}
/**
 * 结果
 * X类的构造函数被调用
 * X类的拷贝构造函数被调用
 * -858993460
 * X类的析构函数被调用
 * X类的析构函数被调用
 */