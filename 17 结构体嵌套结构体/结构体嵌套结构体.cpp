#include<iostream>
#include<string>
using namespace std;

//结构体嵌套结构体
/*
作用：结构体中的成员可以是另一个结构体
例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体
*/

//定义学生结构体
struct Student
{
	string name;
	int age;
	int score;
};

//定义老师结构体
struct teacher
{
	int id;//教师编号
	string name;//教师姓名
	int age;//教师年龄
	struct Student stu;
};

int main()
{
	teacher t;
	t.id = 1000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小明";
	t.stu.age = 22;
	t.stu.score = 80;

	cout << "老师姓名：" << t.name << endl;
	cout << "老师编号：" << t.id << endl;
	cout << "老师年龄：" << t.age << endl;
	cout << "老师辅导的学生的姓名：" << t.stu.name << endl;
	cout << "老师辅导的学生的年龄：" << t.stu.age << endl;
	cout << "老师辅导的学生的考试分数：" << t.stu.score << endl;
}