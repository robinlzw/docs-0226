#include <iostream>
#include <time.h>
 
using namespace std;
 
class JI
{
public:
	JI()
	{
		cout << "JI::JI()缺省构造函数执行了" << endl;
	}
 
public:
	virtual ~JI() 
	{
		cout << "JI::~JI()析构函数执行了" << endl;
	}
};
 
class A : public JI
{
public:
	int m_i, m_j;
public:
	A& operator=(const A& tmp)
	{
		m_i = tmp.m_i;
		m_j = tmp.m_j;
		cout << "A::operator=(const A&)拷贝赋值运算符执行了" << endl;
		return *this;
	}
	A(const A& tmptime) 
	{
		m_i = tmptime.m_i;
		m_j = tmptime.m_j;
		cout << "A::A(const A&)拷贝构造函数执行了" << endl;
	}
	A()
	{
		cout << "A::A()缺省构造函数执行了" << endl;		
	}
};
 
class ParC
{
public:
	virtual ~ParC()
	{
		cout << "ParC::~ParC()虚析构函数执行了" << endl;
	}
};
class MemC
{
public:
	ParC m_j;
};
 
// 析构函数语义
// 若一个类没有定义析构函数，则生成的目标文件中也不会有该类的析构函数
// 析构函数的合成
// 1. 若当前类继承一个基类，基类带有析构函数，则编译器会为当前类合成一个析构函数
//		先执行子类的析构函数在执行父类的析构函数
// 2. 若当前类的成员变量是一个类类型变量，且该类类型带有析构函数，则编译器会为当前类合成一个析构函数
//		先执行 MemC 的析构函数再执行 ParC 的析构函数
int main()
{
 
	A aobj;
	MemC mobj;
 
 	return 0;
}