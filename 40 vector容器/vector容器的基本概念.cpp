#include<iostream>
#include<vector>
using namespace std;
/*
vector数组可以动态扩展
动态扩展：并非在原空间后续接新空间，
而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间
*/
/*
void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}*/
/*
int main()
{
	vector<int>v1;//默认构造，无参构造
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());//起始，结束
	printVector(v2);

	//n个element方式构造
	vector<int>v3(10, 100);//第一个参数为个数，第二个参数为赋值
	printVector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}*/