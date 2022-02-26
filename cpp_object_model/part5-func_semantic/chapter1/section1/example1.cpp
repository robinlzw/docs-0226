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
};
 
// 全局函数gmyfunc
void gmyfunc(MYACLS *ptmp, int abc)
{
	ptmp->m_i += abc;
}
 
// 普通成员函数调用方法
// 编译器内部实际是将对成员函数的调用转换成了一种对全局函数的调用
int main()
{
	MYACLS myacls;
	/**
	 * 成员函数被编译器转换为全局函数的格式
	 * 注，编译器会额外安插一个 this 指针，一般放在参数列表的开头
	 * 1. this 指向实际生成的类对象，可以确定对象所属的某个成员变量在内存中的位置
	 * 2. 常规成员变量的存取通过 this 形参进行
	 * void myfunc(MYACLS* const this, int abc)
	 * {
	 * 		this->m_i += abc;
	 * }
	 */
	myacls.myfunc(18);	  // 调用成员函数
	gmyfunc(&myacls, 18); // 调用全局函数
	printf("MYACLS::myfunc地址=%p\n", &MYACLS::myfunc);
 
	return 0;
}