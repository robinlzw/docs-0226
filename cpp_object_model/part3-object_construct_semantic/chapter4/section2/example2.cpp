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
	static A s_aobj[5];
	printf("s_aobj数组的首地址是%p\n", s_aobj);
}
 
// 局部静态对象数组的构造和析构
int main()
{
	/**
	 * A::A()缺省构造函数执行了
	 * A::A()缺省构造函数执行了
	 * A::A()缺省构造函数执行了
	 * A::A()缺省构造函数执行了
	 * A::A()缺省构造函数执行了
	 * s_aobj数组的首地址是 0x6021D0
	 * s_aobj数组的首地址是 0x6021D0
	 * A::~A()析构函数执行了
	 * A::~A()析构函数执行了
	 * A::~A()析构函数执行了
	 * A::~A()析构函数执行了
	 * A::~A()析构函数执行了
	 */
	myfunc();
	myfunc();
 
	return 0;
}