#include<iostream>
#include<string>
using namespace std;

int main()
{
	int weight_1 = 0;
	int weight_2 = 0;
	int weight_3 = 0;

	cout << "请输入小猪A的体重：";
	cin >> weight_1;
	cout << "请输入小猪B的体重：";
	cin >> weight_2;
	cout << "请输入小猪C的体重：";
	cin >> weight_3;

	cout << "小猪A的体重：" << weight_1 << "," << "小猪B的体重：" << weight_2 << "," << "小猪C的体重：" << weight_3 << endl;

	//方法1
	if (weight_1 > weight_2 && weight_1 > weight_3)
		cout << "小猪A最重。" << endl;
	if (weight_2 > weight_1 && weight_2 > weight_3)
		cout << "小猪B最重。" << endl;
	if (weight_3 > weight_1 && weight_3 > weight_2)
		cout << "小猪C最重。" << endl;

	////方法2
	//if (weight_1 > weight_2)	//A比B重
	//{		
	//	if (weight_1 > weight_3)
	//		cout << "小猪A最重" << endl;
	//	else
	//		cout << "小猪C最重" << endl;
	//}
	//else                        //B比A重
	//{
	//	if (weight_2 > weight_3)
	//		cout << "小猪B最重" << endl;
	//	else
	//		cout << "小猪C最重" << endl;
	//}
		
}