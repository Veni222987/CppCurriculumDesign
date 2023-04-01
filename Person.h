#pragma once
#ifndef PERSON_H
#define PERSON_H
#include "Phone.h"
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
class Person
{
	//���ǻ���Person�����Լ�¼һЩ��������
protected:
	string type_p;
	
	string file_name;
	string name;
	int age;
	string gender;
	bool live_here;//���ڼ�¼������Ƿ�ס�ڵ��أ�������һָ�����ֱ����Out��Here������ȷ��
public:
	Phone phone;
	Person();

	string get_name();
	int get_age();
	string get_gender();
	string get_file_name();

	bool bool_here();
	virtual void show() = 0;
	virtual void set(istream& in) = 0;
	virtual int get_address_num() = 0;
	virtual void save_to_file(string file_name) = 0;

	string time_now();

	string get_type();
};

#endif




