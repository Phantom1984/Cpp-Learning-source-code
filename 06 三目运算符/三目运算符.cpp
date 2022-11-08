#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;

	c = (a > b ? a : b);
	cout << "c = " << c << endl;

	//在C++中三目运算符返回的是变量，可以继续赋值
	//如果a>b，则a赋值100，否则b赋值100
	(a > b ? a : b) = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

}