#pragma once
#ifndef HERE_STUDENT_H
#define HERE_STUDENT_H
#include "Here_Population.h"
class Out_Student;

class Here_Student :
    public Here_Population
{
    string school;

public:
    Here_Student();

    Here_Student(Out_Student&);

    friend istream& operator >> (istream& in, Here_Student& hs);
    friend ostream& operator << (ostream& out, Here_Student& hs);

    
    void show() override;
    void set(istream& in) override;
    void save_to_file(string file_name) override;
    string get_school();
};
#endif


