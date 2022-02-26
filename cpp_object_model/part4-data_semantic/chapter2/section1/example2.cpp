#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	int m_i1;
	char m_c1;
	char m_c2;
	char m_c3;
};
 
int main()
{
	cout << sizeof(Base) << endl; // 8，存在字节对齐
 
	printf("Base::m_i1 = %d\n", &Base::m_i1); // 0
	printf("Base::m_c1 = %d\n", &Base::m_c1); // 4
	printf("Base::m_c2 = %d\n", &Base::m_c2); // 5
	printf("Base::m_c3 = %d\n", &Base::m_c3); // 6
}