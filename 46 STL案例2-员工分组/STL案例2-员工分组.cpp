#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

/*
**********************��������********************
��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
�����10��Ա�����䲿�ź͹���
ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
�ֲ�����ʾԱ����Ϣ
*************************************************
**********************ʵ�ֲ���********************
����10��Ա�����ŵ�vector��
����vector������ȡ��ÿ��Ա���������������
����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
�ֲ�����ʾԱ����Ϣ
*************************************************
*/
class Worker  //����Ա����
{
public:
	Worker(string name)
	{
		this->m_Name = name;
	}
	string m_Name;
	string m_Department;  //����
	int m_Department_Id;  //����Id
	int m_Salary;         //����
};

//������䲿��:0---�߻���1---������2---�з�

void distribution(Worker& w)
{
	int i = rand() % 3;
	if (i == 0)
	{
		w.m_Department = "�߻�";
		w.m_Department_Id = 0;
		w.m_Salary = 8000;
	}
	if (i == 1)
	{
		w.m_Department = "����";
		w.m_Department_Id = 1;
		w.m_Salary = 10000;
	}	
	if (i == 2)
	{
		w.m_Department = "�з�";
		w.m_Department_Id = 2;
		w.m_Salary = 12000;
	}
}

//string department_distribution()
//{
//	string department;
//	int i = rand() % 3;
//	if (i == 0)
//		department = "�߻�";
//	else if (i == 1)
//		department = "����";
//	else if (i == 2)
//		department = "�з�";
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
		cout << "'0'---�߻���'1'---������'2'---�з���'3'---���в��ţ�'4'---�˳�" << endl;;
		cout << "����������鿴�Ĳ��ţ�";
		cin >> selection; cout << endl;
		if (selection == 0)
		{
			cout << "/----------------�߻�����-----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(0); mit != m.end(); mit++)
			{
				if (mit == m.find(1) || mit == m.find(2))
					break;
				cout << "������" << (*mit).second.m_Name << " " << "нˮ��" << (*mit).second.m_Salary << "Ԫ" << endl;
			}
			//break;
		}
		else if (selection == 1)
		{
			cout << "/----------------��������----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(1); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(2))
					break;
				cout << "������" << (*mit).second.m_Name << " " << "нˮ��" << (*mit).second.m_Salary << "Ԫ" << endl;
			}
			//break;
		}
		else if (selection == 2)
		{
			cout << "/----------------�з�����----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(2); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(1))
					break;
				cout << "������" << (*mit).second.m_Name << " " << "нˮ��" << (*mit).second.m_Salary << "Ԫ" << endl;
			}
			//break;
		}
		else if (selection == 3)
		{
			cout << "���в��ţ�" << endl;
			cout << "/----------------�߻�����-----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(0); mit != m.end(); mit++)
			{
				if (mit == m.find(1) || mit == m.find(2))
					break;
				cout << "������" << (*mit).second.m_Name << " " << "нˮ��" << (*mit).second.m_Salary << "Ԫ" << endl;
			}
			cout << "/----------------��������----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(1); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(2))
					break;
				cout << "������" << (*mit).second.m_Name << " " << "нˮ��" << (*mit).second.m_Salary << "Ԫ" << endl;
			}
			cout << "/----------------�з�����----------------/" << endl;
			for (multimap<int, Worker>::iterator mit = m.find(2); mit != m.end(); mit++)
			{
				if (mit == m.find(0) || mit == m.find(1))
					break;
				cout << "������" << (*mit).second.m_Name << " " << "нˮ��" << (*mit).second.m_Salary << "Ԫ" << endl;
			}
		}
		else if (selection == 4)
		{
			cout << "ϵͳ���˳���" << endl;
			break;
		}
		else
		{
			cout << "���������������ȷ�ı�ţ�" << endl;
			cout << endl;
		}
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	vector<Worker>v;
	multimap<int, Worker>m;
	Worker w1("Ա��A");	Worker w2("Ա��B");	Worker w3("Ա��C");	Worker w4("Ա��D");	Worker w5("Ա��E");
	Worker w6("Ա��F");	Worker w7("Ա��G");	Worker w8("Ա��H");	Worker w9("Ա��I");	Worker w10("Ա��J");

	v.push_back(w1); v.push_back(w2); v.push_back(w3); v.push_back(w4); v.push_back(w5);
	v.push_back(w6); v.push_back(w7); v.push_back(w8); v.push_back(w9); v.push_back(w10);
	
	
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		distribution((*it));
		m.insert(pair<int, Worker>((*it).m_Department_Id, (*it)));
		/*(*it).m_Department = department_distribution();
		if ((*it).m_Department == "�߻�")
			(*it).m_Department_Id = 0;
		if ((*it).m_Department == "����")
			(*it).m_Department_Id = 1;
		if ((*it).m_Department == "�з�")
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
	//for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)//���Դ���
	//	cout << (*it).m_Department_Id <<":" << (*it).m_Department << " " << (*it).m_Name << " " << (*it).m_Salary << endl;
}