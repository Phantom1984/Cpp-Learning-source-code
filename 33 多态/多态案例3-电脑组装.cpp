#include"startup.h"
/*
����������
������Ҫ��ɲ���Ϊ CPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢��
��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����
�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľ�
����ʱ��װ��̨��ͬ�ĵ��Խ��й���
*/
//����ͬ�����
//����CPU��
class CPU
{
public:
	//������㺯��
	virtual void calculate() = 0;
};
//�����Կ���
class VideoCard
{
public:
	//������ʾ����
	virtual void display() = 0;
};
//�����ڴ�����
class Memory
{
public:
	//����洢����
	virtual void storage() = 0;
};
//���������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;//CPU�����ָ��
	VideoCard* m_vc;//�Կ����ָ��
	Memory* m_mem;//�ڴ������ָ��
};

//���峧��
//Intel����
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ濪ʼ�洢��" << endl;
	}
};

//���볧��
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ������" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo���ڴ濪ʼ�洢��" << endl;
	}
};

int main()
{
	//����ָ��ָ��������󡪡�������̬
	//��һ̨�������
	CPU* intelcpu = new IntelCPU;
	VideoCard* intelcard = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;
	cout << "��һ̨���Կ�ʼ������" << endl;
	Computer* computer1 = new Computer(intelcpu, intelcard, intelmem);
	computer1->work();
	delete computer1;

	cout << "-----------------------" << endl;
	cout << "�ڶ�̨���Կ�ʼ������" << endl;
	//�ڶ�̨�������
	//����ָ��ָ��������󡪡�������̬
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
}