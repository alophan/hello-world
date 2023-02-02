#include<manager.h>

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化容器  获取到所有文件中 学生/老师信息
	this->initvector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房数量为:" << vcom.size() << endl;
}

void Manager::Meau()
{
		cout << "欢迎管理员:" << this->m_name << "登录" << endl;
		cout << "\t\t-----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           1.添加账号            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           2.查看账号            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           3.查看机房            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           4.清空预约            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|           0:注销登录            |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t-----------------------------------\n";
		cout << "请选择操作:" << endl;
}

void Manager::addperson()
{
	cout << "请输入需要添加的账号类型:" << endl;
	cout << "1:添加学生" << endl;
	cout << "2.添加老师" << endl;

	string filename;//操作文件名
	string tip;//提示id号
	string errortip;//提示重复

	ofstream ofs;//文件操作对象

	int select=0;
	cin >> select;//接收用户选择

	if (select == 1)
	{
		//添加学生
		filename = STUDENT_FILE;
		tip = "请输入学号:";
		errortip = "学号重复,请重新输入:";
	}
	else if(select == 2)
	{
		//添加老师
		filename = TEACHER_FILE;
		tip = "请输入职工编号:";
		errortip = "职工编号重复,请重新输入:";
	}
	else {
		cout << "输入错误,请重新输入!" << endl;
		addperson();
	}

	//利用追加的方式写文件
	ofs.open(filename, ios::out | ios::app);

	int id;//学号or职工号
	string name;
	string pwd;

	//检测输入信息是否有重复
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret=checkrepeat(id, select);
		if (ret)//有重复
		{
			cout << errortip << endl;
		}
		else {
			break;
		}
	}

	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	//向文件中添加;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功!" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//重新初始化,避免重复添加
	this->initvector();
}


//for_each遍历用
//学生信息
void printstudent(Student& stu)
{
	cout << "学号:" << stu.m_id << " 姓名:" << stu.m_name << endl;
}
//老师信息
void printteacher(Teacher& stu)
{
	cout << "职工号:" << stu.m_empid << " 姓名:" << stu.m_name << endl;
}
void Manager::showperson()
{
	cout << "请选择查看内容:" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select=0;//接收用户选择
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下:" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下:" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");
}

void Manager::showcomputer()
{
	cout << "机房信息如下:" << endl;
	for (vector<ComputerRoom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号:" << it->m_comid << " 机房最大容量:" << it->m_maxnum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initvector()
{
	//确保容器为空
	vstu.clear();
	vtea.clear();

	//读取信息 学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	Student s;
	while (ifs>>s.m_id&&ifs>>s.m_name&&ifs>>s.m_pwd)
	{
		vstu.push_back(s);
	}

	cout << "当前学生数量:" << vstu.size() << endl;
	ifs.close();

	//读取信息 老师
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);
	}

	cout << "当前老师数量:" << vtea.size() << endl;
	ifs.close();
}

bool Manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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
		//检测老师
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
