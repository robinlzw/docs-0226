#include <iostream>
 
using namespace std;
 
class MBTXPARENT
{
public:
	MBTXPARENT()
	{
		cout << "MBTXPARENT()构造函数执行了" << endl;
	}
};
 
class MBTX:public MBTXPARENT
{
public:
	int m_i;
	int m_j;
 
	// 默认构造函数
	MBTX()
	{
 		m_i = 15;
	}
 
	void funct()
	{
		cout << "Iamverygood" << endl;
	}
	virtual void mvirfunc() //虚函数
	{
		cout << "mvirfunc" << endl;
	}
};
 
int main()
{
	MBTX myb;
 
	return 0;
 
}
/**
 * 结果
 * 编译器向 MBTX 的默认构造函数中加入了代码
 * 1. 调用父类构造函数 MBTXPARENT::MBTXPARENT
 * 2. MBTX 类中存在虚函数，将 MBTX 类的虚函数表地址赋值给该类对象的虚函数表指针
 */