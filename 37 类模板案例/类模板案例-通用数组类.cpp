#include"myArray.hpp"
/*
��������: ʵ��һ��ͨ�õ������࣬Ҫ�����£�

���Զ��������������Լ��Զ����������͵����ݽ��д洢
�������е����ݴ洢������
���캯���п��Դ������������
�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
����ͨ���±�ķ�ʽ���������е�Ԫ��
���Ի�ȡ�����е�ǰԪ�ظ��������������
*/

void printIntArray(myArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//�����Զ�����������
class Person
{
public:
	Person() {};//���濪���¿ռ���������Զ�����Ĭ�Ϲ��캯������������Ҫд��ʵ��
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
		cout << "������" << parr[i].m_Name << " ���䣺 " << parr[i].m_Age << endl;
}


void test01()
{
	myArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;

	printIntArray(arr1);
	cout << "array1�Ĵ�С��" << arr1.getSize() << endl;
	cout << "array1��������" << arr1.getCapacity() << endl;
	cout << "--------------------------" << endl;

	myArray<int>arr2 = arr1;
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printIntArray(arr2);

	//βɾ
	arr2.Pop_Back();
	cout << "arr2βɾ��:" << endl;
	printIntArray(arr2);
	cout << "array2�Ĵ�С��" << arr2.getSize() << endl;
	cout << "array2��������" << arr2.getCapacity() << endl;
}

void test02()
{
	myArray<Person>arr(10);

	Person p1("�����", 100);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//arr[3] = p2;
	//cout<<arr[0].m_Name;
	//��ӡ����
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