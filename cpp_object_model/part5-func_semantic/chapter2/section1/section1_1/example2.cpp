#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	void myfunc()
	{
		cout << "Base::myfunc()" << endl;
	}
};
 
class Derive : public Base
{
public:
	void myfunc()
	{
		cout << "Derive::myfunc()" << endl;
	}
};
 
// 继承非虚函数的注意事项
//
// 普通成员函数是静态绑定
// myfunc 是普通成员函数，该函数的调用取决于调用者的静态类型
// 注意 : 不要在子类中重新定义一个继承来的非虚成员函数
int main()
{
 
	Derive derive;
	Derive* pderive = &derive;
	pderive->myfunc();   		// Derive::myfunc()
	Base* pbase = &derive;
	pbase->myfunc();   			// Base::myfunc()，此处调用的是父类的 myfunc
 
	return 0;
}