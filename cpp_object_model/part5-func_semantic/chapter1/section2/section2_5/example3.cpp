#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	void myfunc1(int tempvalue1)
	{
		cout << "tempvalue1 = " << tempvalue1 << endl;
	}
	void myfunc2(int tempvalue2)
	{
		cout << "tempvalue2 = " << tempvalue2 << endl;
	}
 
public:
	static void mysfunc(int tempvalue) 
	{ 
		cout << "A::mysfunc()静态成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
 
public:
	virtual void myvirfuncPrev(int tempvalue) 
	{ 
		cout << "A::myvirfuncPrev()虚成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
	virtual void myvirfunc(int tempvalue) 
	{
		cout << "A::myvirfunc()虚成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
public:
	virtual ~A()
	{
 
	}
};
 
class B :public A
{
public:
	virtual void myvirfunc(int tempvalue) 
	{
		cout << "B::myvirfunc()虚成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
	virtual ~B() 
	{
	}
};
 
// 指向虚成员函数的指针和 vcall
// vall 在继承关系中的体现 
int main()
{			
 
	// 需要用成员函数指针，虚函数的执行需要 this 指针
	void (A:: *pmyvirfunc)(int tempvalue) = &A::myvirfunc;
 
	A* pvaobj = new A;
	// 通过虚函数表指针确定虚函数表，通过虚函数表确定虚函数地址并执行
	// vcall 代表一段待执行代码的首地址，该段代码引导程序的执行流程执行正确的虚函数
	// vcall 可以简单的视为虚函数表
	pvaobj->myvirfunc(190);
	(pvaobj->*pmyvirfunc)(190);
	// &A::myvirfunc 代表一个地址，记录该虚函数在虚函数表中的一个偏移值，
	// 从而可以根据该偏移值调用该虚函数
	printf("%p\n", &A::myvirfunc);
	// 普通成员函数的调用不存在 vcall
	pmyvirfunc = &A::myfunc2;
	(pvaobj->*pmyvirfunc)(33);
 
	B* pmyb = new B();
	// &A::myvirfunc 保存了一个偏移的信息
	// 该编译信息与 &B::myvirfunc 保存的偏移信息相同
	void (B:: * pmyvirfunc)(int tempvalue) = &A::myvirfunc;	// 成员函数指针
															// B::myvirfunc()虚成员函数执行了，tempvalue = 190
	(pmyb->*pmyvirfunc)(190);
 
	printf("%p\n", &A::myvirfunc);	// 003F14C4
	printf("%p\n", &B::myvirfunc);	// 003F150A
 
	return 0;
}