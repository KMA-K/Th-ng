#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include"Windows.h"
#include"Menu.h"
#pragma execution_character_set("utf-8")

using namespace std;
void update_student_point();
vector<string> clone_info(string filename);
template <typename T>
void echo_task2(string namefile, vector<T> x) {
    SetConsoleOutputCP(CP_UTF8);
    ofstream out;
    out.open(namefile, ios::out);
    for (auto i : x) {
        out << i << " ";
    }
    out << endl;
    out.close();
}
template <typename T>
void echo_task2_1(string namefile, vector<T> x) {
    SetConsoleOutputCP(CP_UTF8);
    ofstream out;
    out.open(namefile, ios::app);
    for (auto i : x) {
        out << i << " ";
    }
    out << endl;
    out.close();
}
void scoreboard_1(int x_student);
void scoreboard();
void gotoxy(int x, int y);
void update_student_average();
