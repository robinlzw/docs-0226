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
 
// 重新定义虚函数的缺省参数问题
// 缺省参数是静态绑定
// 注意事项 : 不要在子类中重新定义虚函数缺省参数的值
int main()
{
 
	Base base;
	Derive derive;
	Base* pbase = &derive;
	Derive* pderive = &derive;
 
	pderive->myvirfunc(); // Derive::myvirfunc()，value=2
	pbase->myvirfunc();   // Derive::myvirfunc()，value=1
						  // 执行子类的虚函数
						  // 输出的形参 value 是父类的虚函数形参的缺省值
						  // 缺省参数是静态绑定的，因此缺省参数绑定到父类 Base 对应 myvirfunc 的缺省参数上
	pbase = &base;
	pbase->myvirfunc();   // Base::myvirfunc()，value=1
 
	return 0;
}