#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
 
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
};
 
class Base2
{
public:
	virtual void hBase2() { cout << "Base2::hBase2()" << endl; }
 
	virtual ~Base2()
	{
		cout << "Base2::~Base2()" << endl;
	}
};
 
class Derive : public Base, public Base2 {
public:
	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} //只属于Derive的函数
 
	virtual ~Derive()
	{
		cout << "Derive::~Derive()" << endl;
	}
};
 
int main()
{
 
	// 使用 Base2 指针指向 Derive 对象
	Base2* pb2 = new Derive();
	// 执行 delete pb2; 系统的处理步骤 :
	// 1. 若 Base2 没有析构函数，编译期会直接删除 Base2 子对象首地址开始内存段，程序会产生异常
	// 2. 若 Base2 存在普通的析构函数，系统会调用该析构函数，
	// 		但仍然删除 Base2 子对象首地址开始的内存段，程序异常
	// 3. 若 Base2 存在虚析构函数，delete pb2; 执行成功
	//    原因分析 :
	//	  1) pb2 实际指向的是一个 Derive 对象，意味着若 Derive 中存在虚析构函数
	//		则执行 delete pb2; 由于多态特性，查询虚函数表去执行析构函数时执行的是 Derive 的虚析构函数
	// 		编译器会向 Derive 虚析构函数中插入调用 Base Base2 析构函数代码
	//	  2) 若 Derive 中没有析构函数，由于 Base2 中存在虚析构函数，编译器会为 Derive 合成虚析构函数
	// 		目的是使得 Derive 的虚析构函数能够正确调用 Base Base2 的析构函数
	delete pb2;
 
	return 0;
}