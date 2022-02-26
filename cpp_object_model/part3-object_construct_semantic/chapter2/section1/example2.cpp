#include <iostream>
 
using namespace std;
 
class ASon
{
public:
	int m_testson;
};
 
class A
{
public:
	int m_test;
	ASon asubobj;
};
 
int main()
{
	A mya1;
	mya1.m_test = 15;
	mya1.asubobj.m_testson = 120;
	// 这属于拷贝构造动作，但编译器没有合成拷贝构造函数
	// 程序员没有书写类 A 的拷贝构造函数，编译器也没有生成合成拷贝构造函数
	// mya2 中的成员变量 m_test 的值为 15
	// mya2 中的 ASon asubobj 也被赋值
	// 编译器内部的成员变量的初始化手法，
	// 对于基本数据类型，编译器直接进行值拷贝而不生成合成拷贝构造函数
	// 对于类类型成员变量，编译器会递归地复制该类类型的每个成员变量
	A mya2 = mya1;
 
	return 0;
 
}