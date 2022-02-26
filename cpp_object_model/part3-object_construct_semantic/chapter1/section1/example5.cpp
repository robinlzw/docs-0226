#include <iostream>
 
using namespace std;
 
class MBTX
{
public:
	int m_i;
	int m_j;
 
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
 * 编译器为 MBTX 生成合成默认构造函数
 * 并且在生成的构造函数中插入代码
 * 用于将类 MBTX 的虚函数表地址赋给对象的虚函数表指针
 * (可以将虚函数表指针看成是一个隐藏的成员变量，属于类对象)
 */