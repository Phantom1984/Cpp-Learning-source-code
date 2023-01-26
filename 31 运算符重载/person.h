#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	int m_A;
	int m_B;
};
//赋值重载
class Person2
{
public:
	Person2(int age)
	{
		m_Age = new int(age);//数据创建在堆区
	}
	//重载，赋值运算符
	Person2 &operator=(Person2 &p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);//深拷贝
		return *this;           //返回对象本体，可实现链式编程
	}
	~Person2()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	int *m_Age;//为什么这里要用指针？这是new int()的用法，必须用指针接收
};
//关系重载
class Person3
{
public:
	Person3(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	bool operator==(Person3& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
			return true;
		else
			return false;
	}
	bool operator!=(Person3& p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
			return false;
		else
			return true;
	}
	string m_Name;
	int m_Age;
};