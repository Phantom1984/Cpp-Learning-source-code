#include"person.h"
//ͨ������ʹ�ó�Ա���������������������Ϊ��ᵼ��cout��������ұ�
/*
���õ�Ŀ����Ϊ�����ⲿ����Ķ����ܹ���ʵ���޸ģ�
�����ǵ�����ͱ��ͷţ�����û������
*/
ostream &operator<<(ostream &cout, Person &p)//cout��ostream��Ķ���
{                                            
    cout << "m_A = " << p.m_A <<","<< "m_B = " << p.m_B;
	return cout;
}
/*
�����ķ������ͱ���ͺ�������һ�£���cout����ostream�࣬
���Ըú���������ostream��ͷ����������operator<<
*/
/*
int main()
{
	Person p;
	p.m_A = 10;
	p.m_B = 10;

	cout << p << endl;
}
*/