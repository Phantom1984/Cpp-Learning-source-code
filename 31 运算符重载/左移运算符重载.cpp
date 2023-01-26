#include"person.h"
//通常不会使用成员函数重载左移运算符，因为这会导致cout在运算符右边
/*
引用的目的是为了让外部传入的对象能够切实被修改，
而不是调用完就被释放，那样没有意义
*/
ostream &operator<<(ostream &cout, Person &p)//cout是ostream类的对象
{                                            
    cout << "m_A = " << p.m_A <<","<< "m_B = " << p.m_B;
	return cout;
}
/*
函数的返回类型必须和函数类型一致，而cout属于ostream类，
所以该函数必须是ostream开头，并且引用operator<<
*/
/*
int main()
{
	Person p;
	p.m_A = 10;
	p.m_B = 10;

	cout << p << endl;
}
*/