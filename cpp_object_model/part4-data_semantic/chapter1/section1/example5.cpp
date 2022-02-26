#include <iostream>
#include <time.h>
 
using namespace std;
 
typedef string mytype;
class A
{
public:
	void myfunc(mytype tmpvalue);
 
private:
	// 此处的 mytype 是私有的，类 A 外部实现时不可见
	typedef int mytype;
	mytype m_value;					// 这个mytype是int类型
};
 
// 编译报错，
// 类 A 内部声明的 myfunc 的形参 tmpvalue 是 string 类型
// 类 A 外部实现的 myfunc 的形参 tmpvalue 是 int 类型
//
// void A::myfunc(mytype tmpvalue) 	// 这个mytype又变成了int类型，但若在类中定义myfunc，那么参数中出现的mytype是string类型
// {
// 	m_value = tmpvalue;
// }
 
int main()
{
 
	return 0;
 
}