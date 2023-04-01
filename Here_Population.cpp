#include "Here_Population.h"
Here_Population::Here_Population()
{
	address_number = 0;
	live_here = true;
}

void Here_Population::set_address_from_info(string address,int address_num)
{
	address_from = address;
	address_number = address_num;
}

int Here_Population::get_address_num()
{
	return address_number;
}
