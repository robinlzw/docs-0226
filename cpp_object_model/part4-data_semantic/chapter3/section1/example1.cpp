#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	int m_bi;
 
public:
	Base()
	{
		printf("Base::Base()构造函数的this指针是：%p!\n", this);
	}
};
 
class MYACLS : public Base
{
public:
	int m_i;
	int m_j;
 
	virtual void myvirfunc()
	{
	}
	MYACLS() //构造函数
	{
		int abc = 1; //方便加断点
		printf("MYACLS::MYACLS()构造函数的this指针是：%p!\n", this);
	}
	~MYACLS() //析构函数
	{
		int def = 0; //方便加断点
	}
};
 
int main()
{
	cout << sizeof(MYACLS) << endl;				  // 16
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi); // MYACLS::m_bi = 0
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);	  // MYACLS::m_i = 8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);	  // MYACLS::m_j = 12
												  // Base::Base()构造函数的this指针是：00CFF8F4!
												  // MYACLS::MYACLS()构造函数的this指针是：00CFF8F0!
												  // 从执行结果可见 this 指针进行了调整，跳过了 vptr 直接指向了父类的成员变量
	return 0;
}