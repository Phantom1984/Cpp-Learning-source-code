#include"vector.h"

/*
empty(); 判断容器是否为空
capacity(); 容器的容量
resize(int num);重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                      如果容器变短，则末尾超出容器长度的元素被删除
size(); 返回容器中元素的个数
push_back(ele); 尾部插入元素ele
pop_back(); 删除最后一个元素
insert(const_iterator pos, ele); 迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); 删除迭代器指向的元素
erase(const_iterator start, const_iterator end);删除迭代器从start到end之间的元素
clear(); 删除容器中所有元素
*/
/*
int main()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	if (v1.empty() == true)//为真，代表容器为空
		cout << "v1为空" << endl;
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量为:" << v1.capacity() << endl;
		cout << "v1的大小为:" << v1.size() << endl;
	}
	//重新指定大小
	v1.resize(15,100);//默认填充值为参数2
	printVector(v1);//如果重新指定比原来长，默认填充0

	v1.resize(5);
	printVector(v1);//如果重新指定比原来短，超出的部分会被删除

	//插入与删除
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	//清空
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}*/