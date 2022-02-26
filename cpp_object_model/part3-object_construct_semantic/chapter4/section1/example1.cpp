#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	A()
	{
		cout << "A::A()缺省构造函数执行了" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行了" << endl;
	}
	int m_i; 	
};
 
// 局部对象的构造与析构
// 只要出了对象作用域，编译器总会在适当的地方插入调用对象析构函数的代码
// 建议 : 尽量将局部变量定义在需要立即用到该变量的代码段附近
// 现用现定义是 C++ 与 C 的一个典型的不同
int main()
{
 
	A obja;
	int mytest = 1;
	if (mytest == 0)
	{
		return 0;
	}
 
 	return 0;
}