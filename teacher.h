#pragma once
#include<identity.h>
#include<iostream>
#include<string>
#include<orderFile.h>
#include<vector>
using namespace std;

//��ʦ��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empid, string name, string pwd);
	//�˵�����
	void Meau();
	//�鿴����ԤԼ
	void showallorder();
	//���ԤԼ
	void validorder();
	//ְ����
	int m_empid;
};