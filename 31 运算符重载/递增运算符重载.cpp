#include<iostream>
using namespace std;

/*
ǰ�ú��õ�����
ǰ�ã��������ٷ��أ����صĿ����Ƕ�������Ҫ���ã�
���ã�ֱ�Ӽ��㣬���ص�ֻ����ֵ�����Բ�������
*/
class MyInteger
{
	//ʹ����Ԫ���������ǿ��Է���˽����������
	friend ostream &operator<<(ostream &cout, MyInteger myint)/*
															  ���ں��õ������ڣ�����뷵�ص���ֵ���������ﲻ��ʹ������
															  ��ֻ��ǰ�õ���������ʹ������
															  */
	{
		cout << myint.m_Num;
		return cout;
	}
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ��++�����
	MyInteger &operator++()
	{
		//�Ƚ���++����
		m_Num++;
		//��������
		return *this;
	}
	MyInteger operator++(int)  //�����int����ռλ������������������ǰ�úͺ��õ���
	{                          //���õ������뷵��ֵ��ǰ�õ�����������
		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		m_Num++;
		//����¼�������
		return temp;
	}
private:
	int m_Num;
};
/*
int main()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
*/