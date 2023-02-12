#include"mymap.h"
/*
******************map大小和交换*****************
size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器

******************map插入和删除*****************
insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key); //删除容器中值为key的元素。

******************map查找和统计*****************
find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数
*/

void testInsert_map()
{
	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	m[4] = 40;
	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//清空
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
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}

	//查找
	//map<int, int>::iterator pos = m.find(3);

	/*if (pos != m2.end())
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	else
		cout << "未找到元素" << endl;*/

	//统计
	int num = m2.count(3);
	cout << "num = " << num << endl;
}

int main()
{
	//testInsert_map();
	testSearch_map();
}