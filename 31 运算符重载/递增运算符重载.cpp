#include<iostream>
using namespace std;

/*
前置后置的区别：
前置，先运算再返回，返回的可能是对象，所以要引用；
后置，直接计算，返回的只能是值，所以不能引用
*/
class MyInteger
{
	//使用友元操作让我们可以访问私有数据类型
	friend ostream &operator<<(ostream &cout, MyInteger myint)/*
															  由于后置递增存在，其必须返回的是值，所以这里不能使用引用
															  若只有前置递增，可以使用引用
															  */
	{
		cout << myint.m_Num;
		return cout;
	}
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符
	MyInteger &operator++()
	{
		//先进行++运算
		m_Num++;
		//将自身返回
		return *this;
	}
	MyInteger operator++(int)  //这里的int代表占位参数，可以用于区分前置和后置递增
	{                          //后置递增必须返回值，前置递增则是引用
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//将记录结果返回
		return temp;
	}
private:
	int m_Num;
};
/*
int main()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
*/