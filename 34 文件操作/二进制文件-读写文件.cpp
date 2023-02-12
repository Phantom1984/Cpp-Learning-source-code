#include"startup.h"
#include<fstream>

class Person
{
public:
	char m_Name[64];//姓名
	int m_Age;//年龄
};

//二进制文件 写文件
void write_binFile()
{
	//1.包含头文件
	//2.创建流对象
	ofstream ofs;
	//3.打开文件
	ofs.open("person.txt", ios::out | ios::binary);
	//4.写文件
	Person p = { "张三",22 };
	ofs.write((const char*)&p, sizeof(Person));
	//5.关闭文件
	ofs.close();
}
//二进制文件 读文件
void read_binFile()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名： " << p.m_Name << endl;
	cout << "年龄：" << p.m_Age << endl;
}

int main()
{
	//write_binFile();
	read_binFile();
}