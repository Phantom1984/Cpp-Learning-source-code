#include"mylist.h"

/*
函数原型：

list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem); //构造函数将n个elem拷贝给本身。
list(const list &lst); //拷贝构造函数。
*/

void printList(const list<int>& l)//const让容器不可修改
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}

/*
int main()
{
	list<int>l1;//默认构造
	//添加数据
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	printList(l1);

	//区间构造方式
	list<int>l2(l1.begin(), l1.end());
	printList(l2);

	//拷贝构造
	list<int>l3(l2);
	printList(l3);

	//n个elements
	list<int>l4(10, 1000);
	printList(l4);
}*/