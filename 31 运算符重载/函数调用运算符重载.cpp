#include"person.h"
/*
������������� () Ҳ��������
�º���û�й̶�д�����ǳ����
*/
//��ӡ�����
class MyPrint
{
public:
	//���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};
//�º���û�й̶�д�����ǳ����
//�ӷ���
class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
int main()
{
	//MyPrint myPrint;
	MyAdd myAdd;
	//myPrint("Hello,World!");//�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
	int ret = myAdd(100, 100);
	cout << "ret=" << ret << endl;
	//������������
	cout << MyAdd()(100, 100) << endl;
}