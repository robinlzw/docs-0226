#include <iostream>
#include <time.h>
 
using namespace std;
 
//A代表类名，m代表成员名，这里用了一个0，违反常规的写法，但能输出出一个类成员偏移地址来
#define GET(A, m) (int)(&((A *)0)->m)
 
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
 
private:
	int m_pria;
	int m_prib;
 
public:
	void printMemPoint() //因为要打印私有的成员变量偏移值，只能用成员函数打印
	{
		cout << "打印成员变量偏移值---------------" << endl;
		//类名不要省略，必须要有，打印的才是偏移值，否则打印的就是对象的该成员变量的物理地址了
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i); //MYACLS::m_i = 4
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j); //MYACLS::m_j = 8
		printf("MYACLS::m_k = %d\n", &MYACLS::m_k); //MYACLS::m_k = 12
		printf("MYACLS::m_c = %d\n", &MYACLS::m_c); //MYACLS::m_c = 16
		printf("MYACLS::m_n = %d\n", &MYACLS::m_n); //MYACLS::m_n = 17
 
		printf("MYACLS::m_pria = %d\n", &MYACLS::m_pria); //MYACLS::m_pria = 21
		printf("MYACLS::m_prib = %d\n", &MYACLS::m_prib); //MYACLS::m_prib = 25
		cout << "------------------------" << endl;
		//利用GET宏定义来打印m_prib成员变量的偏移值
		cout << "MYACLS::m_prib = " << GET(MYACLS, m_prib) << endl; //MYACLS::m_prib = 25
	}
 
public:
	/**
	 * 存在虚函数，编译器会为 MYACLS 类添加虚函数表指针 vptr 这种隐藏的成员变量
	 * 该成员变量占 4 字节，且位于类的开头位置
	 */
	virtual void mfv() {}
};
#pragma pack() //取消指定的1字节对齐，恢复缺省对齐（原来是多少就恢复成多少）
 
int MYACLS::m_sj = 0; //这才是定义
 
int main()
{
 
	MYACLS myobj; //在栈上分配内存空间
	myobj.m_i = myobj.m_j = myobj.m_k = 0;
	cout << sizeof(myobj) << endl;			//29
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
 
	pmyobj->printMemPoint();
 
	// 成员变量指针打印成员变量的偏移值
	int MYACLS::*mypoint = &MYACLS::m_n;
	printf("pmyobj->m_n偏移地址 = %d\n", mypoint); // pmyobj->m_n偏移地址 = 17
 
	return 0;
}