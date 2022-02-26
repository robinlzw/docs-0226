#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	int m_bi;
};
 
class MYACLS : public Base
{
public:
	int m_i;
	int m_j;
 
	virtual void myvirfunc()
	{
	}
	MYACLS() //构造函数
	{
		int abc = 1; //方便加断点
	}
	~MYACLS() //析构函数
	{
		int def = 0; //方便加断点
	}
};
 
int main()
{
	// 注意
	// 单一继承父类带虚函数的数据成员布局与单一继承父类不带虚函数的数据成员布局是一致的
	cout << sizeof(MYACLS) << endl;				  // 16
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi); // MYACLS::m_bi = 0
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);	  // MYACLS::m_i = 8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);	  // MYACLS::m_j = 12
 
	return 0;
}