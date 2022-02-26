#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	A()
	{
		cout << "A::A()构造函数执行" << endl;
	}
	A(const A& tmpobj)
	{
		m_i = tmpobj.m_i;
		cout << "A::A()拷贝构造函数执行" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行" << endl;
	}
public:
	int m_i;
};
 
A operator+(const A& obj1, const A& obj2)
{
	A tmpobj; 		// 调用一次构造函数
	printf("tmpobj的地址为%p\n", &tmpobj);
	tmpobj.m_i = obj1.m_i + obj2.m_i;
	printf("---------\n");
	return  tmpobj;
}
 
// 拷贝构造函数相关的临时变量
// 开启编译优化后的执行结果
int main()
{
 
	// A::A()构造函数执行
	// myobj1的地址为 001CF9CE
	// A::A()构造函数执行
	// myobj2的地址为 001CF9CD
	// A::A()构造函数执行
	// tmpobj的地址为 001CF9CF
	// ---------
	// resultobj的地址为 001CF9CF
	// A::~A()析构函数执行
	// A::~A()析构函数执行
	// A::~A()析构函数执行
	A myobj1; 	// 调用一次构造函数
	printf("myobj1的地址为%p\n", &myobj1);
	A myobj2; 	// 调用一次构造函数
	printf("myobj2的地址为%p\n", &myobj2);
	// 临时对象直接构造到了resultobj的预留空间中
	// 等价于节省了一次拷贝构造和一次析构
	A resultobj = myobj1 + myobj2;
	printf("resultobj的地址为%p\n", &resultobj);
 
	return 0;
}