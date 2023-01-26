//使用对象指针作为函数参数
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A(int n)
	{
		num = n;
	}
	void setVal(int n)
	{
		num = n;
	}
	int getVal()
	{
		return num;
	}
private:
	int num;
};
/*
这里说一下.和->的区别：
->用于类类型的指针访问类成员，.用于对象访问成员，下面的*a表明类A是一个对象指针，用->访问成员
*/
void sqrt_it(A *a)
{
	a->setVal(a->getVal() * a->getVal());
	cout << "在函数sqrt_it内，形参对象的obj2的数据成员t的值为：" << a->getVal() << endl;
}
/*
int main()
{
	A a(10);
	cout << "在调用sqrt_it()函数前，实参对象成员变量的值为：" << a.getVal() << endl;
	sqrt_it(&a);
	cout << "在调用sqrt_it()函数后，实参对象成员变量的值为：" << a.getVal() << endl;
}
*/