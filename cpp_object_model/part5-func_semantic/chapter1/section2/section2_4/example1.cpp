#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	virtual void f() {}
	virtual ~Base() {}
 
	int m_basei;
};
 
class Derive :public virtual Base
{
public:
	virtual ~Derive() {}
 
	int m_derivei;
};
 
// 虚继承下的虚函数
int main()
{
	cout << sizeof(Derive) << endl;  // 16 = 虚基类表指针 + 虚函数表指针 + 两个 int 成员变量
	Derive dobj;
	dobj.m_basei = 2;   // 13-16 字节
	dobj.m_derivei = 5; // 5-8 字节
	
	Derive* pdobj = new Derive();
	pdobj->f();
 
	return 0;
}