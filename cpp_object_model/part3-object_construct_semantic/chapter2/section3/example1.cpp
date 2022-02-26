#include <iostream>
 
using namespace std;
 
class X
{
public:
	int m_i;
	int* p_mi;
	X() 
	{
		m_i = 0;
		p_mi = new int(100);
		cout << "X类的构造函数被调用" << endl;
	}
	~X()
	{
		delete p_mi;
		cout << "X类的析构函数被调用" << endl;
	}
	X(int value) :m_i(value)
	{
		p_mi = new int(100);
		cout << "X类的X(int)构造函数被调用" << endl;
	}
};
 
int main()
{
	{
		X x0;
		x0.m_i = 150;
		// 浅拷贝
		// 只复制指针值，指针所指向的地址没有额外处理
		X x1(x0);
		cout << x1.m_i << endl;
	}
 
	return 0;
 
}
/**
 * 结果
 * 产生异常
 * 
 * 类 X 没有拷贝构造函数，编译器进行了 bitwise 复制
 * x0 x1 对象的成员变量 p_mi 指向了同一块内存
 * 这块内存是在对象 x0 构造时开辟的，若对象 x0 被释放 x0 的 p_mi 指向的内存被 delete
 * 此时 x1 的 p_mi 指向的内存失效，在 x1 被释放时将 delete 失效的内存空间，从而产生异常
 */