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

//ѧ����
class Student:public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	void Meau();
	//����ԤԼ
	void applyorder();
	//�鿴����ԤԼ
	void showmyoreder();
	//�鿴����ԤԼ
	void showallorder();
	//ȡ��ԤԼ
	void cancleorder();
	//ѧ��ѧ��
	int m_id;

	//��������
	vector<ComputerRoom>vCom;

};