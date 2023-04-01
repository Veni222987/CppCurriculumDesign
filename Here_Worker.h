#pragma once
#ifndef HERE_WORKER_H
#define HERE_WORKER_H
#include "Here_Population.h"
#include "Out_Worker.h"

class Here_Worker :
    public Here_Population
{
    string work_place;
public:
    Here_Worker();
    Here_Worker(Out_Worker& ow);


    friend istream& operator>> (istream& in, Here_Worker hw);
    friend ostream& operator<< (ostream& out, Here_Worker hw);

    void show() override;
    void save_to_file(string filename) override;
    void set(istream& in) override;

    string get_workplace();
};
#endif

