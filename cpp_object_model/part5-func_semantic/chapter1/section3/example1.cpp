#include <iostream>
#include <time.h>
 
using namespace std;
 
class MYACLS
{
public:
	int m_i;
	void myfunc(int abc)
	{
		m_i += abc;
	}
 
	static void mystfunc()
	{
		printf("mystfunc()被调用\n");
	}
};
 
int main()
{
	MYACLS myacls;
	MYACLS *pmyacls = new MYACLS;
	// 对于静态成员函数的调用，无论用对象名还是对象指针调用
	// 都会被编译器转换为一般的针对普通函数(非成员函数)的调用形式
	//
	// 调用静态成员函数时编译器不会插入 this 作为形参
	myacls.mystfunc();
	pmyacls->mystfunc();
	//
	// 这样调用静态成员函数没问题
	((MYACLS *)0)->mystfunc();
	// 本段代码调用，将 0 作为 this 参数传递进普通成员函数调用中
	// 此时只要成员函数中不调用成员变量则不会产生问题
	((MYACLS *)0)->myfunc(12);
 
	return 0;
}