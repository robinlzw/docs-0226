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
};
 
int main()
{
	MBTX myb;
 
	return 0;
 
}
/**
 * 结果
 * 编译器没有为 MBTX 生成合成默认构造函数
 */