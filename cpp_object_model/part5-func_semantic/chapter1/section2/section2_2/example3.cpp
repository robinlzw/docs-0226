#include <iostream>
#include <time.h>
 
using namespace std;
 
class ParentClass 							// 一个父类
{
public:
	ParentClass()	
	{
		cout << "ParentClass::ParentClass()" << endl;
	}
	~ParentClass()
	{
		cout << "ParentClass::~ParentClass()" << endl;
	}
};
 
class SonClass : public ParentClass 		// 一个子类
{
public:
	SonClass()
	{
		cout << "SonClass::SonClass()" << endl;
	}
	~SonClass()
	{
		cout << "SonClass::~SonClass()" << endl;
	}
};
 
// 虚析构函数的意义
int main()
{
 
	/**
	 * ParentClass::ParentClass()
	 * SonClass::SonClass()
	 * SonClass::~SonClass()
	 * ParentClass::~ParentClass()
	 */
	SonClass sonobj;
	/**
	 * ParentClass::ParentClass()
	 * SonClass::SonClass()
	 * ParentClass::~ParentClass()
	 */
	// 此时仅仅执行了父类的析构函数并未执行子类的析构函数，可能会引起内存泄漏
	ParentClass* parobj = new SonClass;	// 创建 SonClass 对象
	delete parobj;  					// 删除 SonClass 对象
 
	return 0;
}