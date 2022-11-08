#include"function.h"
#include"user_list.h"//存放了联系人和通讯录的结构体

int main()
{
	
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0 ;// 创建用户输入的变量
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
			case 1:// 添加联系人
				addPerson(&abs);
				break;
			case 2:// 显示联系人
				showPerson(&abs);
				break;
			case 3:// 删除联系人
				deletePerson(&abs);
				break;
			case 4:// 查找联系人
				findPerson(&abs);
				break;
			case 5:// 修改联系人
				modifyPerson(&abs);
				break;
			case 6:// 清空联系人
				clearPerson(&abs);
				break;
			case 0:// 退出通讯录
				cout << "退出成功，欢迎下次使用！" << endl;
				return 0;//让switch函数直接返回0，退出循环
			default:cout << "请输入正确的按键！" << endl;
				break;
		}
	}
	
	/*测试代码*/
	/*
	string age;
	cin >> age;
	int f = str2num(age);
	cout << f << endl;
	cout << age.size() << endl;
	*/
}
/*
添加联系人实现步骤（上限为1000）
设计联系人结构体
设计通讯录结构体
main函数中创建通讯录
封装添加联系人函数
测试添加联系人功能
*/