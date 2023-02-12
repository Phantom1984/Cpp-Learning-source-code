#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

/*
**********************案例描述********************
公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息
*************************************************
**********************实现步骤********************
创建10名员工，放到vector中
遍历vector容器，取出每个员工，进行随机分组
分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
分部门显示员工信息
*************************************************
*/
class Worker  //创建员工类
{
public:
	Worker(string name)
	{
		this->m_Name = name;
	}
	string m_Name;
	string m_Department;  //部门
	int m_Department_Id;  //部门Id
	int m_Salary;         //工资
};

//随机分配部门:0---策划；1---美术；2---研发

void distribution(Worker& w)
{
	int i = rand() % 3;
	if (i == 0)
	{
		w.m_Department = "策划";
		w.m_Department_Id = 0;
		w.m_Salary = 8000;
	}
	if (i == 1)
	{
		w.m_Department = "美术";
		w.m_Department_Id = 1;
		w.m_Salary = 10000;
	}	
	if (i == 2)
	{
		w.m_Department = "研发";
		w.m_Department_Id = 2;
		w.m_Salary = 12000;
	}
}

//string department_distribution()
//{
//	string department;
//	int i = rand() % 3;
//	if (i == 0)
//		department = "策划";
//	else if (i == 1)
//		department = "美术";
//	else if (i == 2)
//		department = "研发";
//	cout << "i="<< i << endl;
//	return department;
//}
//
//int salary_distribution()
//{
//	int salary;
//	int i = rand() % 3;
//	if (i == 0)
//		salary = 8000;
//	else if (i == 1)
//		salary = 10000;
//	else if (i == 2)
//		salary = 12000;
//	//cout << "j=" << i << endl;
//	return salary;
//}

void show_Worker(multimap<int, Worker>&m)
{
	while (1)
	{
		int selection;
		cout << "'0'---策划；'1'---美术；'2'---研发；'3'---所有部门；'4'---退出" << endl;;
		cout << "请输入你想查看的部门：";
		cin >> selection; cout << endl;
		if (selection == 0)
		{
			cout << "/----------------策划部门-----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(0); mit != m.end(); mit++)
			{
				if (mit == m.find(1) || mit == m.find(2))
					break;
				cout << "姓名：" << (*mit).second.m_Name << " " << "薪水：" << (*mit).second.m_Salary << "元" << endl;
			}
			//break;
		}
		else if (selection == 1)
		{
			cout << "/----------------美术部门----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(1); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(2))
					break;
				cout << "姓名：" << (*mit).second.m_Name << " " << "薪水：" << (*mit).second.m_Salary << "元" << endl;
			}
			//break;
		}
		else if (selection == 2)
		{
			cout << "/----------------研发部门----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(2); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(1))
					break;
				cout << "姓名：" << (*mit).second.m_Name << " " << "薪水：" << (*mit).second.m_Salary << "元" << endl;
			}
			//break;
		}
		else if (selection == 3)
		{
			cout << "所有部门：" << endl;
			cout << "/----------------策划部门-----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(0); mit != m.end(); mit++)
			{
				if (mit == m.find(1) || mit == m.find(2))
					break;
				cout << "姓名：" << (*mit).second.m_Name << " " << "薪水：" << (*mit).second.m_Salary << "元" << endl;
			}
			cout << "/----------------美术部门----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(1); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(2))
					break;
				cout << "姓名：" << (*mit).second.m_Name << " " << "薪水：" << (*mit).second.m_Salary << "元" << endl;
			}
			cout << "/----------------研发部门----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(2); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(1))
					break;
				cout << "姓名：" << (*mit).second.m_Name << " " << "薪水：" << (*mit).second.m_Salary << "元" << endl;
			}
		}
		else if (selection == 4)
		{
			cout << "系统已退出！" << endl;
			break;
		}
		else
		{
			cout << "输入错误，请输入正确的编号！" << endl;
			cout << endl;
		}
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	vector<Worker>v;
	multimap<int, Worker>m;
	Worker w1("员工A");	Worker w2("员工B");	Worker w3("员工C");	Worker w4("员工D");	Worker w5("员工E");
	Worker w6("员工F");	Worker w7("员工G");	Worker w8("员工H");	Worker w9("员工I");	Worker w10("员工J");

	v.push_back(w1); v.push_back(w2); v.push_back(w3); v.push_back(w4); v.push_back(w5);
	v.push_back(w6); v.push_back(w7); v.push_back(w8); v.push_back(w9); v.push_back(w10);
	
	
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		distribution((*it));
		m.insert(pair<int, Worker>((*it).m_Department_Id, (*it)));
		/*(*it).m_Department = department_distribution();
		if ((*it).m_Department == "策划")
			(*it).m_Department_Id = 0;
		if ((*it).m_Department == "美术")
			(*it).m_Department_Id = 1;
		if ((*it).m_Department == "研发")
			(*it).m_Department_Id = 2;
		(*it).m_Salary = salary_distribution();*/
	}
	//multimap<int, Worker>m;
	//m.insert(pair<int, Worker>(w1.m_Department_Id, w1)); m.insert(pair<int, Worker>(w2.m_Department_Id, w2));
	//m.insert(pair<int, Worker>(w3.m_Department_Id, w3)); m.insert(pair<int, Worker>(w4.m_Department_Id, w4));
	//m.insert(pair<int, Worker>(w5.m_Department_Id, w5)); m.insert(pair<int, Worker>(w6.m_Department_Id, w6));
	//m.insert(pair<int, Worker>(w7.m_Department_Id, w7)); m.insert(pair<int, Worker>(w8.m_Department_Id, w8));
	//m.insert(pair<int, Worker>(w9.m_Department_Id, w9)); m.insert(pair<int, Worker>(w10.m_Department_Id, w10));

	show_Worker(m);
	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)//测试代码
	//	cout << (*it).m_Department_Id <<":" << (*it).m_Department << " " << (*it).m_Name << " " << (*it).m_Salary << endl;
}