#include <iostream>
#include <time.h>
 
using namespace std;
 
class MYACLS
{
public:
	virtual void myvirfunc1()
	{
		cout << "虚函数MYACLS::myvirfunc1()执行了" << endl;
	}
	virtual void myvirfunc2()
	{
		cout << "虚函数MYACLS::myvirfunc2()执行了" << endl;
	}
};
 
// vcall，vcall thunk 作用
// 1. 调整 this 指针
// 2. 跳转到真正的虚函数中执行
int main()
{
	{
		// 虚函数在内存中存在固定的地址，该地址是在编译时确定的
		// 此处打印的地址是 vall 函数的地址而不是真正虚函数的地址
		printf("MYACLS::myvirfunc()地址 = %p\n", &MYACLS::myvirfunc1);
		printf("MYACLS::myvirfunc()地址 = %p\n", &MYACLS::myvirfunc2);
		cout << sizeof(MYACLS) << endl;		// 4 字节
		MYACLS *pmyobj = new MYACLS();
		// 编译器通过一系列 vcall 函数，在 vcall 函数中进行跳转，实现跳转到真正虚函数中的目的
		pmyobj->myvirfunc1();
		pmyobj->myvirfunc2();
		cout << "断点设置在这" << endl;
	}
 
	return 0;
}