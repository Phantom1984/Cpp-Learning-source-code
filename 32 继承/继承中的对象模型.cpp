#include"startup.h"

//继承中的对象模型

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};
/*
int main()
{
	//父类中所有非静态成员属性都会被子类继承下去
	//父类中私有成员属性被编译器隐藏了，因此访问不到
	//有四个整型变量，所以大小为16
	cout << "size of Son:" << sizeof(Son) << endl;
}
*/