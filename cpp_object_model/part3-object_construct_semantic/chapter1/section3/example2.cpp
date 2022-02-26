#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	A()
	{		
		printf("A::A()执行了，this = %p\n",this);
	};
	virtual ~A() {}
public:
	virtual void myvirfunc() 
	{
		myvirfunc2();
		printf("A::myvirfunc()执行了!\n");
	};
	virtual void myvirfunc2()
	{
		printf("A::myvirfunc2()执行了!\n");
	};
};
 
class B : public  A
{
public:
	B()
	{
		printf("B::B()执行了，this = %p\n", this);
	};
	virtual ~B() {}
public:
	virtual void myvirfunc()
	{
		// 对于 myvirfunc2 的调用是通过虚函数表进行的
		// 注意当前虚函数表指针指向的是哪个虚函数表
		myvirfunc2();
		printf("B::myvirfunc()执行了!\n");
	};
	virtual void myvirfunc2()
	{
		printf("B::myvirfunc2()执行了!\n");
	};
};
 
class C :public B
{
public:
	C() : m_c(11)
	{
		/**
		 * 类的构造函数中调用虚函数并不会通过调用虚函数表来调用
		 * 在构造函数中调用的虚函数从所在类往根类回溯，直接调用优先确定了的虚函数
		 */
		myvirfunc();
		printf("C::C()执行了，this = %p\n", this);
	};
	virtual ~C() {}
public:
	int m_c;
public:
	virtual void myvirfunc()
	{
		myvirfunc2();
		printf("C::myvirfunc()执行了!\n");
	};
	virtual void myvirfunc2()
	{
		printf("C::myvirfunc2()执行了!\n");
	};
};
 
// 继承体系下的对象构造
// 构造函数中对虚函数的调用
// 建议
// 不要在类的构造函数中调用虚函数，不要在类的析构函数中调用虚函数
int main()
{
 
	C* mycobj = new C();
	mycobj->myvirfunc();
	delete mycobj;
 
 	return 0;
}