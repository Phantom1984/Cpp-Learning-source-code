#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <ctime>
using namespace std;
/*
**********常用排序算法**********
函数原型：
sort(iterator beg, iterator end, _Pred);    按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
random_shuffle(iterator beg, iterator end); 指定范围内的元素随机调整次序
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  容器元素合并，并存储到另一容器中(两个容器必须有序)
                                                                                
reverse(iterator beg, iterator end);  反转指定范围的元素
beg-开始迭代器; end-结束迭代器; _Pred-谓词; dest-目标容器开始迭代器;
*/

void myPrint(int val)
{
	cout << val << " ";
}

void test_sort() 
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	//sort默认从小到大排序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//从大到小排序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

class myPrint2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test_random_shuffle()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint2());
	cout << endl;

	//打乱顺序
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint2());
	cout << endl;
}

void test_merge()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>vtarget;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vtarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint2());
	cout << endl;
}

void test_reverse()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "反转前： " << endl;
	for_each(v.begin(), v.end(), myPrint2());
	cout << endl;

	cout << "反转后： " << endl;

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint2());
	cout << endl;
}
/*
int main() 
{
	//test_sort();
	//test_random_shuffle();
	//test_merge();
	test_reverse();
}*/