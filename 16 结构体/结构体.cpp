#include<iostream>
#include<string>
using namespace std;

/*结构体属于用户自定义的数据类型，允许用户存储不同的数据类型*/
/*结构体创建变量的方式有三种*/
/*
1.struct 结构体名 变量名
2.struct 结构体名 变量名 = (成员1值，成员2值...)
3.定义结构体时顺便创建变量（不建议使用）
*/


//创建学生数据类型：学生包括（姓名，年龄，分数）
struct Student
{
	/*成员列表：姓名，年龄，分数的定义*/

	//姓名
	string name;
	//年龄
	int age;
	//分数
	int score;
}s3;

//结构体数组
//1.定义结构体
//2.创建结构体数组
//3.给结构体数组中的元素赋值
//4.遍历结构体数组

//通过学生类型创建具体学生
int main()
{
	//1.struct Student s1，定义结构体数据类型时，关键字struct可以省略，但是在定义结构体时，关键字不能省略
	//比如下面的struct Student s1，也可以写成Student s1;
	struct Student s1;
	//给s1属性赋值，通过.访问结构体变量中的属性
	s1.name = "张三";
	s1.age = 18;
	s1.score = 100;

	cout << "姓名：" << s1.name << "," << "年龄：" << s1.age << "," << "分数：" << s1.score << endl;

	//2.struct Student s2 = {...}
	struct Student s2 = { "李四",19,80 };
	cout << "姓名：" << s2.name << "," << "年龄：" << s2.age << "," << "分数：" << s2.score << endl;

	//3.struct
	s3.name = "王五";
	s3.age = 20;
	s3.score = 60;
	cout << "姓名：" << s3.name << "," << "年龄：" << s3.age << "," << "分数：" << s3.score << endl;
	
	//创建结构体数组
	struct Student stuArray[3] =
	{
		{"张三",18,100},
		{"李四",28,99},
		{"王五",38,66}
	};
	//给结构体数组中的元素赋值（修改）
	stuArray[2].name = "赵六";
	stuArray[2].age = 80;
	stuArray[2].score = 60;

	//遍历结构体数组
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << stuArray[i].name
			<< "年龄：" << stuArray[i].age
			<< "分数：" << stuArray[i].score << endl;
	}
	//结构体指针
	struct Student s = { "张三",18,100 };
	//通过指针指向结构体变量
	Student * p = &s;
	//通过指针访问结构体变量中的数据
	cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
}

