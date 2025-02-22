#include"admin.h"
void case3() {
	cout << "1.Sửa thông tin sinh viên\n";
	cout << "2.Thêm sinh viên\n";
	cout << "Nhập lựa chọn: ";
	int x; cin >> x;
	if (x == 2) {
		register_std();
	}
	else if (x == 1) {
		system("cls");
		list list_of_student;
		list_of_student.head = nullptr;
		list_of_student.tail = nullptr;
		list_of_student.quantity = 0;
		update_list(list_of_student);
	
		int tmp_1 = list_of_student.quantity;
		for (int i = 1; i <= tmp_1; i++) {
			cout << "Học sinh số: " << i << endl;
			print_student(list_of_student, i);
			cout << endl;
		}
		cout << "Nhập thứ tự của sinh viên muốn sửa\n";
		cout << "Ví dụ mún sửa thông tin của sinh viên số 1 nhập: 1" << endl;
		cout << "Nhập: ";
		int tmp_2;
		while(true){
			cin >> tmp_2;
			if (tmp_2 > tmp_1) {
				cout << "không tìm thấy sinh viên\n";
				cout << "Nhập lại";
				continue;
			}
			else {
				break;
			}
		}
		system("cls");
		cin.ignore();
		fix_data(list_of_student, tmp_2);
		echo_list(list_of_student);

		free_list(list_of_student);
	}
}
void case4() {
		
	   list list_of_student;
	   list_of_student.head = nullptr;
	   list_of_student.tail = nullptr;
	   list_of_student.quantity = 0;
	   update_list(list_of_student);
	
	   vector<string> subject = clone_info("Text1.txt");
	   string s1[9]{ "Xác suất thống kê","Quản trị học","Phương pháp nghiên cứu",
		  "Nhập môn CNTT","Kỹ thuật lập trình","Cấu trúc rời rạc","Cơ sở dữ liệu",
		  "Kiến trúc máy tính","Mạng máy tính" };
	   for (int i = 0; i < subject.size(); i++) {
		   cout << "Học sinh: "<<i+1 << endl;
		   cout << "Tên: ";
		    print_student_name(list_of_student, i+1 );
			cout << endl;
			stringstream ss(subject[i]);
			set<int> v;
			int tmp_3;
			while (ss >> tmp_3) {
				v.insert(tmp_3);
			}
			for (int i = 0; i < 9; i++) {
				cout << s1[i] << " :";
				auto tmp_4 = v.find(i);
				if (tmp_4 == v.end()) {
					cout << "no" << endl;
				}
				else {
					cout << "yes" << endl;
				}
			}cout << endl;




	   }
		cout << "Nhập thứ tự của sinh viên muốn sửa\n";
		cout << "Ví dụ mún sửa học phần của sinh viên số 1 nhập: 1" << endl;
		cout << "Nhập: ";
		int tmp_5;
		cin >> tmp_5;
		system("cls");
		log_in_courses(tmp_5-1);
		

		free_list(list_of_student);
}
void register_tea() {
	string x1, x2, x3 = "admin";
	cout << "Nhập username: ";
	getline(cin,x1);
	cout << "Nhập pass: ";
	getline(cin,x2);
	ifo_admin_1(x1,x2);

}
void ifo_admin_1(string username_admin, string pass_admin) {
	SetConsoleOutputCP(CP_UTF8);
	vector<string>pass;
	vector<string>username;
	pass = clone_info("teacher_name.txt");
	if (pass.empty()) {
		pass.push_back("1");
	}
	
	username = clone_info("teacher_pass.txt");
	if (username.empty()) {
		username.push_back("Bao An");
	}
	pass.push_back(pass_admin);
	username.push_back(username_admin);
	echo_task1("teacher_pass.txt", pass);
	echo_task1("teacher_name.txt", username);
}
int log_in_admin_1() {
	SetConsoleOutputCP(CP_UTF8);
	vector<string>username;//Mảng lưu username
	username = clone_info("teacher_name.txt");
	if (username.empty()) {
		cout << "erro\n";
		return -1;
	}
	vector<string>password;//Mảng lưu pass
	password = clone_info("teacher_pass.txt");
	if (password.empty()) {
		cout << "erro\n";
		return -1;
	}
	string user, pass;
	cout << "Nhập username: ";
	getline(cin, user);
	cout << "Nhập pass: ";
	getline(cin, pass);
	for (size_t i = 0; i < username.size(); i++) {
		//cout << position[i] << " " << password[i]<<" "<< username[i] << endl;
		if (pass == password[i]) {
			if (user == username[i]) {
				cout << "Đăng nhập thành công\n";
				return static_cast<int>(i);
			}
			else {
				cout << 1 << username[i] << 1 << endl;
				cout << 1 << user << 1 << endl;
				cout << "Tên sai" << endl;
			}
		}
	}

	cout << "Đăng nhập thất bại\n";
	return -1; // Trả về -1 nếu đăng nhập thất bại

}
void update_student_point_1(int x) {
	vector<string> point;
	SetConsoleOutputCP(CP_UTF8);

	list list_of_student;
	list_of_student.head = nullptr;
	list_of_student.tail = nullptr;
	list_of_student.quantity = 0;
	update_list(list_of_student);

	vector<string> v = clone_info("Text1.txt");

	string ss[9] = { "Xác suất thống kê", "Quản trị học", "Phương pháp nghiên cứu",
					 "Nhập môn CNTT", "Kỹ thuật lập trình", "Cấu trúc rời rạc",
					 "Cơ sở dữ liệu", "Kiến trúc máy tính", "Mạng máy tính" };

	int n = list_of_student.quantity;
	for (int i = 0; i < n; i++) {
		if (i >= v.size()) {
			cout << "Lỗi: Dữ liệu Text1.txt không đủ!\n";
			break;
		}
		if (i == x) {
			string point_1 = "";
			cout << "Nhập điểm của học sinh: ";
			print_student_name(list_of_student, i + 1);
			cout << endl;

			stringstream ss1(v[i]);
			vector<int> tmp;
			int curr;
			while (ss1 >> curr) {
				tmp.push_back(curr);
			}

			for (int j = 0; j < 9; j++) {
				bool isRegistered = (find(tmp.begin(), tmp.end(), j) != tmp.end());
				if (!isRegistered) {
					cout << ss[j] << ": Không đăng ký\n";
					point_1 += "-1 ";
				}
				else {
					cout << ss[j] << ": ";
					int tmp_2;
					cin >> tmp_2;
					point_1 += to_string(tmp_2) + " ";
				}
			}
			cout << endl;

			if (!point_1.empty()) {
				point.push_back(point_1);
			}
		}
	}
	vector<string>k_point;
	k_point = clone_info("point.txt");
	for (int i = 0; i < k_point.size(); i++) {
		if (i == x) {
			k_point[i] = point[0];
		}
	}
	ofstream out;
	out.open("point.txt", ios::out);
	for (auto i : k_point) {
		out << i << endl;
	}
	out.close();

	free_list(list_of_student);
}
void case5() {
	system("cls");
	list list_of_student;
	list_of_student.head = nullptr;
	list_of_student.tail = nullptr;
	list_of_student.quantity = 0;
	update_list(list_of_student);

	int tmp_1 = list_of_student.quantity;
	for (int i = 1; i <= tmp_1; i++) {
		cout << "Học sinh số: " << i << endl;
		print_student(list_of_student, i);
		cout << endl;
	}
	cout << "Nhập thứ tự của sinh viên muốn sửa \n";
	cout << "Ví dụ mún sửa điểm của sinh viên số 1 nhập: 1" << endl;
	cout << "Nhập: ";
	int tmp_2;
	while (true) {
		cin >> tmp_2;
		if (tmp_2 > tmp_1) {
			cout << "không tìm thấy sinh viên\n";
			cout << "Nhập lại";
			continue;
		}
		else {
			break;
		}
	}
	system("cls");
	update_student_point_1(tmp_2 - 1);
}