#include <iostream>
 
using namespace std;
 
class CTB
{
public:
	virtual void mvirfunc() {}
};
 
class CTBSon : public CTB
{
public:
};
 
int main()
{
	CTBSon myctbson1;
	// 编译器生成了 CTBSon 与 CTB 的拷贝构造函数，
	// CTBSon 类的拷贝构造函数调用父类 CTB 的拷贝构造函数，同时用于给被复制的该类对象的虚函数表指针赋值
	// CTB 类的拷贝构造函数用于给被复制的该类对象的虚函数表指针赋值
	CTBSon myctbson2 = myctbson1;
 
	return 0;
 
}