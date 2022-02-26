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
 
	void funct()
	{
		cout << "Iamverygood" << endl;
	}
};
 
int main()
{
	MBTX myb;	// MBTXPARENT()构造函数执行了
 
	return 0;
 
}
/**
 * 结果
 * 编译器为 MBTX 生成合成默认构造函数
 * 并且调用了 MBTXPARENT 的构造函数
 */