#include<iostream>
#include<set>
using namespace std;
/*
��飺
����Ԫ�ض����ڲ���ʱ�Զ�������(����)

���ʣ�
set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�

set��multiset����
set���������������ظ���Ԫ��
multiset�������������ظ���Ԫ��
*/

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}
/*
int main()
{
	set<int>s1;//Ĭ�Ϲ���
	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	printSet(s1);
	//set����Ԫ��ʱ���Զ�����
	//�ظ�ֵ���ᱻ����

	set<int>s2(s1);
	printSet(s2);
}*/