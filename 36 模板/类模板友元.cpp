#include"startup.h"
/*
ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
*/

//ͨ��ȫ�ֺ��� ��ӡPerson��Ϣ
template<class T1, class T2>class Person;
template<class T1, class T2>void printPerson2(Person<T1, T2> &p);
/*����ʵ�ַǳ��鷳��һ�㲻����ʹ��*/

template<class T1,class T2>
class Person
{
	//ȫ�ֺ���������ʵ��
	friend void printPerson(Person<T1,T2> &p)
	{
		cout << "ȫ�ֺ���������ʵ�֣�" << endl;
		cout << "������" << p.m_Name << "���䣺" << p.m_Age << endl;
	}
	//ȫ�ֺ���������ʵ��
	//�ӿ�ģ������б�
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void printPerson2<>(Person<T1, T2> &p);
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//����ʵ��
template<class T1,class T2>
void printPerson2(Person<T1, T2> &p)
{
	cout << "ȫ�ֺ���������ʵ�֣�" << endl;
	cout << "������" << p.m_Name << "���䣺" << p.m_Age << endl;
}
/*
int main()
{
	Person<string, int>p("Tom", 22);
	printPerson2(p);
}*/