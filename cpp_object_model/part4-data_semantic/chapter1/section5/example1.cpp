#include <iostream>
#include <time.h>
 
using namespace std;
 
class MYACLS
{
public:
	int m_i;
	int m_j;
	int m_k;
};
 
void myfunc(int MYACLS::*mempoint, MYACLS &obj)
{
	obj.*mempoint = 260; //注意写法
}
 
int main()
{
 
	MYACLS myobj;
	myobj.m_i = myobj.m_j = myobj.m_k = 0;
	printf("myobj.m_i = %p\n", &myobj.m_i); // 用对象名.成员变量名，这里输出成员变量的内存地址
											// myobj.m_i = 00AFFDB4
 
	MYACLS *pmyobj = new MYACLS();
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i); // pmyobj->m_i = 00EE4FC8
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j); // pmyobj->m_j = 00EE4FCC
 
	int *p1 = &myobj.m_i; // 对象成员变量指针
	int *p2 = &pmyobj->m_j;
	*p1 = 15;
	*p2 = 30;
	printf("p1地址 = %p,p1值=%d\n", p1, *p1); // p1地址 = 00AFFDB4,p1值 = 15
	printf("p2地址 = %p,p2值=%d\n", p2, *p2); // p2地址 = 00EE4FCC,p2值 = 30
 
	cout << "打印成员变量偏移值---------------" << endl;
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i); // MYACLS::m_i = 0
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j); // MYACLS::m_j = 4
 
	// 成员变量指针，其内部保存的是偏移值
	int MYACLS::*mypoint = &MYACLS::m_j;
	printf("MYACLS::m_j偏移值 = %d\n", mypoint); // MYACLS::m_j偏移值 = 4
 
	mypoint = &MYACLS::m_i;
	printf("MYACLS::m_i偏移值 = %d\n", mypoint); // MYACLS::m_i偏移值 = 0
 
	// mypoint 为指向类中成员变量的成员变量指针
	// 成员变量指针指向了类中的某个成员变量，即可通过一个对象名或对象指针访问某个对象的成员变量
	myobj.*mypoint = 22;   //注意写法
	pmyobj->*mypoint = 19; //注意写法
	// 在函数调用中也可以使用成员变量指针作为形参
	myfunc(mypoint, myobj);									 // 注意调用方法
	myfunc(mypoint, *pmyobj);								 // 注意调用方法
	cout << "sizeof(mypoint) = " << sizeof(mypoint) << endl; // 也是4字节
 
	// 一个空的成员变量指针的值为 0xffffffff
	int MYACLS::*mypoint2;
	mypoint2 = 0;
	mypoint2 = NULL;
	printf("mypoint2 = %d\n", mypoint2); // mypoint2 = -1
 
	// 成员变量指针不允许如下操作
	// mypoint2 += 1; //语法错误，普通指针可以，但成员变量指针不可以
	// mypoint2++; //语法错误
	// mypoint2 = ( (&MYACLS::m_i) + 1);	// 语法错误
 
	return 0;
}