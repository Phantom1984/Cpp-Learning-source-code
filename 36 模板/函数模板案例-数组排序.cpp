#include"startup.h"
/*
案例描述：

利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
排序规则从大到小，排序算法为选择排序
分别利用char数组和int数组进行测试
*/

/*
实现通用 对数组进行排序的函数
规则：从大到小
算法：选择
测试：char数组、int数组
*/

//交换函数模板
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法:选择排序
template<class T>
void choice_Sort(T arr[], int len)
{
	//计算数组长度
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值下标
		for (int j = i + 1; j < len; j++)
		{
			//寻找最大值，并与arr[max]交换
			if (arr[max] < arr[j])
				max = j;
		}
		if (max != i)
			mySwap(arr[max], arr[i]);
	}
}

//提供打印数组模板
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << ",";
	cout << endl;
}
/*
int main()
{
	//测试char数组
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	choice_Sort(charArr, num);
	printArray(charArr, num);
}*/