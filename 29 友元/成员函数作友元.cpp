/*
���ڸ���Ŀ�в������Ѿ�����Ԫ��.cpp�ж��壬���л�����ض������⣬
����ʱ��Ҫ����Ԫ��.cpp����Ŀ���Ƴ�
*/
#include<iostream>
#include<string>
using namespace std;

class Building;
class Goodgay
{
public:
	Goodgay();
	void visit();//�ιۺ��� ����Building�е�����
private:
	//Building& building;  ���ڲ���ʹ�����ã���ʹ��ָ��
	Building* building;
};
class Building
{
	//���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend void Goodgay::visit();
public:
	Building();
	string m_sittingRoom;
private:
	string m_bedRoom;

};

//����ʵ�ֳ�Ա����
Building::Building()
{
	this->m_sittingRoom = "����";
	this->m_bedRoom = "����";
}
Goodgay::Goodgay()
{
	building = new Building;
}
void Goodgay::visit()
{
	cout << "�û������ڷ��ʣ�" << building->m_sittingRoom << endl;
	cout << "�û������ڷ��ʣ�" << building->m_bedRoom << endl;
}
/*
int main()
{
	Goodgay gg;
	gg.visit();
}
*/
