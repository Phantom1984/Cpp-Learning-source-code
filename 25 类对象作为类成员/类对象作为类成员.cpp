#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:
	string m_phoneName;
	Phone(string name)
	{
		m_phoneName = name;
		cout << "Phone����" << endl;
	}
	~Phone()
	{
		cout << "Phone����" << endl;
	}
};

class Person
{
public:
	string m_Name;
	Phone m_PhoneName;
	Person(string name, string pName) :m_Name(name), m_PhoneName(pName)  /*��ʼ���б�ʽ��ʼ��:Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}*/
	{
		cout << "Person����" << endl;
	}
	~Person()
	{
		cout << "Person����" << endl;
	}
	void playGame()
	{
		cout << m_Name << "ʹ��" << m_PhoneName.m_phoneName << "�ֻ�" << endl;
	}
};

void test01()
{
	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ �����Ա
	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴
	Person p("����", "��Ϊmate50");
	p.playGame();
}

int main()
{
	test01();
}