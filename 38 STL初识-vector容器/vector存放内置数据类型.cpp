#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector�������������������
void myPrint(int val)
{
	cout << val << " ";
}
/*
int main()
{
	//������һ��vector����������
	vector<int>v;
	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//ͨ�����������������е�����
	vector<int>::iterator itBegin = v.begin();//��ʼ��������ָ�������е�һ��Ԫ�ص�λ��
	vector<int>::iterator itEnd = v.end();//������������ָ�����������һ��Ԫ�ص���һ��λ��
	
    //��һ�ֱ�����ʽ
	cout << "��һ�ֱ�����ʽ��" << endl;
	while (itBegin != itEnd)
	{
		cout << *itBegin << " ";//��������ָ��ʹ��
		itBegin++;
	}
	cout << endl;
	cout << "*******************" << endl;

	//�ڶ��ֱ�����ʽ(����)
	cout << "�ڶ��ֱ�����ʽ��" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "*******************" << endl;

	//�����ֱ�����ʽ������STL�ṩ�ı����㷨
	cout << "�����ֱ�����ʽ��" << endl;
	for_each(v.begin(), v.end(), myPrint);
}*/