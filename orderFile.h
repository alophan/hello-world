#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<globalFile.h>
#include<string>
#include<fstream>

class OrderFile
{
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//��¼������ key-��¼������ value-�����¼�ļ�ֵ��Ӧ��Ϣ
	map<int, map<string, string>>m_orderData;
	//ԤԼ��¼����
	int m_size;
};