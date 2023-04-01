#pragma once
#ifndef OUT_POPULATION_H
#define OUT_POPULATION_H
#include "Person.h"
class Out_Population :
    public Person
{
protected:
	string left_time;
    string address_now;
    int address_number;
public:
    Out_Population();
    virtual void show() =0;

    void set_address_now_info(string address, int address_num);


    int get_address_num() override;
};
#endif

