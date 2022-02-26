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
 
	virtual void myvirfunc()
	{
		cout << "Base::myvirfunc()" << endl;
	}
};
 
class Derive : public Base
{
public:
	void myfunc()
	{
		cout << "Derive::myfunc()" << endl;
	}
 
	virtual void myvirfunc()
	{
		cout << "Derive::myvirfunc()" << endl;
	}
};
 
class Derive2 : public Base
{
public:
};
 
// 虚函数的动态绑定
// 虚函数是动态绑定的
// myvirfunc 是虚函数，该函数的调用取决于调用者的动态类型
int main()
{
 
	Base base;
	Derive derive;
	Base* pbase = &derive;
	Derive* pderive = &derive;
 
	pderive->myvirfunc(); // Derive::myvirfunc()
	pbase->myvirfunc();   // Derive::myvirfunc()
	pbase = &base;
	pbase->myvirfunc();   // Base::myvirfunc()
 
	return 0;
}