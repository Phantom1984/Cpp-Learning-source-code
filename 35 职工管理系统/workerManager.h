#pragma once
#include"startup.h"
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();

	void Show_Menu();

	void Exit_system();

	//记录职工人数
	int m_EmpNum = 0;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void add_Emp();//必须使函数不能添加已存在的编号

	//保存文件
	void save();

	//判断文件是否为空的标志
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void show_Emp();

	//删除职工
	void del_Emp();

	//判断职工是否存在，如果存在，返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void mod_Emp();//三个人会出bug，且若编号重复，会覆盖所有信息

	//查找职工
	void find_Emp();//编号查找只能查到一个人的信息

	//职工排序
	void sort_Emp();

	//清空文件
	void clear_File();

	~WorkerManager();
};
