#include"Menu.h"
void menu_tinh() {
	SetConsoleOutputCP(CP_UTF8);
	int c;
	do {
		cout << "------------------------Portal sinh viên------------------\n";
		cout << "1.Đăng nhập\n";
		cout << "2.Đăng ký\n";
		cout << "Nhập lựa chọn: ";
		cin >> c;
		switch (c)
		{
		case 1: {
			system("cls");
			cout << "Đăng nhập tài khoản học sinh hay tài khoản giáo viên\n";
			cout << "Học sinh nhập (hs) Giáo viên nhập (gv)\n";
			cout << "Nhập lựa chọn: ";
			string a; cin >> a;
			int tmp;
			if (a == "hs") {
				tmp = log_in_member();
			}
			else if (a == "gv") {
				 tmp = log_in_admin();
			}
			if (tmp == -1) {
				cout << "Lỗi\n";
			}
			else {
				dashboard(tmp);
			}

		}
		
		default:
			break;
		}

	} while (c);
}
void dashboard(int op){
	SetConsoleOutputCP(CP_UTF8);
	system("cls");
	cout << "Thông tin cá nhân" << endl;
	cout << "Đăng ký học phần" << endl;
	cout << "Bảng điểm" << endl;
	int x = op;
	//cout << x << endl;
	scoreboard_1( x);
	// cập nhập danh sách liên kết
	list list_of_student;
	list_of_student.head = nullptr;
	list_of_student.tail = nullptr;
	list_of_student.quantity = 0;
	update_list(list_of_student);
	print_student(list_of_student, x);
	//fix_data(list_of_student, 1);
	echo_list(list_of_student);
	free_list(list_of_student);


}