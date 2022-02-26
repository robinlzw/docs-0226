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
 
// int myfunc()
// {
// 	// 编译报错，该函数中的 myvar 变量是全局的，而全局的 myvar 是 string 类型
// 	return myvar;
// }
 
int main()
{
 
	return 0;
 
}