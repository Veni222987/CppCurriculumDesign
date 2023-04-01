#include "Out_Population.h"
Out_Population::Out_Population()
{
	age = 0;
	live_here = false;
}

void Out_Population::set_address_now_info(string address, int address_num)
{
	address_now = address;
	address_number = address_num;
}

int Out_Population::get_address_num()
{
	return address_number;
}

