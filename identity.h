#pragma once
#include<iostream>
using namespace std;

class Identity//��ݳ������
{
public:
	//�����˵�
	virtual void Meau() = 0;
	//�û���
	string m_name;
	//����
	string m_pwd;
};