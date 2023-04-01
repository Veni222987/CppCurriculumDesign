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

	//获取和设置手机的电话号码
	string get_phone_number();
	void set_phone_number(string number);

	//show_messages函数的作用是把手机收件箱中的信息全部输出
	void show_messages();


	//往该手机信箱之中输入一条信息
	void put_message(string mes);
};
#endif

