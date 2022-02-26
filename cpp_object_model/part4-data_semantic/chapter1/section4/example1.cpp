#include <iostream>
#include <time.h>
 
using namespace std;
 
class FAC
{
public:
	int m_fai;
	int m_faj;
};
 
class MYACLS : public FAC
{
public:
	int m_i;
	static int m_si; // 这是声明不是定义
	int m_j;
 
public:
	void myfunc()
	{
		m_i = 5;
		m_j = 6;
	}
};
 
// 静态成员变量可以视为一个全局变量
// 该变量只在类的空间内可见
// 静态成员变量保存在可执行文件的数据段
int MYACLS::m_si = 0; // 这才是定义
 
int main()
{
 
	MYACLS myobj;
	MYACLS *pmyobj = new MYACLS();
	// 类引用静态成员变量
	cout << MYACLS::m_si << endl;
	// 类对象引用静态成员变量
	cout << myobj.m_si << endl;
	// 对象指针引用静态成员变量
	cout << pmyobj->m_si << endl;
 
	// 多种给类中的静态成员变量的赋值语法
	// 对应的汇编代码完全相同
	MYACLS::m_si = 1;
 
	/**
	 * myobj 这种对象名访问成员变量的方式，在编译期便计算出了成员变量的偏移值
	 * pmyobj 这种对象指针是在执行期 new 出一个具体的对象，并且 new 出的对象类型(父、子、孙)不确定
	 * 无法在编译期计算出成员变量的偏移值，需要间接手段访问非静态成员变量
	 */
	myobj.m_si = 2;
	pmyobj->m_si = 3;
 
	printf("myobj.m_i = %p\n", &myobj.m_i);		  // myobj.m_i = 008FFB0C
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i);	  // pmyobj->m_i = 00A4DBE0
	printf("MYACLS::m_si = %p\n", &MYACLS::m_si); // MYACLS::m_si = 0016C2D0
	printf("MYACLS::m_si = %p\n", &myobj.m_si);	  // MYACLS::m_si = 0016C2D0
	printf("MYACLS::m_si = %p\n", &pmyobj->m_si); // MYACLS::m_si = 0016C2D0
 
	/**
	 * 编译器向 myfunc 成员函数中插入了一个隐式的形参 this，
	 * this 代表对象本身
	 * 
	 * void MYACLS::myfunc(MYACLS* const this)
	 * {
	 * 		this->m_i = 5;
	 * 		this->m_j = 6;
	 * }
	 * 
	 * 当访问一个成员变量时，编译器会将类对象的首地址加上待访问的成员变量的偏移值
	 */
	pmyobj->myfunc();
 
	// 即便存在继承关系，类的成员变量的偏移值仍然是在编译时期计算完毕的
	// 对于普通成员变量的存取，
	// 无论单一类、单一继承、多重继承，
	// 还是访问父类、子类其效率一致
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i); //8，类成员变量的偏移值
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j); //12，类成员变量的偏移值
 
	pmyobj->m_faj = 7; // 给父类的成员变量赋值
 
	return 0;
}