#include <iostream>
#include <time.h>
 
using namespace std;
 
string myvar;  			// 定义全局量，字符串型
 
//定义一个类
class A
{
public:
	int myfunc();
private:
	int myvar;			// 同全局量同名的成员变量
};
 
// 编译器遇到成员函数体内的变量时，会先到类中查找，
// 若查找不到则会到全局范围内查找
int A::myfunc()
{
	return myvar;
}
 
int main()
{
 
	return 0;
 
}