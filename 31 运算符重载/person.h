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
//��ֵ����
class Person2
{
public:
	Person2(int age)
	{
		m_Age = new int(age);//���ݴ����ڶ���
	}
	//���أ���ֵ�����
	Person2 &operator=(Person2 &p)
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);//���
		return *this;           //���ض����壬��ʵ����ʽ���
	}
	~Person2()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	int *m_Age;//Ϊʲô����Ҫ��ָ�룿����new int()���÷���������ָ�����
};
//��ϵ����
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