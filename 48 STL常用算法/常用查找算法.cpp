#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
/*
**********常用查找算法**********
/------------------------------------------------------​/
find //查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

函数原型：
find(iterator beg, iterator end, value);
beg 开始迭代器; end 结束迭代器; value 查找的元素
/------------------------------------------------------​/
/------------------------------------------------------​/​
find_if //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

函数原型：
find_if(iterator beg, iterator end, _Pred);
beg 开始迭代器; end 结束迭代器; _Pred 函数或者谓词（返回bool类型的仿函数）
find_if() 函数会根据指定的查找规则，在指定区域内查找第一个符合该函数要求（使函数返回 true）的元素。

find和find_if的区别在于，后者可以自定义规则
/------------------------------------------------------​/
/------------------------------------------------------​/​
adjacent_find // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器

函数原型：
adjacent_find(iterator beg, iterator end);
beg 开始迭代器; end 结束迭代器
------------------------------------------------------
/------------------------------------------------------​/
binary_search // 查找指定的元素，查到 返回true 否则false

bool binary_search(iterator beg, iterator end, value)(注意: 在无序序列中不可用!)
beg 开始迭代器; end 结束迭代器; value 查找的元素
/------------------------------------------------------​/
/------------------------------------------------------​/​
count // 统计元素出现次数

函数原型：
count(iterator beg, iterator end, value);
beg 开始迭代器; end 结束迭代器; value 统计的元素
/------------------------------------------------------​/
/------------------------------------------------------​/​
count_if // 按条件统计元素个数

函数原型：
count_if(iterator beg, iterator end, _Pred);
beg 开始迭代器; end 结束迭代器; _Pred 谓词
*/
void test_find01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	//查找容器中是否有5这个元素
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
		cout << "没有找到！" << endl;
	else
		cout << "找到了！" << endl;
}
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重载 ==，让底层find知道如何对比Person数据类型
	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
			return true;
		else
			return false;
	}
	string m_Name;
	int m_Age;
};
void test_find02()
{
	vector<Person>v;
	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//要查找的目标
	Person pp("bbb", 20);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
	if (it == v.end())
		cout << "没有找到！" << endl;
	else
	{
		cout << "找到元素" << endl;
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}
}

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test_find_if01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);

	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
		cout << "没有找到!" << endl;
	else
		cout << "找到大于5的数字:" << *it << endl;
}

class Person2
{
public:
	Person2(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator()(Person2& p)
	{
		return p.m_Age > 20;
	}

};

void test_find_if02()
{
	vector<Person2> v;

	//创建数据
	Person2 p1("aaa", 10);
	Person2 p2("bbb", 20);
	Person2 p3("ccc", 30);
	Person2 p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person2>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
	}
}

void test_adjacent_find()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	//查找相邻重复元素
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "找不到!" << endl;
	}
	else {
		cout << "找到相邻重复元素为:" << *it << endl;
	}
}
void test_binary_search()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	//二分查找
	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
		cout << "找到了" << endl;
	else
		cout << "未找到" << endl;
}

void test_count01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);

	cout << "4的个数为： " << num << endl;
}

class Person3
{
public:
	Person3(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person3& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test_count02()
{
	vector<Person3> v;

	Person3 p1("刘备", 35);
	Person3 p2("关羽", 35);
	Person3 p3("张飞", 35);
	Person3 p4("赵云", 30);
	Person3 p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person3 p("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}

class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};

void test_count_if01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int num = count_if(v.begin(), v.end(), Greater4());

	cout << "大于4的个数为： " << num << endl;
}

class AgeLess35
{
public:
	bool operator()(const Person2& p)
	{
		return p.m_Age < 35;
	}
};

void test_count_if02()
{
	vector<Person2> v;

	Person2 p1("刘备", 35);
	Person2 p2("关羽", 35);
	Person2 p3("张飞", 35);
	Person2 p4("赵云", 30);
	Person2 p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小于35岁的个数：" << num << endl;
}
/*
int main()
{
	//test_find01();
	//test_find02();
	//test_find_if01();
	//test_find_if02();
	//test_adjacent_find();
	//test_binary_search();//二分查找必须是有序序列
	//test_count01();
	//test_count02();//统计自定义数据类型时候，需要配合重载 operator==
	//test_count_if01();
	test_count_if02();
}*/