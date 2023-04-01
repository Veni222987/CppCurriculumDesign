#pragma once


#ifndef MYHEAD_H
#define MYHEAD_H
//opencv的头文件，实验性功能
#include <opencv2/opencv.hpp>


#include "Person.h"
#include "Out_Student.h"
#include "Out_Worker.h"
#include "Here_Student.h"
#include "Here_Worker.h"



#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <fstream>
#include "conio.h"
#include <windows.h>
#include <iomanip>

#include <sstream>
#include "Person.h"

using namespace std;

int menu();
void main_map();
void setfont(double size);

vector<Person*> get_file_list(string region);
void save_file_list(string region,vector<Person*>&);


void input_information(string region, vector<Person*>& list);
int find_name(vector<Person*>list,string name);

void move_in(int, vector<Person*>&);
void move_out(int, vector<Person*>&);

string time_str();

void sent_message(string name, vector<Person*>);

void sort_by_age(vector<Person*>&);
void sort_by_name(vector<Person*>& list);


int statistics_in_region(vector <Person*> list,int address_num);

void show_here(vector<Person*> list);
void show_not_here(vector<Person*> list);

void show_type(string type,vector<Person*>);
void show_all(vector<Person*>);

void get_risky_Person(vector<Person*>);

void suansuan(vector<Person*>,string region);

#endif




