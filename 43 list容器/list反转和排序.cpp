#include"mylist.h"

/*
reverse(); //反转链表
sort(); //链表排序
*/

bool myCompare(int val1, int val2)
{
	return val1 > val2;
}

//反转和排序
//int main()
//{
//	list<int> L;
//	L.push_back(90);
//	L.push_back(30);
//	L.push_back(20);
//	L.push_back(70);
//	printList(L);
//
//	//反转容器的元素
//	L.reverse();
//	printList(L);
//
//	//排序
//	//所有不支持随机访问迭代器的容器，不可以用标准算法
//	//不支持随机访问迭代器的容器，内部会提供对应一些算法
//	//sort(L.begin(),L.end());//错误
//	L.sort(); //默认的排序规则 从小到大
//	printList(L);
//
//	L.sort(myCompare); //指定规则，从大到小
//	/*降序方法2：
//	list<int>L2;
//    L.sort();
//	L2 = L;
//	L2.reverse();
//	L = L2;*/
//	printList(L);
//}