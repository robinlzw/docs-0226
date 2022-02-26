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
 
// 访问虚基类的成员变量要比访问其他成员变量更慢
int main()
{
 
	cout << sizeof(Grand) << endl; //4
	cout << sizeof(A1) << endl;	   //12
	cout << sizeof(A2) << endl;	   //12
	cout << sizeof(C1) << endl;	   //24
 
	// 给虚基类表指针赋值的操作是在孙子类的构造函数中进行的
	C1 c1obj;
	c1obj.m_grand = 2; // 对于虚基类中成员变量的访问，此处只用到了图4.66 中的 vbptr1
					   // 虚基类三层结构解决了仅保留一份爷爷子对象的问题
					   // 同时引入了虚基类表指针，额外占用了内存空间
	c1obj.m_a1 = 5;
	c1obj.m_a2 = 6;
	c1obj.m_c1 = 8;
 
	A2 *pa2 = &c1obj; // 指向 A2 类子对象首地址
	pa2->m_grand = 8; // 使用图 4.66 中第二个虚基类表的第 5 - 8 个字节做偏移值
					  // 确定 m_grand 成员变量的首地址并为其赋值
	pa2->m_a2 = 9;
 
	return 0;
}