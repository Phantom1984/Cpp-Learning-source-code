#include"startup.h"
/*��ģ��û���Զ������Ƶ�
��ģ�������Ĭ�ϲ���*/
template<class NameType,class AgeType = int>//�Ⱥź����intΪĬ�ϲ���
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void show_person()
	{
		cout << "������" << this->m_Name << endl;
		cout << "���䣺" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
/*
int main()
{
	Person<string, int>p1("�����", 100);
	p1.show_person();
}*/