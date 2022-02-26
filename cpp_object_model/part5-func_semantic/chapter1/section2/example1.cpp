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
 
	virtual void myvirfunc()
	{
		printf("myvirfunc()被调用,this = %p\n", this);
		// 对虚函数 myvirfunc2 的调用通过查询虚函数表进行
		myvirfunc2();
		// "类名::" 类范围操作符
		// 这种方式调用 myvirfunc2 便成了直接调用
		// 这种明确调用虚函数的方法等价于直接调用一个普通的成员函数
		// 这种调用方式效率更高，压制住了虚拟机制，不在通过查询虚函数表调用虚函数
		MYACLS::myvirfunc2();
	}
 
	virtual void myvirfunc2()
	{
		printf("myvirfunc2()被调用,this = %p\n", this);
	}
};
 
// 全局函数gmyfunc
void gmyfunc(MYACLS *ptmp, int abc)
{
	ptmp->m_i += abc;
}
 
int main()
{
	MYACLS myacls;
	// 通过对象名 myacls 调用虚函数，类似于调用普通成员函数
	myacls.myvirfunc();
	MYACLS *pmyacls = new MYACLS;
	// 通过对象指针调用虚函数，则需要通过虚函数表指针查找虚函数表
	// 然后通过虚函数表确定要调用的虚函数的地址，从而调用指定的虚函数
	//
	// 在编译器角度该段代码
	// (*pmyacls->vptr[0])(pmyacls)
	// vptr 编译器生成的虚函数表指针，指向虚函数表
	// vptr[0] 表示虚函数表中的第一项
	// *pmyacls->vptr[0] 表示待调用虚函数的入口地址
	// (pmyacls) 入参代表 this 指针
	pmyacls->myvirfunc();
	delete pmyacls;
 
	return 0;
}