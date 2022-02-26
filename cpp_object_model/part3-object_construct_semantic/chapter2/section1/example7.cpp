#include <iostream>
 
using namespace std;
 
class Grand //爷爷类
{
public:
};
class A : virtual public  Grand
{
public:
};
class A2 : virtual  public  Grand
{
public:
};
class C :public A, public A2 
{
public:
};
 
int main()
{
	C cc1;
	// 编译器为 A A2 C 都生成了拷贝构造函数
	C cc2 = cc1;
 
	return 0;
 
}