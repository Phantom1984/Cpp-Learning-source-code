#include<iostream>
#include<string>

using namespace std;
/*
thisָ�����;��

���βκͳ�Ա����ͬ��ʱ������thisָ��������
����ķǾ�̬��Ա�����з��ض�������ʹ��return *this
*/
class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}

	Person& PersonaddAge(Person p)
	{
		this->age += p.age;
		return *this;
	}
	int showAge()
	{
		return this->age;
	}
private:
	int age;
};

int main()
{
	Person p1(10);
	cout << "p1�����䣺" << p1.showAge() << endl;

	Person p2(10);
	p2.PersonaddAge(10).PersonaddAge(10).PersonaddAge(10);
	cout << "p2�����䣺" << p2.showAge() << endl;
}