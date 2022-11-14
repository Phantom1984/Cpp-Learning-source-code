#include<iostream>
#include<string>
using namespace std;
/*
点和圆的关系判断
点到圆心的距离==半径，点在圆上
点到圆心的距离>半径，点在圆外
点到圆心的距离<半径，点在圆内
点到圆心的距离公式：
d=sqrt((x1-x2)^2+(y1-y2)^2)
*/

class Circle
{
public:
	void setX(float x)
	{
		c_x = x;
	}
	void setY(float y)
	{
		c_y = y;
	}
	void setR(float r)
	{
		c_r = r;
	}
	void isInCircle(Circle &c,float x, float y)
	{
		float d;
		d = pow((pow((c.c_x - x), 2) + pow((c.c_y - y), 2)), 0.5);
		if (d > c.c_r)
			cout << "点在圆外。" << endl;
		else if (d == c.c_r)
			cout << "点在圆上。" << endl;
		else
			cout << "点在圆内。" << endl;
	}
private:
	//圆心坐标
	float c_x;//圆心x坐标
	float c_y;//圆心y坐标
	float c_r;//半径
};

int main()
{
	Circle c1;
	float x, y;
	float c_x, c_y, c_r;
	cout << "请输入点的x坐标："; cin >> x;
	cout << "请输入点的y坐标："; cin >> y;
	cout << "请输入圆心的x坐标："; cin >> c_x;
	c1.setX(c_x);
	cout << "请输入圆心的y坐标："; cin >> c_y;
	c1.setY(c_y);
	cout << "请输入圆的半径："; cin >> c_r;
	c1.setR(c_r);
	cout << "最终结果：";
	c1.isInCircle(c1, x, y);
}