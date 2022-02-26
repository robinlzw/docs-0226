#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	int m_i, m_j;
};
 
// 对象的默认复制行为
int main()
{
 
	A aobj;
	aobj.m_i = 15;
	aobj.m_j = 20;
	// 系统的默认对象复制行为
	// 可以将 aobj 对象的成员变量值复制到 aobj2 中
	A aobj2 = aobj; // 执行拷贝构造
 
	A aobj3;
	aobj3.m_i = 13;
	aobj3.m_j = 16;
	// 系统的默认对象复制行为
	// 可以将 aobj3 对象的成员变量值复制到 aobj2 中
	aobj2 = aobj3;	// 执行拷贝复制运算符
 
 	return 0;
}