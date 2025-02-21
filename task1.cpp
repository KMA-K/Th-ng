#include"task1.h"
bool isFileEmpty(const string& filename) {
	ifstream file(filename, ios::ate); // Mở file và đặt con trỏ ở cuối
	return file.tellg() == 0; // Kiểm tra kích thước file
}
void echo_task1(string namefile, vector<string>x) {
	SetConsoleOutputCP(CP_UTF8);
	ofstream out;
	out.open(namefile,ios::app);
	bool check;
	if (isFileEmpty(namefile)) {
		for (auto i : x) {
			out << i << endl;
		}
	}
	else { 
		for (int i = 1; i < x.size(); i++) {
			out << x[i] << endl;
		}
	}
	
	out.close();
}
void ifo_task_1(string username_admin, string pass_admin) {
	SetConsoleOutputCP(CP_UTF8);
	vector<string>pass;
	vector<string>position;
	vector<string>username;
	//Cập nhật sô liệu quản lý 
	position.push_back("admin");
	username.push_back( username_admin);
	pass.push_back( pass_admin);

	cout << "Nhập số lượng sinh viên muốn thêm vào hệ thống\n";

	int n; cin >> n;
	cout << "Nhập theo cú pháp usernam - pass\n";
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Sinh viên thứ: " << i + 1 << endl;
		string curr;
		getline(cin, curr);
			stringstream ss(curr);
			string tmp_username,tmp_pass,tmp_position;
			getline(ss, tmp_username, '-');
			getline(ss, tmp_pass, '-');
			tmp_pass.erase(0, 1);
			position.push_back("member");
			username.push_back(tmp_username);
			pass.push_back(tmp_pass);
	}
	echo_task1("pass.txt", pass);
	echo_task1("user_name.txt", username);
	echo_task1("position.txt", position);
}
int log_in_member() {
	SetConsoleOutputCP(CP_UTF8);
	vector<string>username;//Mảng lưu username
	username = clone_info("user_name.txt");
	if (username.empty()) {
		cout << "erro\n";
		return -1;
	}
	vector<string>password;//Mảng lưu pass
	password = clone_info("pass.txt");
	if (password.empty()) {
		cout << "erro\n";
		return -1;
	}
	vector<string>position;//Mảng lưu chức vụ
	position = clone_info("position.txt");
	if (password.empty()) {
		cout << "erro\n";
		return -1;
	}
	string user, pass;
	cout << "Nhập username: ";
	cin.ignore();
	getline(cin, user);
	user += ' ';
	cout << "Nhập pass: ";
	getline(cin, pass);
	for (size_t i = 0; i < username.size(); i++) { 
		//cout << position[i] << " " << password[i]<<" "<< username[i] << endl;
		if (position[i] == "member" && pass == password[i]) {
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
int log_in_admin() {
	SetConsoleOutputCP(CP_UTF8);
	vector<string>username;//Mảng lưu username
	username = clone_info("user_name.txt");
	if (username.empty()) {
		cout << "erro\n";
		return -1;
	}
	vector<string>password;//Mảng lưu pass
	password = clone_info("pass.txt");
	if (password.empty()) {
		cout << "erro\n";
		return -1;
	}
	vector<string>position;//Mảng lưu chức vụ
	position = clone_info("position.txt");
	if (password.empty()) {
		cout << "erro\n";
		return -1;
	}
	string user, pass;
	cout << "Nhập username: ";
	cin.ignore();
	getline(cin, user);
	user += ' ';
	cout << "Nhập pass: ";
	getline(cin, pass);
	for (size_t i = 0; i < username.size(); i++) {
		cout << position[i] << " " << password[i]<<" "<< username[i] << endl;
		if (position[i] == "admin" && pass == password[i] && user == username[i]) {
			cout << "Đăng nhập thành công\n";
			return static_cast<int>(i);
		}
	}

	cout << "Đăng nhập thất bại\n";
	return -1; // Trả về -1 nếu đăng nhập thất bại

}
