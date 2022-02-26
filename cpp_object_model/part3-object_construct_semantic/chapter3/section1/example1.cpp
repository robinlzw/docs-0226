#include <iostream>
 
using namespace std;
 
struct TC
{
	int i;          //内置类型可以移动
	std::string s;  //string类型定义了自己的移动操作
};
 
int main()
{
	TC a;
	a.i = 100;
	a.s = "I Love China!";
	const char* p = a.s.c_str();
	// 编译器为 TC 生成移动构造函数
	// 目的向该函数中添加调用 string 类的移动构造函数的代码
	// 导致结构/类TC移动构造函数的执行,数据移动不是std::move所为，而是string的移动构造函数所为
	TC b = std::move(a);
	const char* q = b.s.c_str();
	// p q 指向不同的内存地址，这是由 string 类的特性导致
 
	return 0;
 
}