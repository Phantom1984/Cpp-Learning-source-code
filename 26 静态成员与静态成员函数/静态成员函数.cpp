#include "static_member.h"

class Person02
{

public:

	//静态成员函数特点：
	//1 程序共享一个函数
	//2 静态成员函数只能访问静态成员变量

	static void func()
	{
		cout << "func调用" << endl;
		m_A = 100;
		//m_B = 100; //错误，不可以访问非静态成员变量
	}

	static int m_A; //静态成员变量
	int m_B; // 
private:

	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};
int Person02::m_A = 10;


void test02()
{
	//静态成员变量两种访问方式

	//1、通过对象
	Person02 p1;
	p1.func();

	//2、通过类名
	Person02::func();


	//Person::func2(); //私有权限访问不到
}

int main() {

	test02();

	system("pause");

	return 0;
}
