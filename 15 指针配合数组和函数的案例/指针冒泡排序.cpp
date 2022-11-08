#include"bubble_sort.h"

//冒泡排序函数：参数1 数组的首地址 参数2 数组长度
void bubble_sort(int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len-i - 1; j++)
		{
			//如果j>j+1的值，交换数字
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组
void printArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		if (i < len-1)
			cout << ',';
		else
			cout << "。" << endl;
	}
}