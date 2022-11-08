#include<iostream>
#include<string>
using namespace std;
/*-------------------------冒泡排序----------------------*/
/*相当于每次提取最大值元素，然后把它放到首位或者末位，循环n次*/
int main()
{
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	int i, j, t;

	//打印原始数组
	cout << "原始数组为：";
	for (i = 0; i < 9; i++)
	{
		cout << arr[i] << ",";
	}
	cout << endl;

	//从左至右，依次递增
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 8-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}
				
		}
	}

	//打印排序结果
	cout << "排序后：";
	for (i = 0; i < 9; i++)
	{
		cout << arr[i] << ",";
	}
	cout << endl;
}