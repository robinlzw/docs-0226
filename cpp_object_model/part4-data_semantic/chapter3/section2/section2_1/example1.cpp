#include <iostream>
#include <time.h>
 
using namespace std;
 
class Grand //爷爷类
{
public:
	int m_grand;
};
class A1 : public Grand
{
public:
};
class A2 : public Grand
{
public:
};
class C1 : public A1, public A2
{
public:
};
 
int main()
{
	cout << sizeof(Grand) << endl; //4
	cout << sizeof(A1) << endl;	   //4
	cout << sizeof(A2) << endl;	   //4
	// 内存中存在两份 Grand 子对象，从而造成存在两份 m_grand 成员变量
	// 共计 8 个字节的内存空间
	cout << sizeof(C1) << endl; //8
 
	C1 c1;
	// 系统提示对 m_grand 的访问不明确
	// 原因定义类 C1 对象时， Grand 类会被继承两次
	// 1. C1 -> A1 -> Grand
	// 2. C1 -> A2 -> Grand
	// c1.m_grand = 12; // 这句编译时会报错
	c1.A1::m_grand = 5;
	c1.A2::m_grand = 8;
 
	return 0;
}