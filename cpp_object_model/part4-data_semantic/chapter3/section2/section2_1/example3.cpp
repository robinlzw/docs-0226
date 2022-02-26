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
	cout << sizeof(Grand) << endl; //4，Grand 包含 int 成员 m_grand 则 sizeof 的值为 4
	cout << sizeof(A1) << endl;	   //12，Grand 中的 int 成员 + A1 中的 int 成员 + 虚基类表指针 = 12 字节
	cout << sizeof(A2) << endl;	   //12，Grand 中的 int 成员 + A2 中的 int 成员 + 虚基类表指针 = 12 字节
	cout << sizeof(C1) << endl;	   //24，Grand 中的 int + A2 中的 int + A1 中的 int + C1 中的 int + A1 虚基类表指针 + A2 虚基类表指针 = 24 字节
 
	return 0;
}