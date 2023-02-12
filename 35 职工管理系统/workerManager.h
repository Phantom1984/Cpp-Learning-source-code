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

	//��¼ְ������
	int m_EmpNum = 0;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void add_Emp();//����ʹ������������Ѵ��ڵı��

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void show_Emp();

	//ɾ��ְ��
	void del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڣ�����ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void mod_Emp();//�����˻��bug����������ظ����Ḳ��������Ϣ

	//����ְ��
	void find_Emp();//��Ų���ֻ�ܲ鵽һ���˵���Ϣ

	//ְ������
	void sort_Emp();

	//����ļ�
	void clear_File();

	~WorkerManager();
};
