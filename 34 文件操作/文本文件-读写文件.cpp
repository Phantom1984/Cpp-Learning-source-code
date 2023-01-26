#include"startup.h"
#include<fstream>

void writeFile()
{
	//1.包含头文件 fstream
	//2.创建流对象
	ofstream ofs;
	//3.指定打开方式
	ofs.open("text.txt", ios::out);
	//4.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：22" << endl;
	//5.关闭文件
	ofs.close();
}

void readFile()
{
	//1.包含头文件 fstream
	ifstream ifs;
	//2.创建流对象
	ifs.open("test.txt", ios::in);
	//3.打开文件，并且判断是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4.读数据
	/*第一种*/
	char buf[1024] = { 0 };
	while (ifs >> buf)//将ifs中的数据存入buf中
	{
		cout << buf << endl;
	}
	//5.关闭文件
	ifs.close();
}

int main()
{
	readFile();
}

/*
总结：
文件操作必须包含头文件 fstream
读文件可以利用 ofstream ，或者fstream类
打开文件时候需要指定操作文件的路径，以及打开方式
利用<<可以向文件中写数据
操作完毕，要关闭文件
*/