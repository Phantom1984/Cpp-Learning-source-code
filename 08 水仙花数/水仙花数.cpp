#include<iostream>
#include<string>
using namespace std;
/*------------------------案例描述-------------------------*/
/*水仙花数是指一个3位数，它的每个位上的数字的3次幂之和等于它本身*/
/*---------------例如：1^3+5^3+3^3=153---------------------*/

int main()
{
	int i = 100;
	int a, b, c;
	int num = 0;
	while (i < 1000)
	{
		a = i / 100;        //提取百位
		b = i / 10 % 10;	//提取十位
		c = i % 10;			//提取个位
		num = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (num == i)
		{
			cout << "水仙花数：" << num << endl;
		}
		i++;
	}
}