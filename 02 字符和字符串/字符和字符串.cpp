#include<iostream>
#include<string>
using namespace std;

int main()
{
	//单个字符，只能用单引号，且只能有一个字符
	char ch = 'a';//或者char ch = 97;
	cout << "输出字符:" << ch << endl;

	//字符串，只能用双引号
    //C风格字符串
	char str[] = "abcd";
	cout << "C风格字符串输出：" << str << endl;

	//C++风格字符串
	string str2 = "abcd";
	cout << "C++风格字符串输出：" << str2 << endl;

	system("pause");
	return 0;
}