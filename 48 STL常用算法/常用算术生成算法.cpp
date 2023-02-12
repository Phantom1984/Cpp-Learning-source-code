#include<iostream>
#include<algorithm>
#include<vector>
#include <numeric>   //����accumulate�㷨
using namespace std;

/*
**********�������������㷨**********
����ԭ�ͣ�
accumulate(iterator beg, iterator end, value1);   ��������Ԫ���ۼ��ܺ�
fill(iterator beg, iterator end, value2);         �����������Ԫ��

beg-��ʼ������; end-����������; value1-��ʼֵ; value2-����ֵ
*/

void test_accumulate()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) 
		v.push_back(i);

	int total = accumulate(v.begin(), v.end(), 0);

	cout << "total = " << total << endl;
}

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test_fill()
{

	vector<int> v;
	v.resize(10);
	//���
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}
/*
int main()
{
	//test_accumulate();
	test_fill();
}*/