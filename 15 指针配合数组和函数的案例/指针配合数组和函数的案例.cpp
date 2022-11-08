#include"swap_fixed.h"
#include"bubble_sort.h"
/*------------------------案例描述---------------------*/
/*封装一个函数，利用冒泡排序，实现对整型数组的升序排序*/
/*例如数组：int arr[10]={4,3,6,9,1,2,10,8,7,5};*/


int main()
{
	/*实参交换测试函数*/
	//swap_exe();
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	//数组长度：数组总长度/数组单个元素长度，数组名代表总长度
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "排序前的数组：";
	printArray(arr, len);

	//冒泡排序函数
	bubble_sort(arr, len);

	//打印排序后的数组
	cout << "排序后的数组：";
	printArray(arr, len);
    
}