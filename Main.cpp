#include"Header.h"
#include"task1.h"
#pragma execution_character_set("utf-8")
using namespace std;
int main() {
	SetConsoleOutputCP(CP_UTF8);
	/*list list_of_student;
	list_of_student.head = nullptr;
	list_of_student.tail = nullptr;
	list_of_student.quantity = 0;
	update_list(list_of_student);
	make_list(list_of_student);
	fix_data(list_of_student, 1);
	echo_list(list_of_student);
	free_list(list_of_student);
	log_in_courses();
	system("pause");*/
	string name = "Bảo An";
	string pass = "123224";
	ifo_task_1(name, pass);
	return 0;
}