#include<iostream>
#include<string>
using namespace std;
/*-----------------寻找数组中的最大元素----------------*/

int main()
{
	int array[5] = { 300,350,200,400,250 };
	int max_num, min_num;
	int i,j = 1;
	// 打印原始数组
	cout << "原始数组：";
	for (i = 0; i < 5; i++)
	{
		cout << array[i] << ",";
	}
	cout << endl;
	// 提取最大值元素
	for (j = 1; j < 5; j++)
	{
		if (array[i] > array[j])
			max_num = array[i];
		else
		{
			max_num = array[j];
			i = j;
		}
	}
	// 提取最小值元素
	for (j = 1; j < 5; j++)
	{
		if (array[i] < array[j])
			min_num = array[i];
		else
		{
			min_num = array[j];
			i = j;
		}
	}
	cout << "最大元素为：" << max_num << endl;
	cout << "最小元素为：" << min_num << endl;

}