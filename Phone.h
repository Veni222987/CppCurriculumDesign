#pragma once
#ifndef PHONE_H
#define PHONE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Phone
{
private:
	std::string phone_number;
	std::vector<string> message_box;
public:
	Phone();

	//��ȡ�������ֻ��ĵ绰����
	string get_phone_number();
	void set_phone_number(string number);

	//show_messages�����������ǰ��ֻ��ռ����е���Ϣȫ�����
	void show_messages();


	//�����ֻ�����֮������һ����Ϣ
	void put_message(string mes);
};
#endif

