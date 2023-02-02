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

//��������Ӳ˵�
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
				cout << "ע���ɹ�!" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
}

//����ѧ���Ӳ˵�����
void studentmeau(Identity* &student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->Meau();
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//�����û�ѡ��

		if (select == 1)//����ԤԼ
		{
			stu->applyorder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showmyoreder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showallorder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancleorder();
		}
		else 
		{
			//ע����¼
			delete student;
			cout << "ע���ɹ�!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managerMeau(Identity* &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->Meau();

		//������ָ��תΪ����ָ��,���������е������ӿ�
		Manager* mana = (Manager*)manager;

		int select = 0;
		//����ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			mana->addperson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			mana->showperson();
		}
		else if (select == 3)//�鿴����
			
		{
			cout << "�鿴����" << endl;
			mana->showcomputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			mana->cleanFile();
		}
		else
		{
			delete manager;//���ٶ�������
			cout << "�����Ϣע���ɹ�" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}
}

//��¼����    �����ļ�����    �����������
void LoginIn(string filename, int type)
{
	//����ָ��,����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;
	char pp;//����������������ĵ��ֻ�ȡ

	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ
	{
		cout << "������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	while (pp = _getch())//�������ز���
	{
		if (pp == '\n' || pp == '\r')break;
		else if (pp == '\b') {    //�������˸��ʱ    
			pwd = pwd.substr(0, pwd.length() - 1);  //ɾ���ַ������һ���ַ�
			cout << "\b" << " " << "\b";  //  �����һ����ʾΪ�գ�����һ��
		}
		else {
			_putch('*');
			pwd += pp;
		}
		
	}
	cout << endl;
	if (type == 1)
	{
		//ѧ�������֤
		int fid;//���ļ��л�ȡ��id
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ�������֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				studentmeau(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fid;//���ļ��л�ȡ��id
		string fname;//���ļ��л�ȡ������
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ�����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ����Ӳ˵�
				teachermeau(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fname;//���ļ��л�ȡ������`
		string fpwd;//���ļ��л�ȡ������
		while (ifs >> fname && ifs >> fpwd)
		{
			//���û�������Ϣ���Ա�
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա�����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա����Ӳ˵�
				managerMeau(person);
				return;
			}
		}
	}
	
    cout << "�����֤ʧ��!" << endl;
	system("pause");
	system("cls");
};
int main()
{
	int select = 0;//���ڽ����û�ѡ��
	
	while(true)
	{
	cout << "*********************��ӭ��������ԤԼϵͳ*********************" << endl;
	cout << "��ѡ���������" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1.ѧ��                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2.��ʦ                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           3.����Ա              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0.�˳�                |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "��ѡ�������Ϣ:" << endl;

	cin >> select;//�����û�ѡ��

	switch (select)
	{
	case 1://ѧ��
		LoginIn(STUDENT_FILE, 1);
		break;
	case 2://��ʦ
		LoginIn(TEACHER_FILE, 2);
		break;
	case 3://����Ա
		LoginIn(ADMIN_FILE, 3);
		break;
	case 0://�˳�
		cout << "��ӭ��һ��ʹ��" << endl;
		system("pause");
		return 0;
		break;
	default://�������
		cout << "�û���������,������ѡ��!" << endl;
		system("pause");
		system("cls");
		break;
	}
	
    }
	system("pause");
	return 0;
}

