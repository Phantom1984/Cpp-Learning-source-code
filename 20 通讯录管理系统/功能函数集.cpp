#include"function.h"
#include"user_list.h"

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks * abs)
{
	string name;
	bool flag;
	//添加联系人
	//1.添加姓名
	while (1)
	{
		cout << "请输入要添加的联系人姓名：";
		cin >> name;
		flag = IsName(name);
		if (flag == false)
		{
			cout << "联系人名字不能含有数字！" << endl;
			cout << "请正确输入要添加的联系人姓名：";
			cin >> name;
		}
		else
		{
			abs->personArray[abs->m_Size].m_Name = name;
			cout << "姓名录入成功！" << endl;
			break;
		}
	}
	//2.添加性别
	while (1)
	{
		cout << "请输入性别,数字1为男性，数字0为女性：";
		cin >> abs->personArray[abs->m_Size].m_Sex;
		if (abs->personArray[abs->m_Size].m_Sex == "1")
		{
			cout << "已录入性别：男" << endl;
			break;
		}
		else if (abs->personArray[abs->m_Size].m_Sex == "0")
		{
			cout << "已录入性别：女" << endl;
			break;
		}
		else
			cout << "请输入正确的性别代号！" << endl;
	}
	//3.添加年龄
	while (1)
	{
		cout << "请输入年龄：";
		cin >> abs->personArray[abs->m_Size].m_Age;
		flag = IsNum(abs->personArray[abs->m_Size].m_Age);
		if (flag == true)
		{
			if (str2num(abs->personArray[abs->m_Size].m_Age) > 120 || str2num(abs->personArray[abs->m_Size].m_Age) < 0)
				cout << "请输入正确的年龄区间，默认为0-120" << endl;
			else
			{
				cout << "已录入年龄：" << abs->personArray[abs->m_Size].m_Age << "岁" << endl;
				break;
			}
		}
		else
			cout << "年龄不能包含字符！" << endl;
	}
	//4.添加电话
	while (1)
	{
		cout << "请输入电话号码：";
		cin >> abs->personArray[abs->m_Size].m_Phone;
		flag = IsNum(abs->personArray[abs->m_Size].m_Phone);
		if (flag == false || (abs->personArray[abs->m_Size].m_Phone).size()>11)
		{
			cout << "请输入正确的号码！" << endl;
		}
		else
		{
			cout << "号码已录入！" << endl;
			break;
		}
	}
	//5.添加住址
		cout << "请输入家庭住址：";
		cin >> abs->personArray[abs->m_Size].m_Addr;
	//6.更新通讯录人数
		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏

}
//检查是否为正确的姓名输入
bool IsName(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int temp = (int)str[i];
		if (!(temp >= 48 && temp <= 57))//数字的asicc码区间
			continue;
		else
			return false;
	}
	return true;
}
//检查是否为数字
bool IsNum(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		int temp = (int)str[i];
		if (temp >= 48 && temp <= 57)//数字的asicc码区间
			continue;
		else
			return false;
	}
	return true;
}
//数字字符串转换为数字(有bug，数字位数超过10失效，且必须为int型整数)
int str2num(string str)
{
	int result = 0;
	int* arr = NULL;//要想办法获取输入字符串的长度，来定义数组的长度
	arr = new int[str.size()];
	//先将每个字符的数位乘以相应的10的乘方，分别存入数组，最后相加即可得到数字。
	for (int i = 0; i < str.size(); i++)
	{
		arr[i] = ((int)str[i]-48)*pow(10,str.size()-i-1);
	}
	//将数组中的元素累加
	for (int i = 0; i < str.size(); i++)
		result = result + arr[i];
	//返回转换后的结果
	return result;

	delete[] arr;
}
void showPerson(Addressbooks* abs) 
{
	if (abs->m_Size == 0)
		cout << "当前记录为空。" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" <<(abs->personArray[i].m_Sex == "1"?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
		system("pause");
		system("cls");
	}
}
int isExist(Addressbooks* abs, string name)//参数1 通讯录 参数2 对比姓名
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了，返回这个人对应的数组下标。
		}
	}
	return -1;//如果遍历结束都没找到，返回-1
}
void deletePerson(Addressbooks * abs)
{
	cout << "请输入删除联系人姓名：" << endl;
	string name;
	cin >> name;
	//ret == -1，查无此人
	//ret != -1，查到此人
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//进行删除操作
		/*实现逻辑*/
		/*
		采用“抹除”的方法，即把后面所有的数据向前挪动一位
		覆盖掉目标数据
		*/
		for (int i = ret; i < abs->m_Size; i++)
			abs->personArray[i] = abs->personArray[i + 1];
		abs->m_Size--;
		cout << "删除成功." << endl;
	}
	else
		cout << "查无此人" << endl;
}
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在于通讯录中
	int ret = isExist(abs, name);
	if (ret != -1)//找到联系人
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
		cout << "查无此人." << endl;
	system("pause");
	system("cls");
}
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	string choose;//选择是否修改
	cin >> name;
	bool flag;
	int ret = isExist(abs, name);

	if (ret != -1)//找到指定的联系人
	{
		//1.修改姓名
		cout << "当前姓名为：" << abs->personArray[ret].m_Name << ",是否修改？" << endl;
		cout << "y---修改,n---跳过" << endl;
		cin >> choose;
		while (1)
		{
			if (choose == "y" || choose == "n")
			{
				if (choose == "y")
				{
					while (1)//修改姓名
					{
						cout << "请输入修改后的联系人姓名：";
						cin >> abs->personArray[ret].m_Name;
						flag = IsName(abs->personArray[ret].m_Name);
						if (flag == false)
						{
							cout << "联系人名字不能含有数字！" << endl;
							cout << "请正确输入要修改的联系人姓名：";
							cin >> abs->personArray[ret].m_Name;
						}
						else
						{
							cout << "姓名修改成功！" << endl;
							break;
						}
					}
					break;
				}
				else if (choose == "n")
					break;
			}
			else
			{
				cout << "请输入正确的按钮！" << endl;
				cout << "y---修改,n---跳过" << endl;
				cin >> choose;
			}
		}

		//2.修改性别
		cout << "当前性别为：" << (abs->personArray[ret].m_Sex == "1" ? "男" : "女") << ",是否修改？" << endl;
		cout << "y---修改,n---跳过" << endl;
		cin >> choose;
		while (1)
		{
			if (choose == "y" || choose == "n")
			{
				if (choose == "y")
				{
					while (1)
					{
						cout << "请输入性别,数字1为男性，数字0为女性：";
						cin >> abs->personArray[ret].m_Sex;
						if (abs->personArray[ret].m_Sex == "1")
						{
							cout << "已修改性别：男" << endl;
							break;
						}
						else if (abs->personArray[ret].m_Sex == "0")
						{
							cout << "已修改性别：女" << endl;
							break;
						}
						else
							cout << "请输入正确的性别代号！" << endl;
					}
					break;
				}
				else if (choose == "n")
					break;
			}
			else
			{
				cout << "请输入正确的按钮！" << endl;
				cout << "y---修改,n---跳过" << endl;
				cin >> choose;
			}
		}

		//3.修改年龄
		cout << "当前年龄为：" << abs->personArray[ret].m_Age << ",是否修改？" << endl;
		cout << "y---修改,n---跳过" << endl;
		cin >> choose;
		while (1)
		{
			if (choose == "y" || choose == "n")
			{
				if (choose == "y")
				{
					while (1)
					{
						cout << "请输入修改后的年龄：";
						cin >> abs->personArray[ret].m_Age;
						flag = IsNum(abs->personArray[ret].m_Age);
						if (flag == true)
						{
							if (str2num(abs->personArray[ret].m_Age) > 120 || str2num(abs->personArray[ret].m_Age) < 0)
								cout << "请输入正确的年龄区间，默认为0-120" << endl;
							else
							{
								cout << "已录入年龄：" << abs->personArray[ret].m_Age << "岁" << endl;
								break;
							}
						}
						else
							cout << "年龄不能包含字符！" << endl;
					}
					break;
				}
				else if (choose == "n")
					break;
			}
			else
			{
				cout << "请输入正确的按钮！" << endl;
				cout << "y---修改,n---跳过" << endl;
				cin >> choose;
			}
		}

		//4.修改电话
		cout << "当前号码为：" << abs->personArray[ret].m_Phone << ",是否修改？" << endl;
		cout << "y---修改,n---跳过" << endl;
		cin >> choose;
		while (1)
		{
			if (choose == "y" || choose == "n")
			{
				if (choose == "y")
				{
					while (1)
					{
						cout << "请输入修改后的电话号码：";
						cin >> abs->personArray[ret].m_Phone;
						flag = IsNum(abs->personArray[ret].m_Phone);
						if (flag == false || (abs->personArray[ret].m_Phone).size() > 11)
						{
							cout << "请输入正确的号码！" << endl;
							break;
						}
						else
						{
							cout << "号码已修改！" << endl;
							break;
						}
					}
					break;
				}
				else if (choose == "n")
					break;
			}
			else
			{
				cout << "请输入正确的按钮！" << endl;
				cout << "y---修改,n---跳过" << endl;
				cin >> choose;
			}
		}
		
		//5.修改住址
		cout << "当前住址为：" << abs->personArray[ret].m_Age << ",是否修改？" << endl;
		cout << "y---修改,n---跳过" << endl;
		cin >> choose;
		while (1)
		{
			if (choose == "y" || choose == "n")
			{
				if (choose == "y")
				{
					cout << "请输入家庭住址：";
					cin >> abs->personArray[ret].m_Addr;
					break;
				}
				else if (choose == "n")
					break;
			}
			else
			{
				cout << "请输入正确的按钮！" << endl;
				cout << "y---修改,n---跳过" << endl;
				cin >> choose;
			}
		}

		cout << "修改成功！" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏
	}
	else//未找到
		cout << "查无此人." << endl;
		
}
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}