#include <iostream>
#include <time.h>
 
using namespace std;
 
class Grand //爷爷类
{
public:
	int m_grand;
};
class A1 : virtual public Grand //注意这里用了virtual
{
public:
	int m_a1;
};
class A2 : virtual public Grand //注意这里用了virtual
{
public:
	int m_a2;
};
class C1 : public A1, public A2 //这里不需要virtual
{
public:
	int m_c1;
};
 
int main()
{
 
	C1 c1;
	// 此时只有一个 Grand 子类对象
	c1.m_grand = 12; //这句编译时不会再报错
 
	cout << sizeof(Grand) << endl; //1，Grand 为空类其 sizeof 的值为 1
	cout << sizeof(A1) << endl;	   //4，A1 虚继承了 Grand 类，编译器插入虚基类表指针，该指针占 4 字节
	cout << sizeof(A2) << endl;	   //4，A2 虚继承了 Grand 类，编译器插入虚基类表指针，该指针占 4 字节
	cout << sizeof(C1) << endl;	   //8，C1 继承自 A1，A2 且 A1，A2 中都具有虚基类表指针，且被 C1 继承从而占 8 字节
 
	return 0;
}