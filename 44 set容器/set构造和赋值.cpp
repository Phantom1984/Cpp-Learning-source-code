#include<iostream>
#include<set>
using namespace std;
/*
简介：
所有元素都会在插入时自动被排序(升序)

本质：
set/multiset属于关联式容器，底层结构是用二叉树实现。

set和multiset区别：
set不允许容器中有重复的元素
multiset允许容器中有重复的元素
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}
/*
int main()
{
	set<int>s1;//默认构造
	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	printSet(s1);
	//set插入元素时会自动排序
	//重复值不会被插入

	set<int>s2(s1);
	printSet(s2);
}*/