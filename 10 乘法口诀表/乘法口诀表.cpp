#include<iostream>
#include<string>
using namespace std;

/*---------------实现9x9乘法口诀表-------------*/
int main()
{
	int i, j, num;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			num = i * j;
			cout << i << "x" << j << "=" << num;
			cout << ",";
		}
		cout << endl;
	}
}