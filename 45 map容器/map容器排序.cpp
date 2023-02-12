#include"mymap.h"
/*
map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则

利用仿函数，可以改变排序规则
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