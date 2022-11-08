#include<iostream>
#include<string>

using namespace std;

/*案例描述*/
/*
设计一个英雄的结构体，包括成员姓名，年龄，性别；创建结构体数组，数组中存放5名英雄。
通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
*/

/*
* 思路：
* 1.设计英雄结构体
* 2.创建数组存放5名英雄
* 3.对数组进行排序，按照年龄进行升序排序
* 4.对排序后的结果打印输出
*/

struct hero
{
	string name;
	int age;
	string sex;
};

void bubbleSort(struct hero heroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			//如果j下标的元素年龄大于j+1下标的元素的年龄，交换两个元素
			if (heroArray[j].age > heroArray[j + 1].age)
			{
				struct hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

void printHero(struct hero heroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << heroArray[i].name 
			 << "年龄：" << heroArray[i].age 
			 << "性别：" << heroArray[i].sex
			 << endl;
	}
}

int main()
{
	hero heroArray[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	cout << "排序前的打印结果：" << endl;
	
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << heroArray[i].name << "年龄：" << heroArray[i].age << "性别：" << heroArray[i].sex
			 << endl;
	}
	cout<<"/*******************************/" << endl;
	cout << "排序后的打印结果：" << endl;
	bubbleSort(heroArray, len);
	printHero(heroArray, len);
}