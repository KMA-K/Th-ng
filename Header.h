#pragma once
#include<iostream>
#include<fstream>
#include"Windows.h"
#include<string>
#include<vector>
#pragma execution_character_set("utf-8")
using namespace std;
struct student {
	string hoten;
	string mssv;
	string lop;
	string pob;
	string phone;
	student* next;
};
struct list {
	student *head;
	student *tail;
	int quantity;
};
void studentinfo(student &x);
void print_student(list x, int k);
void make_list(list &x);
void echo_list(list x);
void update_list(list& x);
void fix_data(list& x,int k);
void free_list(list& ls_student);
void log_in_courses(int k);
void print_student_name(list x, int k);