#include"startup.h"
#include<fstream>

class Person
{
public:
	char m_Name[64];//����
	int m_Age;//����
};

//�������ļ� д�ļ�
void write_binFile()
{
	//1.����ͷ�ļ�
	//2.����������
	ofstream ofs;
	//3.���ļ�
	ofs.open("person.txt", ios::out | ios::binary);
	//4.д�ļ�
	Person p = { "����",22 };
	ofs.write((const char*)&p, sizeof(Person));
	//5.�ر��ļ�
	ofs.close();
}
//�������ļ� ���ļ�
void read_binFile()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������ " << p.m_Name << endl;
	cout << "���䣺" << p.m_Age << endl;
}

int main()
{
	//write_binFile();
	read_binFile();
}