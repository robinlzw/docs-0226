#include <iostream>
#include <time.h>
 
using namespace std;
 
class MYACLS
{
public:
	int m_i;
	static int m_si; // 这是声明不是定义
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;
};
 
int MYACLS::m_sj = 0; // 这才是定义
 
int main()
{
 
	MYACLS myobj;
	/**
	 * 类 MYACLS 中整型成员变量有 3 个，每个 4 字节，总计 12 字节
	 * 静态成员变量属于类，不占类对象的内存空间
	 * 静态成员变量存储于整个程序的数据段中
	 */
	cout << sizeof(myobj) << endl; //12
 
	myobj.m_k = 8;
	myobj.m_i = 2;
	myobj.m_j = 5;
 
	return 0;
}