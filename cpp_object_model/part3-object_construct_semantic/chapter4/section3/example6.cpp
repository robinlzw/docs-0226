#include <iostream>
#include <time.h>
 
using namespace std;
 
// 直接运算产生的临时性对象
int main()
{
	{
		// 由于临时对象被摧毁，此端代码无法正确打印，内存无效
		const char* q = (string("123") + string("456")).c_str();
		printf("q = %s\n", q);
	}
	{
		// 临时对象绑定到引用而被保留
		// 此时该临时对象的生命周期会变成该引用的生命周期
		const string& aaa = (string("123") + string("456"));
		printf("aaa = %s\n", aaa.c_str());
 
	}
 
	return 0;
}