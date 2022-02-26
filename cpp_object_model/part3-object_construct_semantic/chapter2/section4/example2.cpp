#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	int m_i, m_j;
// 禁止对象的拷贝构造和赋值的方法示例
// 私有化拷贝构造函数与拷贝赋值运算符
//private:
//	A& operator=(const A& tmp);
//	A(const A& tmptime);
// C++11 中使用 =delete 关键字
//public:
//	A& operator=(const A& tmp) = delete;
//	A(const A& tmptime) = delete;
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
 
// 拷贝复制运算符与拷贝构造函数
int main()
{
 
	A aobj;
	aobj.m_i = 15;
	aobj.m_j = 20;
	A aobj2 = aobj; // 执行拷贝构造
 
	A aobj3;
	aobj3.m_i = 13;
	aobj3.m_j = 16;
	aobj2 = aobj3;	// 执行拷贝复制运算符
 
 	return 0;
}