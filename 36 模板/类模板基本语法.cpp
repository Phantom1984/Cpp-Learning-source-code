#include"startup.h"
/*类模板没有自动类型推导
类模板可以有默认参数*/
template<class NameType,class AgeType = int>//等号后面的int为默认参数
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void show_person()
	{
		cout << "姓名：" << this->m_Name << endl;
		cout << "年龄：" << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
/*
int main()
{
	Person<string, int>p1("孙悟空", 100);
	p1.show_person();
}*/