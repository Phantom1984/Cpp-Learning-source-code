#include"startup.h"
/*
���⣺�̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�

��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��

��������ͬ����Ա ֱ�ӷ��ʼ���
���ʸ���ͬ����Ա ��Ҫ��������
*/

class Base
{
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - func(int " << a << "����)" << endl;
	}
	static int m_A;
};
int Base::m_A = 100;//���������������ʼ��

class Son :public Base
{
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};
int Son::m_A = 200;
/*
int main()
{
	//1.ͨ�������������
	Son s;
	cout << "ͨ��������ʣ�" << endl;
	cout << "Son �µ�m_A = " << s.m_A << endl;
	cout << "Base�µ�m_A = " << s.Base::m_A << endl;
	s.func();
	s.Base::func();

	//2.ͨ����������
	cout << "ͨ���������ʣ�" << endl;
	cout << "Son �µ�m_A = " << Son::m_A << endl;
	cout << "Base�µ�m_A = " << Son::Base::m_A << endl;
	Son::func();
	Son::Base::func();
	//����ͬ������������ص�����������ͬ����Ա��������Ҫ�������������
	Son::Base::func(100);
}
*/