#include<iostream>
#include<algorithm>
#include<vector>
#include <numeric>   //包含accumulate算法
using namespace std;

/*
**********常用算术生成算法**********
函数原型：
accumulate(iterator beg, iterator end, value1);   计算容器元素累计总和
fill(iterator beg, iterator end, value2);         向容器中填充元素

beg-开始迭代器; end-结束迭代器; value1-起始值; value2-填充的值
*/

void test_accumulate()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) 
		v.push_back(i);

	int total = accumulate(v.begin(), v.end(), 0);

	cout << "total = " << total << endl;
}

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test_fill()
{

	vector<int> v;
	v.resize(10);
	//填充
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}
/*
int main()
{
	//test_accumulate();
	test_fill();
}*/