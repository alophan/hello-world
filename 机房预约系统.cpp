#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<globalFile.h>
#include<identity.h>
#include<fstream>
#include<student.h>
#include<teacher.h>
#include<manager.h>
#include<conio.h>
using namespace std;

//进入教室子菜单
void teachermeau(Identity* &teacher)
{
	while (true)
	{
		teacher->Meau();
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		while (true)
		{
			if (select == 1) 
			{
				tea->showallorder();
			}
			if (select == 2)
			{
				tea->validorder();
			}
			else
			{
				delete teacher;
				cout << "注销成功!" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

//进入学生子菜单界面
void studentmeau(Identity* &student)
{
	while (true)
	{
		//调用学生子菜单
		student->Meau();
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//接收用户选择

		if (select == 1)//申请预约
		{
			stu->applyorder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showmyoreder();
		}
		else if (select == 3)//查看所有人预约
		{
			stu->showallorder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancleorder();
		}
		else 
		{
			//注销登录
			delete student;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMeau(Identity* &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->Meau();

		//将父类指针转为子类指针,调用子类中的其他接口
		Manager* mana = (Manager*)manager;

		int select = 0;
		//接收选择
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			mana->addperson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			mana->showperson();
		}
		else if (select == 3)//查看机房
			
		{
			cout << "查看机房" << endl;
			mana->showcomputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			mana->cleanFile();
		}
		else
		{
			delete manager;//销毁堆区对象
			cout << "身份信息注销成功" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}
}

//登录功能    操作文件名称    操作身份类型
void LoginIn(string filename, int type)
{
	//父类指针,用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;
	char pp;//用来隐藏密码操作的单字获取

	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入学号:" << endl;
		cin >> id;
	}
	else if (type == 2)//老师
	{
		cout << "请输入职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	while (pp = _getch())//密码隐藏操作
	{
		if (pp == '\n' || pp == '\r')break;
		else if (pp == '\b') {    //当输入退格符时    
			pwd = pwd.substr(0, pwd.length() - 1);  //删除字符串最后一个字符
			cout << "\b" << " " << "\b";  //  光标退一个显示为空，在退一格
		}
		else {
			_putch('*');
			pwd += pp;
		}
		
	}
	cout << endl;
	if (type == 1)
	{
		//学生身份验证
		int fid;//从文件中获取的id
		string fname;//从文件中获取的姓名
		string fpwd;//从文件中获取的密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入信息作对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生身份验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentmeau(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fid;//从文件中获取的id
		string fname;//从文件中获取的姓名
		string fpwd;//从文件中获取的密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入信息作对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师身份验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份子菜单
				teachermeau(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fname;//从文件中获取的姓名`
		string fpwd;//从文件中获取的密码
		while (ifs >> fname && ifs >> fpwd)
		{
			//与用户输入信息作对比
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员身份验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMeau(person);
				return;
			}
		}
	}
	
    cout << "身份验证失败!" << endl;
	system("pause");
	system("cls");
};
int main()
{
	int select = 0;//用于接收用户选择
	
	while(true)
	{
	cout << "*********************欢迎来到机房预约系统*********************" << endl;
	cout << "请选择您的身份" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1.学生                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2.老师                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           3.管理员              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0.退出                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "请选择身份信息:" << endl;

	cin >> select;//接收用户选择

	switch (select)
	{
	case 1://学生
		LoginIn(STUDENT_FILE, 1);
		break;
	case 2://老师
		LoginIn(TEACHER_FILE, 2);
		break;
	case 3://管理员
		LoginIn(ADMIN_FILE, 3);
		break;
	case 0://退出
		cout << "欢迎下一次使用" << endl;
		system("pause");
		return 0;
		break;
	default://输入错误
		cout << "用户输入有误,请重新选择!" << endl;
		system("pause");
		system("cls");
		break;
	}
	
    }
	system("pause");
	return 0;
}

