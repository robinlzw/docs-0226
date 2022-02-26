#include <iostream>
 
using namespace std;
 
class A
{
public:
	int m_test;
};
 
int main()
{
	A mya1;
	mya1.m_test = 15;
	// 这属于拷贝构造动作，但编译器没有合成拷贝构造函数
	// 程序员没有书写类 A 的拷贝构造函数，编译器也没有生成合成拷贝构造函数
	// mya2 中的成员变量 m_test 的值为 15
	// 编译器内部的成员变量的初始化手法，
	// 对于基本数据类型，编译器直接进行值拷贝而不生成合成拷贝构造函数
	A mya2 = mya1;
 
	return 0;
 
}