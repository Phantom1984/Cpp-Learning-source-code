#include"swap_fixed.h"

/*普通的值交换无法做到实参的交换，而利用指针可以实现这一点*/
void swap_fixed(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap_exe()
{
	int a = 10;
	int b = 20;
	cout << "交换前：" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	swap_fixed(&a, &b);
	cout << "交换后：" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
