#pragma once
#ifndef OUT_STUDENT_H
#define OUT_STUDENT_H

#include "Here_Student.h"
#include "Out_Population.h"
class Out_Student :
    public Out_Population
{
    string school;

public:
    Out_Student() ;
    Out_Student(Here_Student&);


    friend istream& operator >> (istream& in, Out_Student& os);
    friend ostream& operator << (ostream& out, Out_Student& os);

    void show() override;
    void set(istream& in);
    void save_to_file(string file_name) override;

    string get_school();
};
#endif

