#include"mymap.h"
/*
******************map��С�ͽ���*****************
size(); //����������Ԫ�ص���Ŀ
empty(); //�ж������Ƿ�Ϊ��
swap(st); //����������������

******************map�����ɾ��*****************
insert(elem); //�������в���Ԫ�ء�
clear(); //�������Ԫ��
erase(pos); //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end); //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(key); //ɾ��������ֵΪkey��Ԫ�ء�

******************map���Һ�ͳ��*****************
find(key); //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key); //ͳ��key��Ԫ�ظ���
*/

void testInsert_map()
{
	//����
	map<int, int> m;
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(1, 10));
	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(2, 20));
	//�����ֲ��뷽ʽ
	m.insert(map<int, int>::value_type(3, 30));
	//�����ֲ��뷽ʽ
	m[4] = 40;
	printMap(m);

	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//���
	m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}

void testSearch_map()
{
	//map<int, int>m;
	//m.insert(pair<int, int>(1, 10));
	//m.insert(pair<int, int>(2, 20));
	//m.insert(pair<int, int>(3, 30));

	multimap<int, int>m2;
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(4, 30));
	m2.insert(pair<int, int>(5, 30));
	m2.insert(pair<int, int>(3, 40));
	m2.insert(pair<int, int>(3, 50));
	for (multimap<int, int>::iterator pos = m2.find(3); pos != m2.end(); pos++)
	{
		if (pos == m2.find(4) || pos == m2.find(5))
			break;
		cout << "�ҵ���Ԫ�� key = " << (*pos).first << " value = " << (*pos).second << endl;
	}

	//����
	//map<int, int>::iterator pos = m.find(3);

	/*if (pos != m2.end())
		cout << "�ҵ���Ԫ�� key = " << (*pos).first << " value = " << (*pos).second << endl;
	else
		cout << "δ�ҵ�Ԫ��" << endl;*/

	//ͳ��
	int num = m2.count(3);
	cout << "num = " << num << endl;
}

int main()
{
	//testInsert_map();
	testSearch_map();
}