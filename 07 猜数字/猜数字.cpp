#include<iostream>
#include<string>
using namespace std;

/*案例描述*/
/*系统随机生成一个1到100之间的数字，玩家进行猜测，
  如果猜错，提示玩家数字过大还是过小；
  如果猜对恭喜玩家胜利，并且退出游戏。*/

int main()
{
	int num = 0;
	float num_input = 0;
	int counter = 6;    //机会次数
	char ch = 'r';
	bool flag1 = 1;     //是否继续游戏
	bool flag2 = 0;
	bool pass = 0;      //是否通关
	/*生成随机数*/
	/*使用srand随机数种子保证每次程序运行时生成的随数不一样*/
	srand((int)time(0));
	num = rand() % 100; //生成0-99的随机数
	
	cout << "这是一个猜数游戏，请输入0-99的任意整数，你有6次机会" << endl;
	cout << "/*************************************************/" << endl;
	while (flag1)
	{
		while (counter)
		{
			cout << "请输入：";
			cin >> num_input;
			if ((num_input > 0 && num_input < 99) && num_input == (int)num_input)
			{
				if (num_input < num)
				{
					cout << "输入数字过小，试着调大一点。" << endl;
					cout << "" << endl;
					counter--;
					cout << "还有" << counter << "次机会" << endl;
				}
				if (num_input > num)
				{
					cout << "输入数字过大，试着调小一点。" << endl;
					cout << "" << endl;
					counter--;
					cout << "还有" << counter << "次机会" << endl;
				}
				if (num_input == num)
				{
					cout << "bingo！你猜对了！" << endl;
					pass = 1;
					counter = 0;
				}
			}
			else
			{
				cout << "请输入正确的数字！" << endl;
				cout << "/*****************/" << endl;
			}
		}
		flag2 = 1;
		if (pass == 0)
		{
			cout << "很遗憾，次数已用完 :(" << endl;
			cout << "最终结果为：" << num << endl;
			cout << "/**********************/" << endl;
		}
		while (flag2)
		{
			cout << "按下'r'重来，按下'e'结束游戏" << endl;
			cin >> ch;
			if (ch == 'r')
			{
				flag2 = 0;
				counter = 6;
				cout << "重新开始！" << endl;
				cout << "/*************************************************/" << endl;
			}
			else if (ch == 'e')
			{
				flag1 = 0;
				flag2 = 0;
				cout << "游戏结束." << endl;
			}
			else
				cout << "请输入正确的按钮，'y'代表重来，'e'代表退出." << endl;
		}
		
	}
}