#include"startup.h"
/*
问题：继承中同名的静态成员在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致

访问子类同名成员 直接访问即可
访问父类同名成员 需要加作用域
*/

class Base
{
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - func(int " << a << "调用)" << endl;
	}
	static int m_A;
};
int Base::m_A = 100;//类内声明，类外初始化

class Son :public Base
{
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};
int Son::m_A = 200;
/*
int main()
{
	//1.通过对象访问数据
	Son s;
	cout << "通过对象访问：" << endl;
	cout << "Son 下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;
	s.func();
	s.Base::func();

	//2.通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son 下的m_A = " << Son::m_A << endl;
	cout << "Base下的m_A = " << Son::Base::m_A << endl;
	Son::func();
	Son::Base::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son::Base::func(100);
}
*/