#pragma once
#include<iostream>
#include<fstream>
#include"Windows.h"
#include<string>
#include<vector>
using namespace std;
struct student {
	string hoten;
	string mssv;
	string lop;
	string pob;
	int phone;
	student* next;
};
struct list {
	student *head;
	student *tail;
	int quantity;
};
void studentinfo(student &x);
void print_student(student x);
void make_list(list &x);
void echo_list(list x);
void update_list(list& x);
void fix_data(list& x,int k);
void free_list(list& ls_student);
void log_in_courses();