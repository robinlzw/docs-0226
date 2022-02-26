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
 
public:
	char m_c; //1字节
	int m_n;  //4字节
};
 
int MYACLS::m_sj = 0; //这才是定义
 
int main()
{
 
	MYACLS myobj; //在栈上分配内存空间
	myobj.m_i = myobj.m_j = myobj.m_k = 0;
	cout << sizeof(myobj) << endl;			//20
	printf("myobj.m_i = %p\n", &myobj.m_i); //myobj.m_i = 00EFF7F8
	printf("myobj.m_j = %p\n", &myobj.m_j); //myobj.m_j = 00EFF7FC
	printf("myobj.m_k = %p\n", &myobj.m_k); //myobj.m_k = 00EFF800
	printf("myobj.m_c = %p\n", &myobj.m_c); //myobj.m_c = 00EFF804
	printf("myobj.m_n = %p\n", &myobj.m_n); //myobj.m_n = 00EFF808
	/**
	 * 类成员之间排列不连续，则会进行边界调整；
	 * 边界调整是往成员变量之间填补一些字节，使得类对象的 sizeof 值为 4 或 8 的倍数；
	 * 边界调整的主要目的是提高程序执行效率，且由编译器自动完成；
	 */
	MYACLS *pmyobj = new MYACLS();				//在堆上分配一块内存空间
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i); //pmyobj->m_i = 00F9DFD8
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j); //pmyobj->m_j = 00F9DFDC
	printf("pmyobj->m_k = %p\n", &pmyobj->m_k); //pmyobj->m_k = 00F9DFE0
	printf("pmyobj->m_c = %p\n", &pmyobj->m_c); //pmyobj->m_c = 00F9DFE4
	printf("pmyobj->m_n = %p\n", &pmyobj->m_n); //pmyobj->m_n = 00F9DFE8
 
	return 0;
}