#include <iostream>
 
using namespace std;
 
class CTBSon
{
public:
	virtual void mvirfunc() {}
};
 
int main()
{
	CTBSon myctbson1;
	// 编译器生成了 CTBSon 的拷贝构造函数，
	// 目的是加入为被复制的该类对象的虚函数表指针赋值
	CTBSon myctbson2 = myctbson1;
 
	return 0;
 
}