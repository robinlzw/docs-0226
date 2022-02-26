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
	// 注意
	// 单一继承父类带虚函数的数据成员布局与单一继承父类不带虚函数的数据成员布局是一致的
	cout << sizeof(MYACLS) << endl;				  // 16
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi); // MYACLS::m_bi = 4
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);	  // MYACLS::m_i = 8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);	  // MYACLS::m_j = 12
												  // Base::Base()构造函数的this指针是：00CFF8F0!
												  // MYACLS::MYACLS()构造函数的this指针是：00CFF8F0!
												  // 从执行结果可见 this 指针没有调整
												  // 由于父类带有虚函数则父类具有虚函数表指针 vptr
												  // 子类的虚函数表指针可以视为从父类继承同样位于内存布局的最上面
	return 0;
}