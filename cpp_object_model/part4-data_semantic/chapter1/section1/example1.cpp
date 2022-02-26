#include <iostream>
#include <time.h>
 
using namespace std;
 
string myvar;  			// 定义全局量，字符串型
 
//定义一个类
class A
{
public:
	int myfunc()	
	{
		// 返回的是类 A 的成员变量 myvar
		// 编译器对 myfunc 的解析是整个类 A 定义完毕之后开始的
		// 类 A 定义完毕，编译器会优先在该类中查找变量 myvar
		return myvar;
	}
private:
	int myvar;			// 同全局量同名的成员变量
};
 
int main()
{
 
	return 0;
 
}