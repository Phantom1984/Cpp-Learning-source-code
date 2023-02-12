#include"mylist.h"

/*函数原型：

assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
list& operator=(const list &lst); //重载等号操作符
swap(lst); //将lst与本身的元素互换。*/
/*
int main()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	//赋值
	list<int>l2;
	l2 = l1;
	printList(l2);

	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);

	list<int>l4;
	l4.assign(10, 100);
	printList(l4);

	//交换
	list<int>l5;
	l5.assign(10, 100);
	cout << "交换前： " << endl;
	printList(l1);
	printList(l5);

	cout << endl;

	l1.swap(l5);

	cout << "交换后： " << endl;
	printList(l1);
	printList(l5);
}*/