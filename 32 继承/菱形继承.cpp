#include"startup.h"
/*
���μ̳еĸ��
����������̳�ͬһ������
����ĳ����ͬʱ�̳�������������
���ּ̳б���Ϊ���μ̳У��ֽ���ʯ�̳�

1.��̳��˶�������ݣ���ͬ���̳��˶�������ݣ���������ʹ������ʱ���ͻ����������
2.������̳��Զ�������ݼ̳������ݣ���ʵ����Ӧ������������������ֻ��Ҫһ�ݾͿ���
*/

//������
class Animal
{
public:
	int m_Age;
};

//������̳У�������μ̳е�����
//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳�
//��ʱ�����ĸ���Animal��Ϊ�����
//����
class Sheep :virtual public Animal{};

//����
class Tuo :virtual public Animal{};

//������
class SheepTuo :public Sheep, public Tuo{};

int main()
{
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 22;
	//���������μ̳�ʱ������������ӵ����ͬ�����ݣ���Ҫ������������
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age =  " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;

	//�����������֪����ֻҪ��һ�ݾ��У����μ̳е������������ݣ������Դ�˷�
}