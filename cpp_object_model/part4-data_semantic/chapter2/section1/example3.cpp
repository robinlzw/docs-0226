#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base1
{
public:
	int m_i1;
	char m_c1;
};
 
class Base2 : public Base1
{
public:
	char m_c2;
};
 
class Base3 : public Base2
{
public:
	char m_c3;
};
 
int main()
{
	cout << sizeof(Base1) << endl; //8，存在字节对齐(根据编译器的不同而不同)
	cout << sizeof(Base2) << endl; //12
	cout << sizeof(Base3) << endl; //16
 
	printf("Base3::m_i1 = %d\n", &Base3::m_i1); //Base3::m_i1 = 0
	printf("Base3::m_c1 = %d\n", &Base3::m_c1); //Base3::m_c1 = 4
	printf("Base3::m_c2 = %d\n", &Base3::m_c2); //Base3::m_c2 = 8
	printf("Base3::m_c3 = %d\n", &Base3::m_c3); //Base3::m_c3 = 12
}