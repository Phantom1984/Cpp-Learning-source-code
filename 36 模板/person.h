#pragma once
#include"startup.h"
template<class T1, class T2>
class Person3
{
public:
	Person3(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};