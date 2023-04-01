#include "Here_Worker.h"
Here_Worker::Here_Worker()
{
	type_p = "Here_Worker";
}

istream& operator>>(istream& in, Here_Worker hw)
{
	cout << "请依次输入以下信息：" << endl
		<< "姓名  性别  年龄  电话号码  工作单位  到来时间  原住址  原住址编号" << endl;
	string number;
	in >> hw.name >> hw.gender >> hw.age >> number >> hw.work_place >> hw.movein_time >>
		hw.address_from >> hw.address_number;
	hw.phone.set_phone_number(number);
	return in;
}

ostream& operator<<(ostream& out, Here_Worker hw)
{
	out.setf(ios::left);
	out << setw(8) << hw.name << setw(6) << hw.gender << setw(6) << hw.age << setw(12) << hw.phone.get_phone_number() << setw(20) << hw.work_place << setw(12) << hw.movein_time
		<< setw(20) << hw.address_from << setw(6) <<hw.address_number << endl;
	return out;
}

void Here_Worker::show()
{
	cout << *this;
}

void Here_Worker::set(istream& in)
{
	string number;
	in >> name >> gender >> age >> number >> work_place >> movein_time >> address_from >> address_number;
	phone.set_phone_number(number);
}

void Here_Worker::save_to_file(string filename)
{
	fstream file;
	file.open(filename, ios::out | ios::app);
	file << name << "," << gender << "," << age << "," << phone.get_phone_number() << "," << work_place << "," << movein_time
		<< "," << address_from << "," << address_number << endl;
	file.close();
}
Here_Worker::Here_Worker(Out_Worker& ow)
{
	type_p = "Here_Worker";
	name = ow.get_name();
	age = ow.get_age();
	gender = ow.get_gender();
	string phone_number = ow.phone.get_phone_number();
	phone.set_phone_number(phone_number);
	movein_time = time_now();
	address_number = 0;
	work_place = ow.get_workplace();
}
string Here_Worker::get_workplace()
{
	return work_place;
}
