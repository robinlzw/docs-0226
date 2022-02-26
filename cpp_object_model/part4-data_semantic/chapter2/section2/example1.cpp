#include <iostream>
#include <time.h>
 
using namespace std;
 
class MYACLS
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
 
	cout << sizeof(MYACLS) << endl;				// 12
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i); // MYACLS::m_i = 4
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j); // MYACLS::m_j = 8
 
	MYACLS myobj;
	myobj.m_i = 3;
	myobj.m_j = 6;
 
	return 0;
}