#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	A()
	{		
		printf("A::A()执行了，this = %p\n",this);
	};
	virtual ~A() {}
};
 
class B : public  A
{
public:
	B()
	{
		printf("B::B()执行了，this = %p\n", this);
	};
	virtual ~B() {}
};
 
class C :public B
{
public:
	C() : m_c(11)
	{
		printf("C::C()执行了，this = %p\n", this);
	};
	virtual ~C() {}
public:
	int m_c;
};
 
// 继承体系下的对象构造
// 对象的构造顺序 : 从父类到子类，从根源到末端
int main()
{
	// A::A()执行了，this = 0075FE8C
	// B::B()执行了，this = 0075FE8C
	// C::C()执行了，this = 0075FE8C
	// 调用关系
	/**
	 * C::C()
	 *		B::B()
	 *			A::A()
	 *				printf("A::A()执行了，this = %p\n",this);
	 *			printf("B::B()执行了，this = %p\n", this);
	 *		vptr = C::vftable;	// 给虚函数表指针赋予的最终值
	 *		m_c = 1; 			// 成员初始化列表
	 *		printf("C::C()执行了，this = %p\n", this);	
	 */
	C c;
 
 	return 0;
}