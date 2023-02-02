#pragma once
#include<identity.h>
#include<iostream>
#include<string>
#include<fstream>
#include<globalFile.h>
#include<vector>
#include<student.h>
#include<teacher.h>
#include<algorithm>
#include<computerRoom.h>
using namespace std;

//管理员
class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//菜单界面
	void Meau();
	//添加账号
	void addperson();
	//查看账号
	void showperson();
	//查看机房信息
	void showcomputer();
	//清空预约记录
	void cleanFile();

	//排除重复信息
	//初始化容器
	void initvector();
	//检测重复  参数1 :检测学号/职工号 参数2:检测类型
	bool checkrepeat(int id, int type);
	//学生容器
	vector<Student> vstu;
	//教师容器
	vector<Teacher> vtea;

	//机房信息
	vector<ComputerRoom>vcom;
};