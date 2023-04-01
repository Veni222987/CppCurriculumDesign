#include "Phone.h"

using namespace std;

Phone::Phone()
{
	phone_number = "0";
}
string Phone::get_phone_number()
{
	return phone_number;
}
void Phone::set_phone_number(string number)
{
	phone_number = number;
}
void Phone::show_messages()
{
	for (int i = 0; i < message_box.size(); i++)
		cout << message_box[i] << endl;
}
void Phone::put_message(string mes)
{
	message_box.push_back(mes);
}



