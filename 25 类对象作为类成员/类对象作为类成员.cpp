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
		cout << "Phone构造" << endl;
	}
	~Phone()
	{
		cout << "Phone析构" << endl;
	}
};

class Person
{
public:
	string m_Name;
	Phone m_PhoneName;
	Person(string name, string pName) :m_Name(name), m_PhoneName(pName)  /*初始化列表方式初始化:Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}*/
	{
		cout << "Person构造" << endl;
	}
	~Person()
	{
		cout << "Person析构" << endl;
	}
	void playGame()
	{
		cout << m_Name << "使用" << m_PhoneName.m_phoneName << "手机" << endl;
	}
};

void test01()
{
	//当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
	Person p("张三", "华为mate50");
	p.playGame();
}

int main()
{
	test01();
}