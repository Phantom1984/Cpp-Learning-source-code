#include<iostream>
#include<string>
using namespace std;
/*
���
���غ������ò��������࣬����󳣳�Ϊ��������
��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ�зº���

���ʣ�
��������(�º���)��һ���࣬����һ������

��������ʹ��
����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
�������󳬳���ͨ�����ĸ����������������Լ���״̬
�������������Ϊ��������
*/

//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class MyAdd 
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};


//2����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;   //ʹ�ô���ͳ��
	}
	int count;
};

//3���������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}
/*
int main()
{
	//����һ
	cout << "����һ:" << endl;
	MyAdd myadd;
	cout << myadd(10, 20) << endl; cout << endl;

	//������
	cout << "������:" << endl;
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint���ô���Ϊ�� " << myPrint.count << endl;cout << endl;

	//������
	cout << "������:" << endl;
	MyPrint mp;
	doPrint(mp, "Hello C++");
}*/