#include"startup.h"
/*
全局函数类内实现 - 直接在类内声明友元即可
全局函数类外实现 - 需要提前让编译器知道全局函数的存在
*/

//通过全局函数 打印Person信息
template<class T1, class T2>class Person;
template<class T1, class T2>void printPerson2(Person<T1, T2> &p);
/*类外实现非常麻烦，一般不建议使用*/

template<class T1,class T2>
class Person
{
	//全局函数，类内实现
	friend void printPerson(Person<T1,T2> &p)
	{
		cout << "全局函数的类内实现：" << endl;
		cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
	}
	//全局函数，类外实现
	//加空模板参数列表
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2> &p);
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//类外实现
template<class T1,class T2>
void printPerson2(Person<T1, T2> &p)
{
	cout << "全局函数的类外实现：" << endl;
	cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
}
/*
int main()
{
	Person<string, int>p("Tom", 22);
	printPerson2(p);
}*/