#include <iostream>
#include <time.h>
 
using namespace std;
 
class A 
{
public:
	virtual void myvirfunc() {}
};
 
// C++ 中的多态性
// C++ 的多态的体现 : 必须存在虚函数并且调用虚函数，没有虚函数则不存在多态
//
// 当调用一个虚函数时，调用路线是通过查询虚函数表找到虚函数入口地址从而调用虚函数则体现了多态
int main()
{
 
	A* pa = new A();
	// 对象指针调用虚函数，则通过虚函数表指针查找虚函数表
	// 从而通过虚函数表确定待调用的虚函数地址，调用虚函数
	pa->myvirfunc(); 	// 这是多态
 
	A a;
	// 使用对象名调用虚函数，类似于调用普通成员函数
	a.myvirfunc(); 		// 这不是多态
 
	A* ya = &a;
	ya->myvirfunc();	// 这是多态
 
	return 0;
}