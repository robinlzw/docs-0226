#include <iostream>
 
using namespace std;
 
class Base
{
public:
	int ba;
	int bb;
	Base(int tmpa, int tmpb) // 构造函数
	{
	}
};
 
class CSub
{
public:
	CSub(int tmpvalue)
	{
 
	}
};
 
class A :public Base
{
public:
	int m_x;
	int m_y;
	int &m_yy;
	const int m_myc;
	CSub cmysub;
 
	A(int& tmpvalue) :m_yy(tmpvalue), m_myc(tmpvalue), Base(tmpvalue, tmpvalue), cmysub(tmpvalue)
	{
		//m_yy = tmpvalue; // 错误，不可以，必须在初始化列表中进行绑定
		m_x = 0;
		m_y = 0;
		m_yy = 160;
	}
 
};
 
int main()
{
	{
		int abc = 1;
		A a(abc);
	}
	
	return 0;
 
}