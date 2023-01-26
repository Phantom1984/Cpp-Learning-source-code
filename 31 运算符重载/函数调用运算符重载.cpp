#include"person.h"
/*
函数调用运算符 () 也可以重载
仿函数没有固定写法，非常灵活
*/
//打印输出类
class MyPrint
{
public:
	//重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//仿函数没有固定写法，非常灵活
//加法类
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
int main()
{
	//MyPrint myPrint;
	MyAdd myAdd;
	//myPrint("Hello,World!");//由于重载后使用的方式非常像函数的调用，因此称为仿函数
	int ret = myAdd(100, 100);
	cout << "ret=" << ret << endl;
	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}