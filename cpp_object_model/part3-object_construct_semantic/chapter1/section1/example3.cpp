#include <iostream>
 
using namespace std;
 
class M0TX
{
public:
	M0TX()//默认构造函数
	{
		cout << "Ogood!" << endl;		
	}
};
 
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
	MATX ma;  	//类类型成员变量
	M0TX m0; 	//注意定义顺序，先定义的ma，再定义的m0
};
 
int main()
{
	MBTX myb;	// goodHAHAHA， Ogood
 
	return 0;
 
}
/**
 * 结果
 * 编译器为 MBTX 生成合成默认构造函数
 * 并且依次调用了 MATX M0TX 的构造函数
 */