#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
};
 
class Base2
{
public:
	virtual void hBase2() { cout << "Base2::hBase2()" << endl; }
};
 
class Derive : public Base, public Base2 {
public:
	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} //只属于Derive的函数
};
 
 
int main()
{
 
	// pb2 指针指向的地址是经过 this 指针调整后的地址
	// 指向的是 Base2 子对象
	//
	// 编译时转换为
	// Derive* temp = new Derive();
	// Base2* pb2 = (Base2*)((char*)(temp) + sizeof(Base));
	Base2* pb2 = new Derive();
	// delete pb2; // 此时删除 pb2 会抛出异常
 
	return 0;
}