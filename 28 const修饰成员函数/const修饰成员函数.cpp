#include<iostream>
#include<string>
using namespace std;

/*
��������
��Ա�������const�����ǳ�Ϊ�������Ϊ������
�������ڲ������޸ĳ�Ա����
��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

������
��������ǰ��const�Ƹö���Ϊ������
������ֻ�ܵ��ó�����
*/
class Person
{
public:
	//ԭ�ȵ�thisָ��ָ��Ķ����ǲ������޸ĵģ����ǿ����޸�ָ���ֵ
	//���ڳ�Ա�������const�����ε���thisָ���ָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const
	{
		//this->m_A = 100; �޷��޸ĳ�Ա������ֵ
		//this = NULL;       this�����޸�ָ��
		this->m_B = 100;
	}
	void func()    //�� ������
	{
		m_B = 200;
	}
	int m_A = 0;
	mutable int m_B = 1;      //mutable������const���εı����õ��޸�
};

int main()
{
	Person p1;
	const Person p2;         //����һ��������
	cout << "p1��B�ĳ�ֵ��" << p1.m_B << endl;
	p1.showPerson();         //���ó��������޸ĵĳ�Ա����������mutable���Σ����򱨴�
	cout << "p1�޸ĺ��Bֵ��" << p1.m_B << endl;
	//p2.func();�����������޷����÷� ����������ʹ�����޸ĵı�����mutable����Ҳ����
	//p2.m_A = 1;����m_A�ڳ��������޷��޸�
	p2.m_B = 100;  //mutable���εı����ڳ������п��޸�
}