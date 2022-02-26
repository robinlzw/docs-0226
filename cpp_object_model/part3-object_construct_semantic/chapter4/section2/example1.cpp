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
 
void myfunc()
{	
	// s_aobj1 / s_aobj2 变量的作用域只存在于 myfunc 函数内
	static A s_aobj1;
	static A s_aobj2;
	printf("s_aobj1的地址是%p\n", &s_aobj1);
	printf("s_aobj2的地址是%p\n", &s_aobj2);
}
 
// 局部静态对象的构造和析构
int main()
{
	/**
	 * A::A()缺省构造函数执行了
	 * A::A()缺省构造函数执行了
	 * s_aobj1的地址是 0009D14C
	 * s_aobj2的地址是 0009D154
	 * s_aobj1的地址是 0009D14C
	 * s_aobj2的地址是 0009D154
	 * A::~A()析构函数执行了
	 * A::~A()析构函数执行了
	 */
	myfunc();
	myfunc();
 
	return 0;
}