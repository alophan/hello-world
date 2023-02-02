#pragma once
#include<identity.h>
#include<iostream>
#include<string>
#include<vector>
#include<computerRoom.h>
#include<fstream>
#include<globalFile.h>
#include<orderFile.h>
#include<cstdlib>
using namespace std;

//学生类
class Student:public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);
	//菜单界面
	void Meau();
	//申请预约
	void applyorder();
	//查看自身预约
	void showmyoreder();
	//查看所有预约
	void showallorder();
	//取消预约
	void cancleorder();
	//学生学号
	int m_id;

	//机房容器
	vector<ComputerRoom>vCom;

};