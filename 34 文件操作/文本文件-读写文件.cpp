#include"startup.h"
#include<fstream>

void writeFile()
{
	//1.����ͷ�ļ� fstream
	//2.����������
	ofstream ofs;
	//3.ָ���򿪷�ʽ
	ofs.open("text.txt", ios::out);
	//4.д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺22" << endl;
	//5.�ر��ļ�
	ofs.close();
}

void readFile()
{
	//1.����ͷ�ļ� fstream
	ifstream ifs;
	//2.����������
	ifs.open("text.txt", ios::in); 
	//3.���ļ��������ж��Ƿ�򿪳ɹ�
	
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//4.������
	/*��һ��
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/
	/*�ڶ���
	char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//������
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
	/*�����֣������ַ������ȡ�����Ƽ�
	char c;
	while ((c=ifs.get())!=EOF)//EOF:end of file���ļ�β����־
	{
		cout << c << endl;
	}*/
	//5.�ر��ļ�
	ifs.close();
}
/*
int main()
{
	//writeFile();
	readFile();
}
*/
/*
�ܽ᣺
�ļ������������ͷ�ļ� fstream
���ļ��������� ofstream ������fstream��
���ļ�ʱ����Ҫָ�������ļ���·�����Լ��򿪷�ʽ
����<<�������ļ���д����
������ϣ�Ҫ�ر��ļ�
*/