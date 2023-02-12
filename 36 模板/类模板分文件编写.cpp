#include"startup.h"
//#include"person.cpp"
/*
问题：
类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到

解决：
解决方式1：直接包含.cpp源文件
解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
*/

//template<class T1,class T2>
//class Person3
//{
//public:
//	Person3(T1 name, T2 age);
//	
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1,class T2>
//Person3<T1, T2>::Person3(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age - age;
//}

//template<class T1, class T2>
//void Person3<T1, T2>::showPerson()
//{
//	cout << "姓名：" << this->m_Name;
//	cout << "年龄：" << this->m_Age;
//}

/*int main()
{
    Person3<string, int>p3("Tom", 22);
	p3.showPerson();
}*/

