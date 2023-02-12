#include<iostream>
#include<string>
using namespace std;
/*
概念：
重载函数调用操作符的类，其对象常称为函数对象
函数对象使用重载的()时，行为类似函数调用，也叫仿函数

本质：
函数对象(仿函数)是一个类，不是一个函数

函数对象使用
函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递
*/

//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd 
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};


//2、函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;   //使用次数统计
	}
	int count;
};

//3、函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}
/*
int main()
{
	//方法一
	cout << "方法一:" << endl;
	MyAdd myadd;
	cout << myadd(10, 20) << endl; cout << endl;

	//方法二
	cout << "方法二:" << endl;
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数为： " << myPrint.count << endl;cout << endl;

	//方法三
	cout << "方法三:" << endl;
	MyPrint mp;
	doPrint(mp, "Hello C++");
}*/