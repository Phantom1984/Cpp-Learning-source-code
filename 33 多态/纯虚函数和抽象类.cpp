#include"startup.h"
/*
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
因此可以将虚函数改为纯虚函数

纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
当类中有了纯虚函数，这个类也称为抽象类

抽象类特点：
无法实例化对象
子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/

class Base
{
public:
	/*
	纯虚函数存在，该类为抽象类
	抽象类特点：
	1.无法实例化对象
	2.抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
	*/
	virtual void func() = 0;
};
class Son :public Base
{
public:
	void func()
	{
		cout << "Son-func函数调用" << endl;
	}
};
/*
int main()
{
	/*
	父类指针指向子类，调用子类函数
	*/
/*
	Base* base = new Son;
	base->func();
	delete base;
}
*/