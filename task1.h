#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include"Windows.h"
#include"task2.h"
#pragma execution_character_set("utf-8")

using namespace std;
bool isFileEmpty(const string& filename);
void ifo_task_1(string username_admin, string pass_admin);
//struct T {
//    Type value;
//    T(Type v) : value(v) {}        
//    operator Type() const { return value; }  
//};
//template <typename Type>
void echo_task1(string namefile, vector<string>x);
int log_in_member();
int log_in_admin();