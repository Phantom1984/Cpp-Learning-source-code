#include"mymap.h"
/*
map����Ĭ���������Ϊ ����keyֵ���� ��С��������������θı��������

���÷º��������Ըı��������
*/
class myCompare
{
public:
	bool operator()(int val1, int val2)const
	{
		return val1 > val2;
	}
};
/*
int main()
{
	map<int, int, myCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
		cout << "key=" << (*it).first << " value=" << (*it).second << endl;
	cout << endl;
}*/