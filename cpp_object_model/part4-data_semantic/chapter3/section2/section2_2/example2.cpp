#include <iostream>
#include <time.h>
 
using namespace std;
 
class Grand //爷爷类
{
public:
	int m_grand;
};
class Grand2
{
public:
	int m_grand2;
};
class A1 : virtual public Grand, public Grand2 //注意这里用了virtual
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
 
	cout << sizeof(Grand) << endl; //4
	cout << sizeof(A1) << endl;	   //16
	cout << sizeof(A2) << endl;	   //12
	cout << sizeof(C1) << endl;	   //28
 
	A1 a1obj;
	a1obj.m_grand = 2;
	a1obj.m_grand2 = 6;
	a1obj.m_a1 = 5;
	return 0;
}