#include"startup.h"

class Animal
{
public:
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	//��д����������ֵ���� �������������б���ȫ��ͬ
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

/*ִ��˵���ĺ���
��ַ��� �ڱ���׶�ȷ��������ַ
�����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���
*/

/*��̬��̬��������
//1.�м̳й�ϵ
//2.����Ҫ��д������麯��
*/
/*��̬ʹ�ã�
//����ָ�������ָ���������
*/
void doSpeak(Animal &animal) //Animal & animal = cat;
{
	animal.speak();
}

class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};
/*
int main()
{
	Cat cat;
	Dog dog;
	doSpeak(cat);
	doSpeak(dog);
}*/