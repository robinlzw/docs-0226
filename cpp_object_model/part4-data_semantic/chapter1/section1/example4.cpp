#include <iostream>
#include <time.h>
 
using namespace std;
 
typedef string mytype;
class A
{
public:
	void myfunc(mytype tmpvalue) 	// 这个mytype是string类型
	{
		// 编译报错，tmpvalue 为 string 类型，m_value 为 int 类型
		// m_value = tmpvalue;
	}
 
private:
	// mytype 是 A 类私有的，外部无法访问
	typedef int mytype;
	mytype m_value;					// 这个mytype是int类型
};
 
int main()
{
 
	return 0;
 
}