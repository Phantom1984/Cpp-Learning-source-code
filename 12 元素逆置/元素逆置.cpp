#include<iostream>
#include<string>
using namespace std;

int main()
{
	int array[5] = { 1,3,2,5,4 };	//定义原始数组
	int in_arr[5] = { 0,0,0,0,0 };  //创建逆置数组
	int i;

	for (i = 0; i < 5; i++)
		in_arr[i] = array[4 - i];
	cout << "原始数组为：";
	for (i = 0; i < 5; i++)
		cout << array[i] << ",";
	cout << endl;
	cout << "逆置数组为：";
	for (i = 0; i < 5; i++)
		cout << in_arr[i] << ",";
	cout << endl;
}