#pragma once//防止类型重定义
#define MAX 1000
#include<string>
using namespace std;
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男；2 女
	string m_Sex;
	//年龄
	string m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};