#include"startup.h"
/*
公用权限（public）：访问权限最高；派生类、外部函数均可以直接访问（无论是成员变量还是成员函数）。
保护权限（protect）：访问权限中间；该类内部函数、派生类都能访问，外部类、外部函数不能访问
私有权限（private）：访问权限最低；只能是该类内部函数互相调用，派生类、外部函数都不能访问。
*/
/*
公共继承
保护继承
私有继承
*/

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
	void func()
	{
		m_A = 10;//父类中的公共权限成员，到子类中依然是公共权限
		m_B = 10;//父类中的保护权限成员，到子类中依然是保护权限
		//m_C = 10;//父类中的私有权限成员，到子类无法访问
	}
};

class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
	void func()
	{
		m_A = 100;//父类中的公共权限成员，到子类中变为保护权限
		m_B = 100;//父类中的保护权限成员，到子类中仍是保护权限
		//m_C = 100;//父类中的私有权限成员，到子类无法访问
	}
};

class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
	void func()
	{
		m_A = 100;//父类中的公共权限成员，到子类中变为私有权限
		m_B = 100;//父类中的保护权限成员，到子类中仍是私有权限
		//m_C = 100;//父类中的私有权限成员，到子类无法访问
	}
};

class GrandSon3 :public Son3
{
public:
	void func()
	{
		/*
		m_A = 1000;//在Son3中这两个变量已经是私有属性，公共继承方式也无法访问
		m_B = 1000;
		*/
	}
};
/*
int main()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;//保护权限类外无法访问
	Son2 s2;
	//s2.m_A = 1000;//在Son2中，m_A已变为保护权限，无法访问
	Son3 s3;
	//s3.m_A = 1000;//在Son3中，m_A已变为私有权限，无法访问
}
*/