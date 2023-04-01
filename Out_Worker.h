#pragma once
#ifndef OUT_WORKER_H
#define OUT_WORKER_H
 
#include "Out_Population.h"

class Here_Worker;
class Out_Worker :
    public Out_Population
{
    string work_place;
public:
    Out_Worker();
    Out_Worker(Here_Worker&);

    friend istream& operator >> (istream& in,  Out_Worker& ow);
    friend ostream& operator << (ostream& out, Out_Worker& ow);



    void show() override;
    void set(istream& in) override;
    void save_to_file(string file_name) override;

    string get_workplace();
};
#endif

