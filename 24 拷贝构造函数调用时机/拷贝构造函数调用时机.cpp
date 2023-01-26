#include<iostream>
#include<string>
using namespace std;

/*
C++�п������캯������ʱ��ͨ�����������
* ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
* ֵ���ݵķ�ʽ������������ֵ
* ��ֵ��ʽ���ؾֲ�����
*/

class Person
{
public:
	int mAge;
	Person()
	{
		cout << "�����޲ι��캯����" << endl;
		mAge = 0;
	}
	Person(int age)
	{
		cout << "�����вι��캯����" << endl;
		mAge = age;
	}
	Person(const Person& p)
	{
		cout << "�������캯����" << endl;
		mAge = p.mAge;
	}
	//�����������ͷ��ڴ�֮ǰ����
	~Person()
	{
		cout << "����������������" << endl;
	}
};

//1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person man(100);
	Person newman(man);
	Person newman2 = man;

	//Person newman3;
	//newman3 = man;  //���ǵ��ÿ������캯������ֵ����
}

//2.ֵ���ݵķ�ʽ������������ֵ
//�൱��Person p1 = p;
void doWork(Person p1){}
void test02()
{
	Person p; //�޲ι��캯��
	doWork(p);
}

//3. ��ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}

int main()
{
	//test01();
	//test02();
	test03();
}