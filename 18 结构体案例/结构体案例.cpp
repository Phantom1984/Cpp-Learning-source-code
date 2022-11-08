#include<iostream>
#include<string>
using namespace std;

/*案例描述*/
/*学生正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：*/
/*
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
学生的成员有姓名、考试分数、创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
最终打印出老师数据以及老师所带的学生数据
*/

struct student
{
	string name;
	int score;
};

struct teacher
{
	string name;
	struct student sArray[5];
};

//给老师和学生赋值的函数
void allocateSpace(struct teacher tArray[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArray[i].name = "Teacher";
		tArray[i].name += nameSeed[i];

		//通过循环给每名老师所带的学生赋值
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = "Student";
			tArray[i].sArray[j].name += nameSeed[j];

			int random = rand() % 61 + 40;//40-100的随机数
			tArray[i].sArray[j].score = random;
		}
		
	}
}

//打印所有信息
void printInfo(struct teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师姓名：" << tArray[i].name << endl;
		
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << tArray[i].sArray[j].name
				 << "考试分数：" << tArray[i].sArray[j].score << endl;	
		}
	}
}
int main()
{
	srand((int)time(0));
	struct teacher tArray[3];

	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);
	printInfo(tArray, len);
}