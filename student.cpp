#include<student.h>

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	//��ʼ��
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		//����ȡ����Ϣ�ŵ�����
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::Meau()
{

	cout << "��ӭѧ��:" << this->m_name << "��¼" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1.����ԤԼ            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2.�鿴�ҵ�ԤԼ        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           3.�鿴����ԤԼ        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           4.ȡ��ԤԼ            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0:ע����¼            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "��ѡ�����:" << endl;
}

void Student::applyorder()
{
	cout << "������������Ϊ��һ������" << endl;
	cout << "��������ҪԤԼ��ʱ��:" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date=0;//����
	int interval=0;//ʱ���
	int room = 0;//�������
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "��ʱ��β���ԤԼ!������ѡ��ԤԼʱ��!" << endl;
	}
	cout << "����������ԤԼ��ʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "��ʱ��β���ԤԼ!������ѡ��ԤԼʱ��!" << endl;
	}
	cout << "��ѡ�����" << endl;
	cout << vCom[0].m_comid << "�Ż�������Ϊ:" << vCom[0].m_maxnum << endl;
	cout << vCom[1].m_comid << "�Ż�������Ϊ:" << vCom[1].m_maxnum << endl;
	cout << vCom[2].m_comid << "�Ż�������Ϊ:" << vCom[2].m_maxnum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������Ϣ��������!����������!" << endl;
	}
	cout << "ԤԼ�ɹ�!�����!" << endl;

	//����ԤԼ��Ϣ
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuname:" << this->m_name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}

void Student::showmyoreder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//string->int  c_str()תΪc����ַ���
		if (this->m_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
			cout << " ʱ���:" << (of.m_orderData[i]["interval"]=="1"?"����":"����");
			cout << " ������:" << of.m_orderData[i]["roomid"];
			string status = " ״̬:";
			if (of.m_orderData[i]["status"]=="1")
			{
				status += "�����";
			}
			else if(of.m_orderData[i]["status"]=="2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showallorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		//string->int  c_str()תΪc����ַ���
		cout << "i+1" << " .";
			cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
			cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ��:" << of.m_orderData[i]["stuid"];
			cout << " ����" << of.m_orderData[i]["stuname"];
			cout << " ������:" << of.m_orderData[i]["roomid"];
			string status = " ״̬:";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		
	}
	system("pause");
	system("cls");
}

void Student::cancleorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�����ԤԼ�ɹ��ļ�¼����ȡ��,��������Ҫȡ���ļ�¼:" << endl;
	vector<int>v;//���������������±���
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//string->int  c_str()תΪc����ַ���
		if (this->m_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ".";
				cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
				cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������:" << of.m_orderData[i]["roomid"];
				string status = " ״̬:";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}	
				cout << status << endl;
			}		
		}
	}
	cout << "������ȡ���ļ�¼,0��ʾ����:" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select==0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"]="0";
				of.updateOrder();
				cout << "ȡ���ɹ�!" << endl;
				break;
			}
		}
		cout << "������������������!:" << endl;
	}
	system("pause");
	system("cls");
}
