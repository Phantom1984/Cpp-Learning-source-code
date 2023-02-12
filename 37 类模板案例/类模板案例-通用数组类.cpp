#include"myArray.hpp"
/*
案例描述: 实现一个通用的数组类，要求如下：

可以对内置数据类型以及自定义数据类型的数据进行存储
将数组中的数据存储到堆区
构造函数中可以传入数组的容量
提供对应的拷贝构造函数以及operator=防止浅拷贝问题
提供尾插法和尾删法对数组中的数据进行增加和删除
可以通过下标的方式访问数组中的元素
可以获取数组中当前元素个数和数组的容量
*/

void printIntArray(myArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试自定义数据类型
class Person
{
public:
	Person() {};//后面开辟新空间编译器会自动调用默认构造函数，所以这里要写空实现
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(myArray<Person>& parr)
{
	for (int i = 0; i < parr.getSize(); i++)
		cout << "姓名：" << parr[i].m_Name << " 年龄： " << parr[i].m_Age << endl;
}


void test01()
{
	myArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为：" << endl;

	printIntArray(arr1);
	cout << "array1的大小：" << arr1.getSize() << endl;
	cout << "array1的容量：" << arr1.getCapacity() << endl;
	cout << "--------------------------" << endl;

	myArray<int>arr2 = arr1;
	cout << "arr2的打印输出为：" << endl;
	printIntArray(arr2);

	//尾删
	arr2.Pop_Back();
	cout << "arr2尾删后:" << endl;
	printIntArray(arr2);
	cout << "array2的大小：" << arr2.getSize() << endl;
	cout << "array2的容量：" << arr2.getCapacity() << endl;
}

void test02()
{
	myArray<Person>arr(10);

	Person p1("孙悟空", 100);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//将数据插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//arr[3] = p2;
	//cout<<arr[0].m_Name;
	//打印数组
	printPersonArray(arr);
}

int main()
{
	//test01();
	test02();
	/*myArray<int>arr2(arr1);
	myArray<int>arr3(100);
	arr3 = arr1;*/
}