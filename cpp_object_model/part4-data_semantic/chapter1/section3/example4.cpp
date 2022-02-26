#include <iostream>
#include <time.h>
 
using namespace std;
 
/**
 * 1 字节对齐，针对类(结构)，要求其各个成员之间紧密排列，
 * 不允许做边界对齐，不允许在成员之间留任何空隙
 */
#pragma pack(1) //1字节对齐方式
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
#pragma pack() //取消指定的1字节对齐，恢复缺省对齐（原来是多少就恢复成多少）
 
int MYACLS::m_sj = 0; //这才是定义
 
int main()
{
 
	MYACLS myobj; //在栈上分配内存空间
	myobj.m_i = myobj.m_j = myobj.m_k = 0;
	cout << sizeof(myobj) << endl;			//17
	printf("myobj.m_i = %p\n", &myobj.m_i); //myobj.m_i = 00EFF7F8
	printf("myobj.m_j = %p\n", &myobj.m_j); //myobj.m_j = 00EFF7FC
	printf("myobj.m_k = %p\n", &myobj.m_k); //myobj.m_k = 00EFF800
	printf("myobj.m_c = %p\n", &myobj.m_c); //myobj.m_c = 00EFF804
	printf("myobj.m_n = %p\n", &myobj.m_n); //myobj.m_n = 00EFF805
 
	MYACLS *pmyobj = new MYACLS();				//在堆上分配一块内存空间
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i); //pmyobj->m_i = 00F9DFD8
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j); //pmyobj->m_j = 00F9DFDC
	printf("pmyobj->m_k = %p\n", &pmyobj->m_k); //pmyobj->m_k = 00F9DFE0
	printf("pmyobj->m_c = %p\n", &pmyobj->m_c); //pmyobj->m_c = 00F9DFE4
	printf("pmyobj->m_n = %p\n", &pmyobj->m_n); //pmyobj->m_n = 00F9DFE5
 
	return 0;
}