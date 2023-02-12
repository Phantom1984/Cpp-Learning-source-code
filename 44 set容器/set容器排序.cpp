#include"myset.h"

/*���÷º��������Ըı��������*/

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
	bool operator()(const Person& p1,  const Person& p2)const//�����constӦ����vs2019�ض����﷨
	{
		//�������併��
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

	//ָ���������
	set<int, myCompare>s2;
	for (set<int, myCompare>::iterator it = s2.begin(); it != s2.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}


void test02()
{
	//�Զ����������ͣ�����ָ���������
	set<Person,comparePerson>s;
	//����Person����
	Person p1("����", 23);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << endl;
	}
}

int main()
{
	//test01();
	test02();
}