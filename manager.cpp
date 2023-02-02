#include<manager.h>

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ������  ��ȡ�������ļ��� ѧ��/��ʦ��Ϣ
	this->initvector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "��������Ϊ:" << vcom.size() << endl;
}

void Manager::Meau()
{
		cout << "��ӭ����Ա:" << this->m_name << "��¼" << endl;
		cout << "\t\t-----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           1.����˺�            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           2.�鿴�˺�            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           3.�鿴����            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           4.���ԤԼ            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           0:ע����¼            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t-----------------------------------\n";
		cout << "��ѡ�����:" << endl;
}

void Manager::addperson()
{
	cout << "��������Ҫ��ӵ��˺�����:" << endl;
	cout << "1:���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string filename;//�����ļ���
	string tip;//��ʾid��
	string errortip;//��ʾ�ظ�

	ofstream ofs;//�ļ���������

	int select=0;
	cin >> select;//�����û�ѡ��

	if (select == 1)
	{
		//���ѧ��
		filename = STUDENT_FILE;
		tip = "������ѧ��:";
		errortip = "ѧ���ظ�,����������:";
	}
	else if(select == 2)
	{
		//�����ʦ
		filename = TEACHER_FILE;
		tip = "������ְ�����:";
		errortip = "ְ������ظ�,����������:";
	}
	else {
		cout << "�������,����������!" << endl;
		addperson();
	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(filename, ios::out | ios::app);

	int id;//ѧ��orְ����
	string name;
	string pwd;

	//���������Ϣ�Ƿ����ظ�
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret=checkrepeat(id, select);
		if (ret)//���ظ�
		{
			cout << errortip << endl;
		}
		else {
			break;
		}
	}

	cout << "����������:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	//���ļ������;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�!" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//���³�ʼ��,�����ظ����
	this->initvector();
}


//for_each������
//ѧ����Ϣ
void printstudent(Student& stu)
{
	cout << "ѧ��:" << stu.m_id << " ����:" << stu.m_name << endl;
}
//��ʦ��Ϣ
void printteacher(Teacher& stu)
{
	cout << "ְ����:" << stu.m_empid << " ����:" << stu.m_name << endl;
}
void Manager::showperson()
{
	cout << "��ѡ��鿴����:" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select=0;//�����û�ѡ��
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����:" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ����:" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");
}

void Manager::showcomputer()
{
	cout << "������Ϣ����:" << endl;
	for (vector<ComputerRoom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "�������:" << it->m_comid << " �����������:" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

void Manager::initvector()
{
	//ȷ������Ϊ��
	vstu.clear();
	vtea.clear();

	//��ȡ��Ϣ ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	Student s;
	while (ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_pwd)
	{
		vstu.push_back(s);
	}

	cout << "��ǰѧ������:" << vstu.size() << endl;
	ifs.close();

	//��ȡ��Ϣ ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);
	}

	cout << "��ǰ��ʦ����:" << vtea.size() << endl;
	ifs.close();
}

bool Manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (id == it->m_empid)
			{
				return true;
			}
		}
	}
	return false;
}
