#include <iostream>
 
using namespace std;
 
class CTB
{
public:
	CTB(const CTB&) //拷贝构造函数
	{
		cout << "CTB类的拷贝构造函数执行了" << endl;
	}	
	CTB() //缺省构造函数
	{
	}
};
 
class CTBSon :public CTB
{
public:
};
 
int main()
{
	CTBSon myctbson1;
	// 编译器生成了 CTBSon 的拷贝构造函数，
	// 目的是向该函数中加入调用其父类 CTB 的拷贝构造函数的代码
	CTBSon myctbson2 = myctbson1;
 
	return 0;
 
}