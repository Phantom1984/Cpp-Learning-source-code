#include<iostream>
#include<string>
#include"user_list.h"
using namespace std;

void showMenu();//菜单显示
void addPerson(Addressbooks* abs);//添加联系人，用指针才能真正写入数据
bool IsName(string str);//判断是否包含数字字符
bool IsNum(string str);//判断是否全为数字字符
int str2num(string str);//将数字字符串转换为数字(有bug，具体见实现部分)
void showPerson(Addressbooks* abs);//显示联系人
int isExist(Addressbooks* abs, string name);//检测联系人是否存在，如果存在，返回联系人所在数组的位置下标，不存在则返回-1
void deletePerson(Addressbooks* abs);//删除联系人
void findPerson(Addressbooks* abs);//查找联系人
void modifyPerson(Addressbooks* abs);//修改联系人
void clearPerson(Addressbooks* abs);//清空联系人