#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	virtual void mybvirfunc() {}
	int m_bi;
 
public:
	Base()
	{
		printf("Base::Base()构造函数的this指针是：%p!\n", this);
	}
};
 
class Base2
{
public:
	virtual void mybvirfunc2() {}
	int m_b2i;
 
public:
	Base2()
	{
		printf("Base2::Base2()构造函数的this指针是：%p!\n", this);
	}
};
 
class MYACLS : public Base, public Base2
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
	cout << sizeof(MYACLS) << endl;					// 24
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);	// MYACLS::m_bi = 4
	printf("MYACLS::m_b2i = %d\n", &MYACLS::m_b2i); // MYACLS::m_b2i = 4
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);		// MYACLS::m_i = 16
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);		// MYACLS::m_j = 20
													// Base::Base()构造函数的this指针是：00CFF8F0!
													// Base2::Base2()构造函数的this指针是：00CFF8F8!
													// MYACLS::MYACLS()构造函数的this指针是：00CFF8F0!
													// 从执行结果可见 this 指针没有调整
													// 由于父类带有虚函数则父类具有虚函数表指针 vptr
													// 子类的虚函数表指针可以视为从父类继承同样位于内存布局的最上面
	return 0;
}