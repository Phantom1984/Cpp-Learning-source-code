#include"startup.h"


//�����������ͺ���
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//�������������ͺ���
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T>//����һ��ģ�壬���߱���������Ĵ����н����ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
/*
int main()
{
	int a = 10;
	int b = 20;
	cout << "����ǰ��" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	// swapInt(a, b);
	//���ú���ģ�彻���������ַ�ʽ��ʹ��
	//1.�Զ������Ƶ�
	// mySwap(a, b);
	//2.��ʾָ������
	mySwap<int>(a, b);
	cout << "������" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	double c = 1.1;
	double d = 2.2;
	cout << "����ǰ��" << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
	swapDouble(c, d);
	cout << "������" << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
}*/