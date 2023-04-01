#include "Out_Worker.h"
#include "Here_Worker.h"
//重载流操作运算符，实现快速输入功能，减少测试函数代码
Out_Worker::Out_Worker()
{
	file_name = "files/Out_Worker.csv";
	type_p = "Out_Worker";
}

Out_Worker::Out_Worker(Here_Worker& hw)
{
	type_p = "Out_Worker";
	name = hw.get_name();
	gender = hw.get_gender();
	age = hw.get_age();
	phone.set_phone_number(hw.phone.get_phone_number());
	address_number = 0;
	left_time = time_now();
	work_place = hw.get_workplace();
}


istream& operator >>(istream& in, Out_Worker& ow)
{
	cout << "请依次输入以下信息：" << endl
		<< "姓名  性别  年龄  电话号码  工作单位  离开时间  现住址  现住址编号" << endl;
	string number;
	in >> ow.name >> ow.gender >> ow.age >> number >> ow.work_place >> ow.left_time >>
	 ow.address_now >> ow.address_number;
	ow.phone.set_phone_number(number);

	return in;
}

//重载流操作运算符，实现输出功能
ostream& operator<<(ostream& out, Out_Worker& ow)
{
	out.setf(ios::left);
	out <<setw(8)<< ow.name << setw(6) << ow.gender << setw(6) << ow.age << setw(12) << ow.phone.get_phone_number()  << setw(20) << ow.work_place << setw(12) << ow.left_time
		<< setw(20) << ow.address_now << setw(6) << ow.address_number << endl;
	return out;
} 

void Out_Worker::set(istream& in)
{
	string number;
	in >> name >> gender >> age >> number >> work_place >> left_time >> address_now >> address_number;
	phone.set_phone_number(number);
}

void Out_Worker::show()
{
	cout << *this;
}

void Out_Worker::save_to_file(string filename)
{
	fstream file;
	file.open(filename, ios::out | ios::app);
	file << name << "," << gender << "," << age << "," << phone.get_phone_number() << "," << work_place << "," << left_time
		<< "," << address_now << "," << address_number << endl;
	file.close();
}

string Out_Worker::get_workplace()
{
	return work_place;
}


