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
 
public:
	virtual Base* clone() const
	{
		return new Base();
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
 
public:
	virtual Base2* clone() const
	{
		return new Base2();
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
 
public:
	virtual Derive* clone() const
	{
		return new Derive();
	}
 
};
 
// this 指针调整
// this 指针调整目的就是让对象指针正确地指向对象的首地址
// 从而能正确调用对象的成员函数或正确确定变量的存储位置
int main()
{
	// this 指针的调整的情况
	// 1. 通过指向第二个基类的指针调用继承类的虚函数时
	Base2* pb2 = new Derive();
	delete pb2;  //这里调用了 Derive 类的虚析构函数
 
	// 2. 一个指向派生类的指针调用第二个基类中的虚函数时
	Derive* pd2 = new Derive();
	pd2->hBase2();
 
	// 3. 允许虚函数的返回值类型有所变化时
	Base2* pb1 = new Derive();
	Base2* pb2 = pb1->clone(); 	// 执行 Derive::clone()
								// 此时 pb1 会调整指向 Derive 对象的起始地址
								// 从而调用 Derive 版本的 clone 方法
	return 0;
}