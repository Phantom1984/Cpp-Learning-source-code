#include "static_member.h"

class Person02
{

public:

	//��̬��Ա�����ص㣺
	//1 ������һ������
	//2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����

	static void func()
	{
		cout << "func����" << endl;
		m_A = 100;
		//m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա����
	}

	static int m_A; //��̬��Ա����
	int m_B; // 
private:

	//��̬��Ա����Ҳ���з���Ȩ�޵�
	static void func2()
	{
		cout << "func2����" << endl;
	}
};
int Person02::m_A = 10;


void test02()
{
	//��̬��Ա�������ַ��ʷ�ʽ

	//1��ͨ������
	Person02 p1;
	p1.func();

	//2��ͨ������
	Person02::func();


	//Person::func2(); //˽��Ȩ�޷��ʲ���
}

int main() {

	test02();

	system("pause");

	return 0;
}
