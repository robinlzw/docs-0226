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
};
 
// 指向成员函数的指针
// 类中成员函数的地址是在编译期确定的，但是调用成员函数时需要通过对象调用成员函数
// 		原因，成员函数的运行需要依赖 this 指针，该 this 指针指向对象的首地址
int main()
{
 
	A mya;
	void (A:: * pmypoint)(int tempvalue) = &A::myfunc1; // 定义一个成员函数指针并给初值
	pmypoint = &A::myfunc2; 							// 给成员函数指针赋值
 
	// 通过成员函数指针来调用成员函数
	(mya.*pmypoint)(15); 	// 要使用成员函数指针来调用成员函数必须要对象介入
	// 编译器角度 : pmypoint(&mya, 15);
 
	A* pmya = new A();
	(pmya->*pmypoint)(20); 	// 用对象指针使用成员函数指针调用成员函数
	// 编译器角度 : pmypoint(pmya, 20);
 
	// 编译器不会向静态成员函数中插入 this 指针作为第一个参数
	void (*pmyspoint)(int tempvalue) = &A::mysfunc; 	// 一个普通的函数指针，而不是成员函数指针
	pmyspoint(80); 										// 从编译器角度看也是这个代码，不需要有个所谓的 this 指针
 
	// 需要用成员函数指针，虚函数的执行需要 this 指针
	void (A:: * pmyvirfunc)(int tempvalue) = &A::myvirfunc;
 
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
 
	return 0;
}