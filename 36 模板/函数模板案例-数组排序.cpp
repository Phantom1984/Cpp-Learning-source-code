#include"startup.h"
/*
����������

���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
�������Ӵ�С�������㷨Ϊѡ������
�ֱ�����char�����int������в���
*/

/*
ʵ��ͨ�� �������������ĺ���
���򣺴Ӵ�С
�㷨��ѡ��
���ԣ�char���顢int����
*/

//��������ģ��
template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//�����㷨:ѡ������
template<class T>
void choice_Sort(T arr[], int len)
{
	//�������鳤��
	for (int i = 0; i < len; i++)
	{
		int max = i;//�϶����ֵ�±�
		for (int j = i + 1; j < len; j++)
		{
			//Ѱ�����ֵ������arr[max]����
			if (arr[max] < arr[j])
				max = j;
		}
		if (max != i)
			mySwap(arr[max], arr[i]);
	}
}

//�ṩ��ӡ����ģ��
template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << ",";
	cout << endl;
}
/*
int main()
{
	//����char����
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	choice_Sort(charArr, num);
	printArray(charArr, num);
}*/