#include<iostream>
#include<vector>
#include<functional>  //�ڽ���������ͷ�ļ�
#include<algorithm>
using namespace std;
/*
����������ʵ�ֹ�ϵ�Ա�

�º���ԭ�ͣ�
template<class T> bool equal_to<T> //����
template<class T> bool not_equal_to<T> //������
template<class T> bool greater<T> //����
template<class T> bool greater_equal<T> //���ڵ���
template<class T> bool less<T> //С��
template<class T> bool less_equal<T> //С�ڵ���
*/

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//�Լ�ʵ�ַº���
	//sort(v.begin(), v.end(), MyCompare());
	//STL�ڽ��º���  ���ڷº���
	sort(v.begin(), v.end(), greater<int>());//�ǵü�()

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}