/*
��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա

��Ԫ�Ĺؼ���Ϊ friend

��Ԫ������ʵ��

ȫ�ֺ�������Ԫ
������Ԫ
��Ա��������Ԫ
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
		this->m_sittingRoom = "����";
		this->m_bedRoom = "����";
	}
	string m_sittingRoom;
private:
	string m_bedRoom;
};

void goodGay(Building &building)
{
	cout << "�û������ڷ��ʣ�" << building.m_sittingRoom << endl;
	cout << "�û������ڷ��ʣ�" << building.m_bedRoom << endl;
}
/*
int main()
{
	Building b;
	goodGay(b);
}
*/