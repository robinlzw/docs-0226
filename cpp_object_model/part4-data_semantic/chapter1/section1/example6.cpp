#include <iostream>
#include <time.h>
 
using namespace std;
 
typedef string mytype;
class A
{
	typedef int mytype;
public:
	// mytype : int 类型
	void myfunc(mytype tmpvalue);
 
private:
	// mytype : int 类型
	mytype m_value;
};
 
// mytype : int 类型
void A::myfunc(mytype tmpvalue)
{
	m_value = tmpvalue;
}
 
// mytype : string 类型
void myfunc(mytype tmpvalue)
{
	string mvalue = tmpvalue;
}
 
int main()
{
 
	return 0;
 
}