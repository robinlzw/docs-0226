#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
};
 
class Derive : public Base
{
public:
};
 
class Derive2 : public Base
{
public:
};
 
// 静态类型 : 对象定义时的类型，编译期间便确定；
// 动态类型 : 对象目前指向的类型，运行时确定的类型；
int main()
{
 
	Base base;   	// 静态类型是 Base，没有动态类型
	Derive derive; 	// 静态类型是 Derive，没有动态类型
	Base* pbase;  	// 定义时类型为 Base *，则静态类型是 Base *，
					// 该指针没有指向任何对象则没有动态类型
	Base* pbase2 = new Derive();  // 静态类型依旧是 Base *，动态类型为 Derive
	Base* pbase3 = new Derive2(); // 静态类型依旧是 Base *，动态类型为 Derive2
 
	// 动态类型在执行过程中可以改变
	pbase = pbase2;	// pbase 的动态类型为 Derive
	pbase = pbase3;	// pbase 的动态类型为 Derive2
 
	return 0;
}