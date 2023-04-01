#include "Out_Student.h"
Out_Student::Out_Student()
{
	file_name = "files/Out_Student.csv";
	type_p = "Out_Student";
};

Out_Student::Out_Student(Here_Student& hs)
{
	type_p = "Out_Student";
	name = hs.get_name();
	gender = hs.get_gender();
	age = hs.get_age();
	phone.set_phone_number(hs.phone.get_phone_number());
	address_number = 0;
	left_time = time_now();
	school = get_school();
}

istream& operator >>(istream& in, Out_Student & os)
{
	cout << "请依次输入以下信息：" << endl
		<< "姓名  性别  年龄  电话号码  学校  离开时间  现住址  现住址编号" << endl;
	string number;
	in >> os.name >> os.gender >> os.age >> number >> os.school >> os.left_time >>
		 os.address_now >> os.address_number;
	os.phone.set_phone_number(number);

	return in;
}

ostream& operator<<(ostream& out, Out_Student & os)
{
	out.setf(ios::left);

	out <<setw(8)<< os.name << setw(6) << os.gender << setw(6) << os.age << setw(12) << os.phone.get_phone_number()  << setw(20) << os.school << setw(12) << os.left_time
		<< setw(20) << os.address_now << setw(6) << os.address_number << endl;
	return out;
}

void Out_Student::show()
{
	cout << *this;
}
void Out_Student::set(istream& in)
{
	string number;
	in >> name >> gender >> age >> number >> school >> left_time >> address_now >> address_number;
	phone.set_phone_number(number);
}

void Out_Student::save_to_file(string filename)
{
	fstream file;
	file.open(filename, ios::out | ios::app);
	file<< name << "," <<gender << "," << age << "," << phone.get_phone_number() << "," << school << "," << left_time
		<< "," << address_now << "," << address_number << endl;
	file.close();
}

string Out_Student::get_school()
{
	return school;
}

