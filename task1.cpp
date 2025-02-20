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