#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a1 = 10;
	int b1 = 3;
	cout << "a1 = " << a1 <<","<< "b1 = " << b1 << endl;
	cout <<"取模结果："<< a1 % b1 << endl;
	cout << "" << endl;

	int a2 = 10;
	int b2 = 20;
	cout << "a2 = " << a2 << "," << "b2 = " << b2 << endl;
	cout << "取模结果：" << a2 % b2 << endl;
	cout << "" << endl;

	/*以下是错误示范，除数不能为0，取模也是如此
	int a3 = 10;
	int b3 = 0;*/

	/*两个小数也不能做取模运算*/

}