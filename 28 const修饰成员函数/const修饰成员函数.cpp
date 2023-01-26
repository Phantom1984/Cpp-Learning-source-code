#include<iostream>
#include<string>
using namespace std;

/*
常函数：
成员函数后加const后我们称为这个函数为常函数
常函数内不可以修改成员属性
成员属性声明时加关键字mutable后，在常函数中依然可以修改

常对象：
声明对象前加const称该对象为常对象
常对象只能调用常函数
*/
class Person
{
public:
	//原先的this指针指向的对象是不可以修改的，但是可以修改指向的值
	//而在成员函数后加const，修饰的是this指针的指向，让指针指向的值也不可以修改
	void showPerson() const
	{
		//this->m_A = 100; 无法修改成员变量的值
		//this = NULL;       this不可修改指向
		this->m_B = 100;
	}
	void func()    //非 常函数
	{
		m_B = 200;
	}
	int m_A = 0;
	mutable int m_B = 1;      //mutable可以让const修饰的变量得到修改
};

int main()
{
	Person p1;
	const Person p2;         //声明一个常对象
	cout << "p1中B的初值：" << p1.m_B << endl;
	p1.showPerson();         //调用常函数，修改的成员变量必须有mutable修饰，否则报错
	cout << "p1修改后的B值：" << p1.m_B << endl;
	//p2.func();报错：常对象无法调用非 常函数，即使里面修改的变量有mutable修饰也不行
	//p2.m_A = 1;报错：m_A在常对象中无法修改
	p2.m_B = 100;  //mutable修饰的变量在常对象中可修改
}