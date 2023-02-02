#include<teacher.h>

Teacher::Teacher()
{
}

Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_empid = empid;
	this->m_name = name;
	this->m_pwd = pwd;
}

void Teacher::Meau()
{
	cout << "��ӭ��ʦ:" << this->m_name << "��¼" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1.�鿴����ԤԼ        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2.���ԤԼ            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0:ע����¼            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "��ѡ�����:" << endl;
}

void Teacher::showallorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << ".";
		cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
		cout << " ʱ���:" << (of.m_orderData[i]["interval"]=="1" ? "����" : "����");
		cout << " ѧ��:" << of.m_orderData[i]["stuid"];
		cout << " ����:" << of.m_orderData[i]["stuname"];
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

void Teacher::validorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵ļ�¼����:" << endl;
	vector<int>v;//���������������±���
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
	
			if (of.m_orderData[i]["status"] == "1" )
			{
				v.push_back(i);
				cout << index++ << ".";
				cout << "ԤԼ����:��" << of.m_orderData[i]["date"];
				cout << " ʱ���:" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ѧ��:" << of.m_orderData[i]["stuid"];
				cout << " ����:" << of.m_orderData[i]["stuname"];
				cout << " ������:" << of.m_orderData[i]["roomid"];
				string status = " ״̬:�����";
				cout << status << endl;
			}
		
	}
	cout << "��������Ҫ��˵�ԤԼ,0��ʾ����:" << endl;
	int select = 0;
	int ret;//����ԤԼ���
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��:" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if(ret==1)
				{ 
				of.m_orderData[v[select - 1]]["status"] = "2";//ͨ��
				}
				else
				{
				of.m_orderData[v[select - 1]]["status"] = "1";//��ͨ��
				}
				of.updateOrder();//����
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������~:" << endl;
	}
	system("pause");
	system("cls");
}
