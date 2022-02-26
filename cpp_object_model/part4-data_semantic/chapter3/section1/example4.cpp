#include <iostream>
#include <time.h>
 
using namespace std;
 
class Base
{
public:
	virtual void mybvirfunc() {}
	int m_bi;
 
public:
	Base()
	{
		printf("Base::Base()构造函数的this指针是：%p!\n", this);
	}
};
 
class Base2
{
public:
	virtual void mybvirfunc2() {}
	int m_b2i;
 
public:
	Base2()
	{
		printf("Base2::Base2()构造函数的this指针是：%p!\n", this);
	}
};
 
class MYACLS : public Base, public Base2
{
public:
	int m_i;
	int m_j;
 
	virtual void myvirfunc()
	{
	}
	MYACLS() //构造函数
	{
		int abc = 1; //方便加断点
		printf("MYACLS::MYACLS()构造函数的this指针是：%p!\n", this);
	}
	~MYACLS() //析构函数
	{
		int def = 0; //方便加断点
	}
};
 
int main()
{
 
	MYACLS myobj;
	Base2 *pbase2 = &myobj; // 注意结果，myobj地址为0x009ffb0c，而pbase2给值后是0x009ffb14，
							//		因为this指针调整是要往后跳8字节的，所以这里myobj地址值+8字节后给了pbase2
							// 编译器做出的调整，Base2* pbase3 = (Base2*)(((char*)& myobj) + sizeof(Base));
	Base *pbase = &myobj;	// pbase的地址就是myobj对象的首地址，因为this不需要调整，Base类的首地址和MYACLS类的首地址相同
 
	Base2 *pbase3 = new MYACLS();			// 父类指针new子类对象，返回的地址是：0x01054bc8，实际这里分配是28字节
	MYACLS *psubobj = (MYACLS *)pbase3; 	// 得到的地址是0x01054bc0 比pbase3指向的地址少了8字节
	//delete pbase3; 						// 报异常 ，据此，可以认为pbase3里返回的地址不是分配的首地址，是this指针调整后的地址，
											//		而new分配的真正的内存首地址应该是psubobj指向的那个地址
	delete psubobj; 						// 成功，验证了psubobj里才是真正的首地址的说法
	return 0;
}