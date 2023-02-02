#pragma once
#include<iostream>
using namespace std;

class Identity//身份抽象基类
{
public:
	//操作菜单
	virtual void Meau() = 0;
	//用户名
	string m_name;
	//密码
	string m_pwd;
};