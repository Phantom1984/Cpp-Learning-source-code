#include<iostream>
#include<string>
using namespace std;

int main()
{
	//1.整型输入
	int a ;//最好给a默认赋值，比如int a = 0;
	cout << "请给整型变量a赋值:" << endl;
	cin >> a;
	cout << "整型变量a = " << a << endl;
/*
	//2.浮点型输入
	float f = 3.14f;
	cout << "请给浮点型变量f赋值：" << endl;
	cin >> f;
	cout << "浮点型变量f = " << f << endl;

	//3.字符型
	char ch = 'a';
	cout << "请给字符型变量赋值：" << endl;
	cin >> ch;
	cout << "字符型变量ch = " << ch << endl;

	//4.字符串型
	string str = "abc";
	cout << "字符串初始值:" << str << endl;
	cout << "请给字符串重新赋值：" << endl;
	cin >> str;
	cout << "字符串str = " << str << endl;

	//5.布尔类型，非0值都为真,true,1
	bool flag = false;
	cout << "请给布尔类型flag赋值" << flag << endl;
	cin >> flag;
	cout << "布尔类型flag = " << flag << endl;
*/
	system("pause");
	return 0;
}