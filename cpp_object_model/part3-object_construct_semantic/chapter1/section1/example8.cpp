#include <iostream>
 
using namespace std;
 
class Time
{
public:
	int Second{ 10 };
};
 
int main()
{
	Time mytime;
 
	return 0;
 
}
/**
 * 结果
 * 编译器会为该类生成合成默认构造函数
 */