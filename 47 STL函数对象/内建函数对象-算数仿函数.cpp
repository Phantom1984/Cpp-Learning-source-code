#include<iostream>
#include<functional>  //内建函数对象头文件
using namespace std;
/*
功能描述：
实现四则运算
其中negate是一元运算，其他都是二元运算

仿函数原型：
template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数
*/

/*
int main()
{
	//negate一元仿函数 取反仿函数
	negate<int>n;
	cout << n(50) << endl;

	//plus二元仿函数 加法
	plus<int>p;
	cout << p(1,2) << endl;
}*/