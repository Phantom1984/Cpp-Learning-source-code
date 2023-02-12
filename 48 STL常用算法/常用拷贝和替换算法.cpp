#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
**********���ÿ������滻�㷨**********
����ԭ�ͣ�
copy(iterator beg, iterator end, iterator dest);          ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
replace(iterator beg, iterator end, oldvalue, newvalue);  �������ھ�Ԫ�� �滻�� ��Ԫ��
replace_if(iterator beg, iterator end, _pred, newvalue);  �������滻Ԫ�أ������������滻��ָ��Ԫ��
swap(container c1, container c2);                         ��������������Ԫ��

beg-��ʼ������; end-����������; _Pred-ν��; 
dest-Ŀ��������ʼ������; oldvalue-��Ԫ��; newvalue-��Ԫ��; 
newvalue-�滻����Ԫ��;  c1-����1; c2-����2
*/
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test_copy()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) 
		v1.push_back(i + 1);
	cout << "����ǰ������v1��";
	for_each(v1.begin(), v1.end(), myPrint());cout << endl;

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	cout << "�����������v2��";
	for_each(v2.begin(), v2.end(), myPrint());cout << endl;
}

void test_replace()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), myPrint());cout << endl;

	//�������е�20 �滻�� 2000
	cout << "�滻��" << endl;
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), myPrint());cout << endl;
}

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}

};

void test_replace_if()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), myPrint());cout << endl;

	//�������д��ڵ��ڵ�30 �滻�� 3000
	cout << "�滻��" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());cout << endl;
}

void test_swap()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "����ǰ�� " << endl;
	for_each(v1.begin(), v1.end(), myPrint());cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());cout << endl;

	cout << "������ " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());cout << endl;
}
/*
int main()
{
	//test_copy();
	//test_replace();
	//test_replace_if();
	test_swap();
}*/