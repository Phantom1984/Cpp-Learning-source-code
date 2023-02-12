#include"person.h"

template<class T1,class T2>
Person3<T1, T2>::Person3(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person3<T1, T2>::showPerson()
{
	cout << "ÐÕÃû£º" << this->m_Name << endl;
	cout << "ÄêÁä£º" << this->m_Age << endl;
}

//int main()
//{
//	Person3<string, int>p3("Tom", 22);
//	p3.showPerson();
//}