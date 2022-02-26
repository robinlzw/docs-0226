#include <iostream>
#include <time.h>
 
using namespace std;
 
class A
{
public:
	A()
	{
		cout << "A::A()缺省构造函数执行了" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行了" << endl;
	}
	int m_i; 	
};
 
// 全局对象(全局变量)保存在数据段中
// 全局对象(全局变量)若没有给初始值情况下，编译器会给定默认值 0
//
// 全局对象/全局变量的地址在可执行程序中是确定的，并且装载到内存运行时便按照该地址为全局变量/全局对象分配内存
// 堆中的内存通过 delete 回收
// 栈中的内存只要离开了作用域便自动回收
// 全局对象的内存在程序运行期一直存在
A g_aobj;
 
// 全局对象的构造与析构
int main()
{
	/**
	 * 1. 全局变量 g_aobj 获得地址
	 * 2. 将全局变量 g_aobj 的内存内容清 0
	 * 3. 调用全局变量 g_aobj 对应类 A 的构造函数
	 * 4. 执行 main() 主函数
	 * 5. 当整个 mian 函数执行完毕，调用全局变量 g_aobj 对应的类 A 的析构函数
	 * 6. 整个程序执行完毕
	 */
	/**
	 * A::A() 缺省构造函数执行了
	 * g_aobj 对象的地址 = 0041E138
	 * A::A() 缺省构造函数执行了
	 * jbobj 对象的地址 = 00FDFE4C
	 * A::~A()析构函数执行了
	 * A::~A()析构函数执行了
	 */
	printf("g_aobj 对象的地址 = %p\n", &g_aobj);
	A jbobj;
	printf("jbobj 对象的地址 = %p\n", &jbobj);
 
	g_aobj.m_i = 6;
 
 	return 0;
}