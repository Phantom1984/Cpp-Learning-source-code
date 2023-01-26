/*
友元的目的就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为 friend

友元的三种实现

全局函数做友元
类做友元
成员函数做友元
*/
#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend void goodGay(Building& building);
public:
	Building()
	{
		this->m_sittingRoom = "客厅";
		this->m_bedRoom = "卧室";
	}
	string m_sittingRoom;
private:
	string m_bedRoom;
};

void goodGay(Building &building)
{
	cout << "好基友正在访问：" << building.m_sittingRoom << endl;
	cout << "好基友正在访问：" << building.m_bedRoom << endl;
}
/*
int main()
{
	Building b;
	goodGay(b);
}
*/