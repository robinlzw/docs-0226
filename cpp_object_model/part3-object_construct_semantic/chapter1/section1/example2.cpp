#include <iostream>
 
using namespace std;
 
class MATX
{
public:
	MATX() //默认构造函数
	{
		cout << "goodHAHAHA" << endl;
	}
};
 
class MBTX
{
public:
	int m_i;
	int m_j;
 
	void funct()
	{
		cout << "Iamverygood" << endl;
	}
public:
	MATX ma;  //类类型成员变量
};
 
int main()
{
	MBTX myb;	// goodHAHAHA
 
	return 0;
 
}
/**
 * 结果
 * 编译器为 MBTX 生成合成默认构造函数
 * 并且调用了 MATX 的构造函数
 */