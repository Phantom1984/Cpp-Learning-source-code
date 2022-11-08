#include"swap.h"

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	cout << "/*注意，这里只是打印交换后的结果*/" << endl;
	cout << "/*实参a和b的值还是原来的，并没有发生改变*/" << endl;
}