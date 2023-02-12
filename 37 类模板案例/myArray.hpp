//�Լ���ͨ�õ�������
/*������ģ�壬���������ʵ����ͬһ���ļ��У��򽫸��ļ���׺��Ϊ.hpp*/
#pragma once
#include"startup.h"

template<class T>
class myArray
{
public:
	//�вι��� ���� ����
	myArray(int capacity)
	{
		//cout << "myArray���вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	//��������
	myArray(const myArray& arr)
	{
		//cout << "myArray�Ŀ����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//ǳ�������ظ��ͷ�����
		this->pAddress = new T[this->m_Capacity];//���
		//��arr�е����ݶ���������
		for (int i = 0; i < this->m_Size; i++)
			this->pAddress[i] = arr.pAddress[i];
	}
	//operator=��ֹǳ�������� a = b = c
	myArray& operator=(const myArray &arr)//��ֵ���������
	{
		//cout << "myArray�ĵȺŵ���" << endl;
		//���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for(int i=0;i<this->m_Size;i++)
			this->pAddress[i] = arr.pAddress[i];
		return *this;//����ʵ�����Ķ�����Ϊreturn this�򷵻ص��ǵ�ַ����Ϊ������ǰ������ ����& ���š�
	}
	//β�巨
	void Push_Back(const T& val)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			cout << "����������>_<" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;//������ĩβ��������
		this->m_Size++;//���������С
	}
	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}
	//ͨ���±���������е�Ԫ�� arr[0]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//���������С
	int getSize()
	{
		return this->m_Size;
	}
	//��������
	~myArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "myArray����������" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;//��ֹҰָ��
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:
	T* pAddress;//ָ��ָ��������ٵ���ʵ����
	int m_Capacity; //����
	int m_Size;   // ��С
};