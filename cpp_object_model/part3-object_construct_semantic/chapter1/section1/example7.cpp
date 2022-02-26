#include <iostream>
 
using namespace std;
 
class Grand //爷爷类
{
public:
};
class A : virtual public  Grand  //注意virtual 
{
public:
};
class A2 : virtual  public  Grand //注意virtual 
{
public:
};
class C :public A, public A2 //这里不需要virtual
{
public:
	C()  //默认 构造函数
	{
		cout << "C::C()默认构造函数执行了" << endl;
	}
};
 
int main()
{
	C cc;
 
	return 0;
 
}
/**
 * 结果
 * 编译器会为子类和父类都生成合成默认构造函数
 */