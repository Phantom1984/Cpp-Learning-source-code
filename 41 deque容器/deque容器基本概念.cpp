#include"deque.h"
/*
功能：
双端数组，可以对头端进行插入删除操作

deque与vector区别：
vector对于头部的插入删除效率低，数据量越大，效率越低
deque相对而言，对头部的插入删除速度回比vector快
vector访问元素时的速度会比deque快,这和两者内部实现有关
*/

void printDeque(const deque<int>& d)//const修饰配合const_iterator，只读权限
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
		cout << *it << " ";
	cout << endl;
}
/*
int main()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);
	//和vector很像，不再多赘述，不懂的就去查文档
}*/