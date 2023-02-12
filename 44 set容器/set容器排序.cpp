#include"myset.h"

/*利用仿函数，可以改变排序规则*/

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

class myCompare
{
public:
	bool operator()(int val1,int val2)
	{
		return val1 > val2;
	}
};

class comparePerson
{
public:
	bool operator()(const Person& p1,  const Person& p2)const//这里的const应该是vs2019特定的语法
	{
		//按照年龄降序
		return p1.m_Age > p2.m_Age;
	}
};

void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(70);
	s1.insert(60);
	printSet(s1);

	//指定排序规则
	set<int, myCompare>s2;
	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}


void test02()
{
	//自定义数据类型，都会指定排序规则
	set<Person,comparePerson>s;
	//创建Person对象
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}

int main()
{
	//test01();
	test02();
}