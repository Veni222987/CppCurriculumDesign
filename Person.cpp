#include "Person.h"

Person::Person()
{
	age = 0;
}

string Person::get_file_name()
{
	return file_name;
}

string Person::get_name()
{
	return name;
}

bool Person::bool_here()
{
	return live_here;
}

int Person::get_age()
{
	return age;
}

string Person::get_gender()
{
	return gender;
}

//自动获取当前时间的time类
string Person::time_now()
{
	string time_out;
	time_t now = time(nullptr);
	tm tm_t;
	localtime_s(&tm_t,&now);
	time_out = to_string(1900 + tm_t.tm_year) + "." + to_string(1 + tm_t.tm_mon)
				+"."+ to_string(tm_t.tm_mday);
	return time_out;
}

string Person::get_type()
{
	return type_p;
}
