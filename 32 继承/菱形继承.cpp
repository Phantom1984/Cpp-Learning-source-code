#include"startup.h"
/*
菱形继承的概念：
两个派生类继承同一个基类
又有某个类同时继承着两个派生类
这种继承被称为菱形继承，又叫钻石继承

1.羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性
2.草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以
*/

//动物类
class Animal
{
public:
	int m_Age;
};

//利用虚继承，解决菱形继承的问题
//继承前加virtual关键字后，变为虚继承
//此时公共的父类Animal称为虚基类
//羊类
class Sheep :virtual public Animal{};

//驼类
class Tuo :virtual public Animal{};

//羊驼类
class SheepTuo :public Sheep, public Tuo{};

int main()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 22;
	//当出现菱形继承时，有两个父类拥有相同的数据，需要加作用域区分
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age =  " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;

	//这份数据我们知道，只要有一份就行，菱形继承导致数据有两份，造成资源浪费
}