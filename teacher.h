#pragma once
#include<identity.h>
#include<iostream>
#include<string>
#include<orderFile.h>
#include<vector>
using namespace std;

//教师类
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empid, string name, string pwd);
	//菜单界面
	void Meau();
	//查看所有预约
	void showallorder();
	//审核预约
	void validorder();
	//职工号
	int m_empid;
};