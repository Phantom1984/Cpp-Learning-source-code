#include"deque.h"
/*
���ܣ�
˫�����飬���Զ�ͷ�˽��в���ɾ������

deque��vector����
vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻر�vector��
vector����Ԫ��ʱ���ٶȻ��deque��,��������ڲ�ʵ���й�
*/

void printDeque(const deque<int>& d)//const�������const_iterator��ֻ��Ȩ��
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
		cout << *it << " ";
	cout << endl;
}
/*
int main()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);
	//��vector���񣬲��ٶ�׸���������ľ�ȥ���ĵ�
}*/