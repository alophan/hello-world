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

//����Ա
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	void Meau();
	//����˺�
	void addperson();
	//�鿴�˺�
	void showperson();
	//�鿴������Ϣ
	void showcomputer();
	//���ԤԼ��¼
	void cleanFile();

	//�ų��ظ���Ϣ
	//��ʼ������
	void initvector();
	//����ظ�  ����1 :���ѧ��/ְ���� ����2:�������
	bool checkrepeat(int id, int type);
	//ѧ������
	vector<Student> vstu;
	//��ʦ����
	vector<Teacher> vtea;

	//������Ϣ
	vector<ComputerRoom>vcom;
};