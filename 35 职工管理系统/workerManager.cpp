#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�������Ϊ��
	char ch;		//�ļ��еĵ����ַ�
	ifs >> ch;		//ifs��ȡ
	if (ifs.eof())  //���ch���ļ������ı�־�����ʼ��
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num; 
	this->m_EmpArray = new Worker * [this->m_EmpNum];//���ٿռ�
	this->init_Emp();                                //���ļ��е����ݣ���ŵ�������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id;
		cout << "ְ��������" << this->m_EmpArray[i]->m_Name;
		cout << "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

WorkerManager::~WorkerManager()
{

}

void WorkerManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ********" << endl;
	cout << "**********0.�˳��������************" << endl;
	cout << "**********1.����ְ����Ϣ************" << endl;
	cout << "**********2.��ʾְ����Ϣ************" << endl;
	cout << "**********3.ɾ����ְְ��************" << endl;
	cout << "**********4.�޸�ְ����Ϣ************" << endl;
	cout << "**********5.����ְ����Ϣ************" << endl;
	cout << "**********6.���ձ������************" << endl;
	cout << "**********7.��������ĵ�************" << endl;
	cout << "************************************" << endl;
}

void WorkerManager::Exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::add_Emp()
{
	cout << "��������ӵ�ְ��������";
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//������=ԭ������+��������
		//�����¿ռ�
		Worker** newSpace = new Worker* [newSize];
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			for (int j = 0; j < this->m_EmpNum + i; j++)
			{
				if (id == this->m_EmpArray[j]->m_Id)
				{
					cout << "�ñ���Ѵ��ڣ�����������" << endl;
					cin >> id;
				}
			}
			
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "����ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		
		//�ɹ���Ӻ󣬱��浽�ļ���
		this->save();
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
	}
	else
		cout << "��������" << endl;
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�

	//��ÿ���˵�����д�뵽�ļ���
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
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
		num++;                  //ͳ������
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
		if (dId == 1)//��ְͨ��
			worker = new Employee(id, name, dId);
		else if (dId == 2)//����
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	else
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	//�����������
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
			index = i;//�ҵ�ְ��
			break;
		}
	}
	return index;
}

void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	else
	{
		cout << "������Ҫɾ���ı�ţ�";
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)//˵��ְ������
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			this->m_EmpNum--;//���������м�¼������
			//ͬ�����µ��ļ�
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	else
	{
		cout << "�������޸�ְ���ı�ţ�";
		int id;
		cin >> id;

		if (this->IsExist(id) != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[this->IsExist(id)];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "��������������";
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

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
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų��ң�" << endl;
		cout << "2.��ְ���������ң�" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����Ų�
			int id;
			cout << "������Ҫ���ҵ�ְ����ţ�";
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "���޴��ˣ�" << endl;
		}
		else if (select == 2)
		{
			//��������
			string name;
			cout << "������Ҫ���ҵ�ְ����������";
			cin >> name;

			int flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
				cout << "���޴��ˣ�" << endl;
		}
		else
			cout << "����ѡ������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���������" << endl;
		cout << "2.��ְ����Ž���" << endl;

		int select = 0;//�����û�ѡ��
		cin >> select;
		if (select == 1 || select == 2)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				int minOrmax = i;//������Сֵ�����ֵ�±�
				for (int j = i + 1; j < this->m_EmpNum; j++)//�Ƚ�
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
				if (i != minOrmax)                          //����
				{
					Worker* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
					this->m_EmpArray[minOrmax] = temp;
				}
			}
			cout << "����ɹ��������Ľ��Ϊ��" << endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			cout << "��������" << endl;
			system("pause");
			system("cls");
		}
	}
}

void WorkerManager::clear_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ios::trunc�����ļ���ɾ���򴴽��ļ�
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}