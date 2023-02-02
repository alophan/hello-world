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
	cout << "欢迎教师:" << this->m_name << "登录" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1.查看所有预约        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2.审核预约            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0:注销登录            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "请选择操作:" << endl;
}

void Teacher::showallorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << ".";
		cout << "预约日期:周" << of.m_orderData[i]["date"];
		cout << " 时间段:" << (of.m_orderData[i]["interval"]=="1" ? "上午" : "下午");
		cout << " 学号:" << of.m_orderData[i]["stuid"];
		cout << " 姓名:" << of.m_orderData[i]["stuname"];
		string status = " 状态:";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的记录如下:" << endl;
	vector<int>v;//存放在最大容器的下标编号
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
	
			if (of.m_orderData[i]["status"] == "1" )
			{
				v.push_back(i);
				cout << index++ << ".";
				cout << "预约日期:周" << of.m_orderData[i]["date"];
				cout << " 时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 学号:" << of.m_orderData[i]["stuid"];
				cout << " 姓名:" << of.m_orderData[i]["stuname"];
				cout << " 机房号:" << of.m_orderData[i]["roomid"];
				string status = " 状态:审核中";
				cout << status << endl;
			}
		
	}
	cout << "请输入需要审核的预约,0表示返回:" << endl;
	int select = 0;
	int ret;//接收预约结果
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
				cout << "请输入审核结果:" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if(ret==1)
				{ 
				of.m_orderData[v[select - 1]]["status"] = "2";//通过
				}
				else
				{
				of.m_orderData[v[select - 1]]["status"] = "1";//不通过
				}
				of.updateOrder();//更新
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误请重新输入~:" << endl;
	}
	system("pause");
	system("cls");
}
