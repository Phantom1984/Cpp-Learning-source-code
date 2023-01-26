/*
由于该项目中部分类已经在成员函数作友元.cpp中定义，运行会出现重定义问题，
运行时需要把成员函数作友元.cpp从项目中移除
*/

#include<iostream>
#include<string>
using namespace std;

class Building
{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class Goodgay;
public:
	Building();
	string m_sittingRoom;
private:
	string m_bedRoom;

};
class Goodgay
{
public:
	Goodgay();
	void visit();//参观函数 访问Building中的属性
private:
	//Building& building;  类内不能使用引用，得使用指针
	Building* building;
};
//类外实现成员函数
Building::Building()
{
	this->m_sittingRoom = "客厅";
	this->m_bedRoom = "卧室";
}
Goodgay::Goodgay()
{
	building = new Building;
}
void Goodgay::visit()
{
	cout << "好基友正在访问：" << building->m_sittingRoom << endl;
	cout << "好基友正在访问：" << building->m_bedRoom << endl;
}
/*
int main()
{
	Goodgay gg;
	gg.visit();
}
*/