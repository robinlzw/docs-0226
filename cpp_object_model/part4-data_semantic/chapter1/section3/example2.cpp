#include <iostream>
#include <time.h>
 
using namespace std;
 
class MYACLS
{
public:
	int m_i;
	static int m_si; //这是声明不是定义
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;
};
 
int MYACLS::m_sj = 0; //这才是定义
 
int main()
{
 
	MYACLS myobj; //在栈上分配内存空间
	myobj.m_i = myobj.m_j = myobj.m_k = 0;
	cout << sizeof(myobj) << endl;			//12
	printf("myobj.m_i = %p\n", &myobj.m_i); //myobj.m_i = 00EFF7F8
	printf("myobj.m_j = %p\n", &myobj.m_j); //myobj.m_j = 00EFF7FC
	printf("myobj.m_k = %p\n", &myobj.m_k); //myobj.m_k = 00EFF800
 
	MYACLS *pmyobj = new MYACLS();				//在堆上分配一块内存空间
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i); //pmyobj->m_i = 00F9DFD8
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j); //pmyobj->m_j = 00F9DFDC
	printf("pmyobj->m_k = %p\n", &pmyobj->m_k); //pmyobj->m_k = 00F9DFE0
 
	return 0;
}