#pragma once
#ifndef HERE_POPULATION_H
#define HERE_POPULATION_H
#include "Person.h"
class Here_Population :
    public Person
{
protected:
    string movein_time;
    string address_from;
    int address_number;
public:
    Here_Population();

    void set_address_from_info(string address,int address_num);

    virtual void show() = 0;

    int get_address_num() override;
};

#endif


	
