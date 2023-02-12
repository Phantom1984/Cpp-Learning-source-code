#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main()
{
	/*
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;*/
	
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
			case 0:
				wm.Exit_system();
				break;
			case 1:
				wm.add_Emp();
				break;
			case 2:
				wm.show_Emp();
				break;
			case 3:
				wm.del_Emp();
				break;
			case 4:
				wm.mod_Emp();
				break;
			case 5:
				wm.find_Emp();
				break;
			case 6:
				wm.sort_Emp();
				break;
			case 7:
				wm.clear_File();
				break;
		default:
			system("cls");
			break;
		}
	}
	
}