#include"static_member.h"
/*
��̬��Ա�����ڳ�Ա�����ͳ�Ա����ǰ���Ϲؼ���static����Ϊ��̬��Ա

��̬��Ա��Ϊ��

��̬��Ա����
���ж�����ͬһ������
�ڱ���׶η����ڴ�
���������������ʼ��
��̬��Ա����
���ж�����ͬһ������
��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
*/

int Person01::m_A = 10;
int Person01::m_B = 10;

void test01()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person01 p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person01 p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //����ͬһ������
	cout << "p2.m_A = " << p2.m_A << endl;

	//2��ͨ������
	cout << "m_A = " << Person01::m_A << endl;


	//cout << "m_B = " << Person::m_B << endl; //˽��Ȩ�޷��ʲ���
}

/*
int main()
{

	test01();

	system("pause");

	return 0;
}
*/