#include"mylist.h"

/*
reverse(); //��ת����
sort(); //��������
*/

bool myCompare(int val1, int val2)
{
	return val1 > val2;
}

//��ת������
//int main()
//{
//	list<int> L;
//	L.push_back(90);
//	L.push_back(30);
//	L.push_back(20);
//	L.push_back(70);
//	printList(L);
//
//	//��ת������Ԫ��
//	L.reverse();
//	printList(L);
//
//	//����
//	//���в�֧��������ʵ��������������������ñ�׼�㷨
//	//��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
//	//sort(L.begin(),L.end());//����
//	L.sort(); //Ĭ�ϵ�������� ��С����
//	printList(L);
//
//	L.sort(myCompare); //ָ�����򣬴Ӵ�С
//	/*���򷽷�2��
//	list<int>L2;
//    L.sort();
//	L2 = L;
//	L2.reverse();
//	L = L2;*/
//	printList(L);
//}