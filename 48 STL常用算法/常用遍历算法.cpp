#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
**********常用遍历算法**********
for_each //遍历容器
transform //搬运容器到另一个容器中

函数原型：
for_each(iterator beg, iterator end, _func);要熟练掌握
beg 开始迭代器; end 结束迭代器; _func 函数或者函数对象

transform(iterator beg1, iterator end1, iterator beg2, _func);
beg1 源容器开始迭代器; end1 源容器结束迭代器
beg2 目标容器开始迭代器; _func 函数或者函数对象

*/

//普通函数
void print01(int val)
{
	cout << val <<" ";
}

class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test_for_each()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	for_each(v.begin(), v.end(), print01);
	cout << endl;
	for_each(v.begin(), v.end(), print02());
}

class TransForm
{
public:
	int operator()(int val)
	{
		return val;
	}
};
void test_TransForm()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	vector<int>vTarget; //目标容器
	vTarget.resize(v.size()); // 目标容器需要提前开辟空间
	for_each(v.begin(), v.end(), print02());cout << endl;
	transform(v.begin(), v.end(), vTarget.begin(), TransForm());
	for_each(vTarget.begin(), vTarget.end(), print02());cout << endl;
}
/*
int main()
{
	//test_for_each();
	//test_TransForm();
}*/