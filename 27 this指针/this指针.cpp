#include<iostream>
#include<string>

using namespace std;
/*
this指针的用途：

当形参和成员变量同名时，可用this指针来区分
在类的非静态成员函数中返回对象本身，可使用return *this
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
	cout << "p1的年龄：" << p1.showAge() << endl;

	Person p2(10);
	p2.PersonaddAge(10).PersonaddAge(10).PersonaddAge(10);
	cout << "p2的年龄：" << p2.showAge() << endl;
}