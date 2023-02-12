//自己的通用的数组类
/*对于类模板，如果声明和实现在同一个文件中，则将该文件后缀改为.hpp*/
#pragma once
#include"startup.h"

template<class T>
class myArray
{
public:
	//有参构造 参数 容量
	myArray(int capacity)
	{
		//cout << "myArray的有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	myArray(const myArray& arr)
	{
		//cout << "myArray的拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//浅拷贝，重复释放问题
		this->pAddress = new T[this->m_Capacity];//深拷贝
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
			this->pAddress[i] = arr.pAddress[i];
	}
	//operator=防止浅拷贝问题 a = b = c
	myArray& operator=(const myArray &arr)//赋值运算符重载
	{
		//cout << "myArray的等号调用" << endl;
		//先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for(int i=0;i<this->m_Size;i++)
			this->pAddress[i] = arr.pAddress[i];
		return *this;//返回实例化的对象，若为return this则返回的是地址，因为我们在前面用了 引用& 符号。
	}
	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			cout << "容量已满！>_<" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新数组大小
	}
	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}
	//通过下标访问数组中的元素 arr[0]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
	//析构函数
	~myArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "myArray的析构调用" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;//防止野指针
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity; //容量
	int m_Size;   // 大小
};