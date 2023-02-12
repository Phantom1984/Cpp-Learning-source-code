#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，但数据为空
	char ch;		//文件中的单个字符
	ifs >> ch;		//ifs读取
	if (ifs.eof())  //如果ch是文件结束的标志，则初始化
	{
		//文件为空
		cout << "文件为空！" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num; 
	this->m_EmpArray = new Worker * [this->m_EmpNum];//开辟空间
	this->init_Emp();                                //将文件中的数据，存放到数组中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id;
		cout << "职工姓名：" << this->m_EmpArray[i]->m_Name;
		cout << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

WorkerManager::~WorkerManager()
{

}

void WorkerManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "********欢迎使用职工管理系统********" << endl;
	cout << "**********0.退出管理程序************" << endl;
	cout << "**********1.增加职工信息************" << endl;
	cout << "**********2.显示职工信息************" << endl;
	cout << "**********3.删除离职职工************" << endl;
	cout << "**********4.修改职工信息************" << endl;
	cout << "**********5.查找职工信息************" << endl;
	cout << "**********6.按照编号排序************" << endl;
	cout << "**********7.清空所有文档************" << endl;
	cout << "************************************" << endl;
}

void WorkerManager::Exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::add_Emp()
{
	cout << "请输入添加的职工人数：";
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新人数=原有人数+新增人数
		//开辟新空间
		Worker** newSpace = new Worker* [newSize];
		//将原来空间下的数据拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			for (int j = 0; j < this->m_EmpNum + i; j++)
			{
				if (id == this->m_EmpArray[j]->m_Id)
				{
					cout << "该编号已存在！请重新输入" << endl;
					cin >> id;
				}
			}
			
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		
		//成功添加后，保存到文件中
		this->save();
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;
	}
	else
		cout << "数据有误！" << endl;
	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " " << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
		num++;                  //统计人数
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id; string name;int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通职工
			worker = new Employee(id, name, dId);
		else if (dId == 2)//经理
			worker = new Manager(id, name, dId);
		else
			worker = new Boss(id, name, dId);
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::show_Emp()
{
	ifstream ifs;
	//判断文件是否为空
	if (this->m_FileIsEmpty)
		cout << "文件不存在或记录为空！" << endl;
	else
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	//按任意键清屏
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;//找到职工
			break;
		}
	}
	return index;
}

void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "文件不存在或记录为空！" << endl;
	else
	{
		cout << "请输入要删除的编号：";
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//说明职工存在
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			this->m_EmpNum--;//更新数组中记录的人数
			//同步更新到文件
			this->save();
			cout << "删除成功！" << endl;
		}
		else
			cout << "删除失败，未找到该职工！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "文件不存在或记录为空！" << endl;
	else
	{
		cout << "请输入修改职工的编号：";
		int id;
		cin >> id;

		if (this->IsExist(id) != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArray[this->IsExist(id)];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：";
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[this->IsExist(id)] = worker;
			cout << "修改成功！" << endl;
			this->save();
		}
		else
			cout << "修改失败，查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "文件不存在或记录为空！" << endl;
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找：" << endl;
		cout << "2.按职工姓名查找：" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按编号查
			int id;
			cout << "请输入要查找的职工编号：";
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "查无此人！" << endl;
		}
		else if (select == 2)
		{
			//按姓名查
			string name;
			cout << "请输入要查找的职工的姓名：";
			cin >> name;

			int flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！该职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
				cout << "查无此人！" << endl;
		}
		else
			cout << "输入选项有误！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号升序：" << endl;
		cout << "2.按职工编号降序：" << endl;

		int select = 0;//接收用户选择
		cin >> select;
		if (select == 1 || select == 2)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int minOrmax = i;//声明最小值或最大值下标
				for (int j = i + 1; j < this->m_EmpNum; j++)//比较
				{
					if (select == 1)
					{
						if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
							minOrmax = j;
					}
					else if (select == 2)
					{
						if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
							minOrmax = j;
					}
				}
				if (i != minOrmax)                          //交换
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
					this->m_EmpArray[minOrmax] = temp;
				}
			}
			cout << "排序成功！排序后的结果为：" << endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			cout << "输入有误！" << endl;
			system("pause");
			system("cls");
		}
	}
}

void WorkerManager::clear_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ios::trunc，若文件被删除则创建文件
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}