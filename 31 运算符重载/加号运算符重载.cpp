#include"person.h"

/*
运算符重载：简单来说就是自定义运算符的作用，类似于python中用魔法方法修改运算符
这里要实现的目标是将两个成员变量相加

有两种方法：成员函数重载+号和全局函数重载+号
关键方法：operator+()
*/
/*
class Person
{
public:
	//1.成员函数重载+号
	Person operator+(Person& p)       
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
	
	int m_A;
	int m_B;
};
*/

//2.全局函数重载+号
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
/*
int main()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	Person p3 = p1 + p2;

	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
}
*/