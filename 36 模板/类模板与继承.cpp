#include"startup.h"

template<class T>
class Base
{
public:
	T m;
};

//lass Son :public Base //错误，必须要知道父类中T的类型，才能继承给子类
class Son :public Base<int>
{

};

//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的类型为：" << typeid(T1).name() << endl;
		cout << "T2的类型为：" << typeid(T2).name() << endl;
	}
	T1 obj;
};
/*
int main()
{
	Son2<int, char>s2;
}*/