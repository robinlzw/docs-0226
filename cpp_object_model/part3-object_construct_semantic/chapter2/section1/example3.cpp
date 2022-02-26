#include <iostream>
 
using namespace std;
 
class CTB
{
public:
	CTB(const CTB&) //拷贝构造函数
	{
		cout << "CTB类的拷贝构造函数执行了" << endl;
	}	
	CTB() //缺省构造函数
	{
	}
};
 
class ASon
{
public:
	int m_testson;
};
 
class A
{
public:
	int m_test;
	ASon asubobj;
	CTB m_ctb;
};
 
int main()
{
	A mya1;
	mya1.m_test = 15;
	mya1.asubobj.m_testson = 120;
	// 编译器因为 CTB 类中具有拷贝构造函数，为类 A 生成了一个拷贝构造函数
	// 目的是向其中添加调用类 CTB 的拷贝构造函数
	// 原来一些成员变量值的复制都不受影响
	A mya2 = mya1;
 
	return 0;
 
}