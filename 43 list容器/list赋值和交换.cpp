#include"mylist.h"

/*����ԭ�ͣ�

assign(beg, end); //��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem); //��n��elem������ֵ������
list& operator=(const list &lst); //���صȺŲ�����
swap(lst); //��lst�뱾���Ԫ�ػ�����*/
/*
int main()
{
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	//��ֵ
	list<int>l2;
	l2 = l1;
	printList(l2);

	list<int>l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);

	list<int>l4;
	l4.assign(10, 100);
	printList(l4);

	//����
	list<int>l5;
	l5.assign(10, 100);
	cout << "����ǰ�� " << endl;
	printList(l1);
	printList(l5);

	cout << endl;

	l1.swap(l5);

	cout << "������ " << endl;
	printList(l1);
	printList(l5);
}*/