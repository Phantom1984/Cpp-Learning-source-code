#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
**********常用拷贝和替换算法**********
函数原型：
copy(iterator beg, iterator end, iterator dest);          按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
replace(iterator beg, iterator end, oldvalue, newvalue);  将区间内旧元素 替换成 新元素
replace_if(iterator beg, iterator end, _pred, newvalue);  按条件替换元素，满足条件的替换成指定元素
swap(container c1, container c2);                         互换两个容器的元素

beg-开始迭代器; end-结束迭代器; _Pred-谓词; 
dest-目标容器开始迭代器; oldvalue-旧元素; newvalue-新元素; 
newvalue-替换的新元素;  c1-容器1; c2-容器2
*/
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test_copy()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) 
		v1.push_back(i + 1);
	cout << "拷贝前的容器v1：";
	for_each(v1.begin(), v1.end(), myPrint());cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	cout << "拷贝后的容器v2：";
	for_each(v2.begin(), v2.end(), myPrint());cout << endl;
}

void test_replace()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());cout << endl;

	//将容器中的20 替换成 2000
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), myPrint());cout << endl;
}

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}

};

void test_replace_if()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());cout << endl;

	//将容器中大于等于的30 替换成 3000
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());cout << endl;
}

void test_swap()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());cout << endl;

	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());cout << endl;
}
/*
int main()
{
	//test_copy();
	//test_replace();
	//test_replace_if();
	test_swap();
}*/