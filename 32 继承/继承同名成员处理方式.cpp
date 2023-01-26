#include"startup.h"

//继承中同名成员处理

class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base - func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base - func(int " << a << "调用)" <<endl;
	}
	int m_A;
};

class Son :public Base
{
public://必须加public关键字，因为c++中类默认私有，不加则无法访问属性
	Son()
	{
		m_A = 200;
	}
	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
	int m_A;//这里的属性必须加，否则父类仍然会调用子类继承的属性
};
/*
int main()
{
	Son s;

	cout << "Son 下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;

	s.func();
	s.Base::func();

	//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
	//若要访问父类中被隐藏的同名成员函数，则需要加作用域
	s.Base::func(100);
}
*/
/*
总结：

子类对象可以直接访问到子类中同名成员
子类对象加作用域可以访问到父类同名成员
当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
*/