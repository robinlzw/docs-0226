#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	A()
	{
		cout << "A::A()构造函数执行" << endl;
	}
	A(const A& tmpobj)
	{
		m_i = tmpobj.m_i;
		cout << "A::A()拷贝构造函数执行" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行" << endl;
	}
public:
	A& operator=(const A& tmpaobj)
	{
		cout << "A::operaotor=()拷贝赋值运算符执行" << endl;
		return *this;	// 返回一个该对象的引用
	}
public:
	int m_i;
};
 
A operator+(const A& obj1, const A& obj2)
{
	A tmpobj; 		// 调用一次构造函数
	tmpobj.m_i = obj1.m_i + obj2.m_i;
	return  tmpobj; // 执行后调用了一次拷贝构造函数，一次析构函数，说明有临时对象生成
}
 
// 直接运算产生的临时性对象
int main()
{
	// A::A()构造函数执行
	// A::A()构造函数执行
	// A::A()构造函数执行
	// A::A()拷贝构造函数执行
	// A::~A()析构函数执行
	// A::~A()析构函数执行
	// A::~A()析构函数执行
	// A::~A()析构函数执行
	A myobj1; 	// 调用一次构造函数
	A myobj2; 	// 调用一次构造函数
	// 产生的临时对象被立即析构
	myobj1 + myobj2;
 
	return 0;
}