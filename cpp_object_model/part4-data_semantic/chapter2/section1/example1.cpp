#include <iostream>
#include <time.h>
 
using namespace std;
 
class FAC //父类
{
public:
	int m_fai;
	int m_faj;
};
 
class MYACLS : public FAC //子类
{
public:
	int m_i;
	int m_j;
};
 
int main()
{
	printf("MYACLS::m_i = %d\n", &FAC::m_fai);	  // MYACLS::m_i = 0
	printf("MYACLS::m_i = %d\n", &FAC::m_faj);	  // MYACLS::m_i = 4
	printf("MYACLS::m_i = %d\n", &MYACLS::m_fai); // MYACLS::m_i = 0
	printf("MYACLS::m_i = %d\n", &MYACLS::m_faj); // MYACLS::m_i = 4
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);	  // MYACLS::m_i = 8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);	  // MYACLS::m_j = 12
	// 1. 一个子类对象所包含的内容，是其自己的成员与父类成员的总和
	// 2. 父类的成员排在子类成员的前面
 
	return 0;
}