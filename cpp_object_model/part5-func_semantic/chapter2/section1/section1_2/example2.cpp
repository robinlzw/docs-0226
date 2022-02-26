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
 
	virtual void myvirfunc(int value = 1)
	{
		cout << "Base::myvirfunc(),value=" << value << endl;
	}
};
 
class Derive : public Base
{
public:
	void myfunc()
	{
		cout << "Derive::myfunc()" << endl;
	}
 
	virtual void myvirfunc(int value = 2)
	{
		cout << "Derive::myvirfunc(),value=" << value << endl;
	}
};
 
class Derive2 : public Base
{
public:
};
 
// C++ 中的多态性
// C++ 的多态的体现 : 必须存在虚函数并且调用虚函数，没有虚函数则不存在多态
//
// 1. 存在父类与子类并且父类中必须存在虚函数且子类中复写了父类中的虚函数
// 2. 父类指针指向子类对象或父类引用绑定子类对象
// 3. 当以父类的指针或引用调用子类中重写了的虚函数时，便体现出了多态，此时调用的是子类的虚函数
int main()
{
 
	Derive derive;
	Derive* pderive = &derive;
	pderive->myfunc();   		// Derive::myfunc()
 
	Base* pbase2 = new Derive();
	pbase2->myvirfunc(); 		// Derive::myvirfunc()
 
	Derive derive2;
	Base& yinbase = derive2;
	yinbase.myvirfunc(); 		// Derive::myvirfunc()
 
	return 0;
}