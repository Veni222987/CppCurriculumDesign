#include "Here_Student.h"
#include "Out_Student.h"
Here_Student::Here_Student()
{
	type_p = "Here_Student";
}

istream& operator>>(istream& in, Here_Student& hs)
{
	cout << "请依次输入以下信息：" << endl
		<< "姓名  性别  年龄  电话号码  学校  到来时间  原住址  原住址编号" << endl;
	string number;
	in >> hs.name >> hs.gender >> hs.age >> number >>
		hs.school >> hs.movein_time >> hs.address_from >> hs.address_number;
	hs.phone.set_phone_number(number);
	return in;
}

ostream& operator<< (ostream& out, Here_Student& hs)
{
	out.setf(ios::left);
	out << setw(8) << hs.name << setw(6) << hs.gender << setw(6) << hs.age << setw(12) << hs.phone.get_phone_number() << setw(20) << hs.school << setw(12) << hs.movein_time
		<< setw(20) << hs.address_from << setw(6) << hs.address_number << endl;
	return out;
}

void Here_Student::set(istream& in)
{
	string number;
	in >> name >> gender >> age >> number >> school >> movein_time >> address_from >> address_number;
	phone.set_phone_number(number);
}

void Here_Student::save_to_file(string filename)
{
	
	fstream file;
	file.open(filename, ios::out | ios::app);
	file << name << "," << gender << "," << age << "," << phone.get_phone_number() << "," << school << "," << movein_time
		<< "," << address_from << "," << address_number << endl;
	file.close();
}

//构造函数，用于办理迁入手续时候的类型转换
Here_Student::Here_Student(Out_Student& os)
{
	type_p = "Here_Student";
	name = os.get_name();
	age = os.get_age();
	gender = os.get_gender();
	string phone_number = os.phone.get_phone_number();
	phone.set_phone_number(phone_number);
	movein_time = time_now();
	address_number = 0;
	school = os.get_school();
}

void Here_Student::show()
{
	cout << *this;
}

string Here_Student::get_school()
{
	return school;
}
