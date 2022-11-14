#include<iostream>
#include<string>
using namespace std;
/*
设计立方体类(Cube)
求出立方体的面积和体积
分别用全局函数和成员函数判断两个立方体是否相等
*/
class Cube
{
	//行为
	// 获取立方体面积
public:
	void setL(float l)
	{
		m_L = l;
	}
	float getL()
	{
		return m_L;
	}
	void setW(float w)
	{
		m_W = w;
	}
	float getW()
	{
		return m_W;
	}
	void setH(float h)
	{
		m_H = h;
	}
	float getH()
	{
		return m_H;
	}
	float calculateS()
	{
		return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
	}
	float calculateV()
	{
		return m_L * m_W * m_H;
	}
	//利用成员函数判断是否相等
	bool isSameByClass(Cube &c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
			return true;
		else
			return false;
	}
private:
	//定义属性
	float m_L;
	float m_W;
	float m_H;
};

//利用全局函数判断 两个立方体是否相等
bool isSame(Cube &c1,Cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getH() && c2.getH() && c1.getW() == c2.getW())
		return true;
	else
		return false;
}

int main()
{
	Cube c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);

	cout << "c1的面积为：" << c1.calculateS() << endl;
	cout << "c1的体积为：" << c1.calculateV() << endl;

	Cube c2;
	c2.setH(10);
	c2.setL(10);
	c2.setW(10);
	//利用全局函数判断
	bool ret = isSame(c1, c2);
	if (ret)
		cout << "全局函数判断：c1和c2是相等的" << endl;
	else
		cout << "全局函数判断：c1和c2是不相等的" << endl;
	//利用成员函数判断
	ret = c1.isSameByClass(c2);
	if (ret)
		cout << "成员函数判断：c1和c2是相等的" << endl;
	else
		cout << "成员函数判断：c1和c2是不相等的" << endl;
}