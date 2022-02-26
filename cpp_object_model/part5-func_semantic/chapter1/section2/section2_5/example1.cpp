#include <iostream>
#include <time.h>
 
using namespace std;
 
// 将一个成员函数的地址转换成普通地址
template<typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
	return *static_cast<dst_type*>(static_cast<void*>(&src));
}
 
class TDF
{
public:
	void myf(int val)
	{
		cout << "myf()成员函数执行了" << endl;
	}
};
 
// 不用类对象能否调用类的虚函数和普通成员函数
// 本质上，只要一个函数存在地址便可以直接调用
// 若该函数需要一些参数，但是调用者调用该函数时没有传入这些参数，
//		则只要函数体中没有使用到这些参数，则执行该函数时一般不会报告异常
int main()
{
 
	printf("TDF::myf的地址是%p\n", &TDF::myf);		 // TDF::myf的地址是 0060142E
	typedef void (*Func)();
	Func fun1 = pointer_cast<Func>(&TDF::myf);
	void* func2 = pointer_cast<void*>(&TDF::myf);
	fun1();  										// 把成员函数当普通函数调用
													// myf()成员函数执行了
	return 0;
}