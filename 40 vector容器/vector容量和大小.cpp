#include"vector.h"

/*
empty(); �ж������Ƿ�Ϊ��
capacity(); ����������
resize(int num);����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
                ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
                      ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
size(); ����������Ԫ�صĸ���
push_back(ele); β������Ԫ��ele
pop_back(); ɾ�����һ��Ԫ��
insert(const_iterator pos, ele); ������ָ��λ��pos����Ԫ��ele
insert(const_iterator pos, int count,ele);������ָ��λ��pos����count��Ԫ��ele
erase(const_iterator pos); ɾ��������ָ���Ԫ��
erase(const_iterator start, const_iterator end);ɾ����������start��end֮���Ԫ��
clear(); ɾ������������Ԫ��
*/
/*
int main()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	if (v1.empty() == true)//Ϊ�棬��������Ϊ��
		cout << "v1Ϊ��" << endl;
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ:" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ:" << v1.size() << endl;
	}
	//����ָ����С
	v1.resize(15,100);//Ĭ�����ֵΪ����2
	printVector(v1);//�������ָ����ԭ������Ĭ�����0

	v1.resize(5);
	printVector(v1);//�������ָ����ԭ���̣������Ĳ��ֻᱻɾ��

	//������ɾ��
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//βɾ
	v1.pop_back();
	printVector(v1);
	//����
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//ɾ��
	v1.erase(v1.begin());
	printVector(v1);

	//���
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}*/