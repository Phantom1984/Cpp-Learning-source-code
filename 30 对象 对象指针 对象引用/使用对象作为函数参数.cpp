//ʹ�ö�����Ϊ��������
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A(int n)
	{
		num = n;
	}
	void setVal(int n)
	{
		num = n;
	}
	int getVal()
	{
		return num;
	}
private:
	int num;
};

void sqrt_it(A a)
{
	a.setVal(a.getVal()* a.getVal());
	cout << "�ں���sqrt_it�ڣ��βζ����obj2�����ݳ�Աt��ֵΪ��" << a.getVal() << endl;
}
/*
int main()
{
	A a(10);
	cout << "�ڵ���sqrt_it()����ǰ��ʵ�ζ����Ա������ֵΪ��" << a.getVal() << endl;
	sqrt_it(a);
	cout << "�ڵ���sqrt_it()������ʵ�ζ����Ա������ֵΪ��" << a.getVal() << endl;
}
*/