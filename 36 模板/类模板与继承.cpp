#include"startup.h"

template<class T>
class Base
{
public:
	T m;
};

//lass Son :public Base //���󣬱���Ҫ֪��������T�����ͣ����ܼ̳и�����
class Son :public Base<int>
{

};

//��������ָ��������T���ͣ�����Ҳ��Ҫ����ģ��
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1������Ϊ��" << typeid(T1).name() << endl;
		cout << "T2������Ϊ��" << typeid(T2).name() << endl;
	}
	T1 obj;
};
/*
int main()
{
	Son2<int, char>s2;
}*/