#include"startup.h"

//��ͨʵ��ҳ��
/*
class Java
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
	void content()
	{
		cout << "JAVAѧ����Ƶ" << endl;
	}
};

class Python
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

class CPP
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

int main()
{
	cout << "Java������Ƶҳ�����£�" << endl;
	Java().header();
	Java().footer();
	Java().left();
	Java().footer();
	cout << "--------------------" << endl;

	cout << "Python������Ƶҳ�����£�" << endl;
	Python().header();
	Python().footer();
	Python().left();
	Python().footer();
	cout << "--------------------" << endl;

	cout << "C++������Ƶҳ�����£�" << endl;
	CPP().header();
	CPP().footer();
	CPP().left();
	CPP().footer();
	cout << "--------------------" << endl;
}
*/

//�̳�ʵ��ҳ��
//����ҳ����
class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
};
//Javaҳ��
class Java :public BasePage
{
public:
	void content()
	{
		cout << "JAVAѧ����Ƶ" << endl;
	}
};
//Pythonҳ��
class Python : public BasePage
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};
//C++ҳ��
class CPP : public BasePage
{
public:
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};
/*
int main()
{
	//Javaҳ��
	cout << "Java������Ƶҳ�����£� " << endl;
	Java().header();
	Java().footer();
	Java().left();
	Java().content();
	cout << "--------------------" << endl;

	//Pythonҳ��
	cout << "Python������Ƶҳ�����£� " << endl;
	Python().header();
	Python().footer();
	Python().left();
	Python().content();
	cout << "--------------------" << endl;

	//C++ҳ��
	cout << "C++������Ƶҳ�����£� " << endl;
	CPP().header();
	CPP().footer();
	CPP().left();
	CPP().content();
}
*/