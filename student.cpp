#include<student.h>

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	//初始化
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		//将读取的信息放到容器
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::Meau()
{

	cout << "欢迎学生:" << this->m_name << "登录" << endl;
	cout << "\t\t-----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1.申请预约            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2.查看我的预约        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           3.查看所有预约        |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           4.取消预约            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0:注销登录            |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t-----------------------------------\n";
	cout << "请选择操作:" << endl;
}

void Student::applyorder()
{
	cout << "机房开放日期为周一至周五" << endl;
	cout << "请输入需要预约的时间:" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date=0;//日期
	int interval=0;//时间段
	int room = 0;//机房编号
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "该时间段不可预约!请重新选择预约时间!" << endl;
	}
	cout << "请输入申请预约的时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "该时间段不可预约!请重新选择预约时间!" << endl;
	}
	cout << "请选择机房" << endl;
	cout << vCom[0].m_comid << "号机房容量为:" << vCom[0].m_maxnum << endl;
	cout << vCom[1].m_comid << "号机房容量为:" << vCom[1].m_maxnum << endl;
	cout << vCom[2].m_comid << "号机房容量为:" << vCom[2].m_maxnum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "机房信息输入有误!请重新输入!" << endl;
	}
	cout << "预约成功!审核中!" << endl;

	//存入预约信息
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//string->int  c_str()转为c风格字符串
		if (this->m_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			cout << "预约日期:周" << of.m_orderData[i]["date"];
			cout << " 时间段:" << (of.m_orderData[i]["interval"]=="1"?"上午":"下午");
			cout << " 机房号:" << of.m_orderData[i]["roomid"];
			string status = " 状态:";
			if (of.m_orderData[i]["status"]=="1")
			{
				status += "审核中";
			}
			else if(of.m_orderData[i]["status"]=="2")
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
	}
	system("pause");
	system("cls");
}

void Student::showallorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		//string->int  c_str()转为c风格字符串
		cout << "i+1" << " .";
			cout << "预约日期:周" << of.m_orderData[i]["date"];
			cout << " 时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学号:" << of.m_orderData[i]["stuid"];
			cout << " 姓名" << of.m_orderData[i]["stuname"];
			cout << " 机房号:" << of.m_orderData[i]["roomid"];
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

void Student::cancleorder()
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者月预约成功的记录可以取消,请输入需要取消的记录:" << endl;
	vector<int>v;//存放在最大容器的下标编号
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//string->int  c_str()转为c风格字符串
		if (this->m_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ".";
				cout << "预约日期:周" << of.m_orderData[i]["date"];
				cout << " 时间段:" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房号:" << of.m_orderData[i]["roomid"];
				string status = " 状态:";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}	
				cout << status << endl;
			}		
		}
	}
	cout << "请输入取消的记录,0表示返回:" << endl;
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
				cout << "取消成功!" << endl;
				break;
			}
		}
		cout << "输入有误请重新输入!:" << endl;
	}
	system("pause");
	system("cls");
}
