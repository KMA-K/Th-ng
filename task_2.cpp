#include"task2.h"
vector<string> clone_info(string filename) {
    SetConsoleOutputCP(CP_UTF8);
    ifstream in(filename);  
    vector<string> v;

    if (!in.is_open()) { 
        cerr << "Lỗi: Không thể mở file " << filename << endl;
        return v;  
    }

    string x;
    while (getline(in, x)) {
        v.push_back(x);
    }
    in.close();
    return v;
}
void updata_student_point() {
    SetConsoleOutputCP(CP_UTF8);
	vector<string>pass;
	vector<string>position;
	vector<string>username;
	username = clone_info("user_name.txt");
    if (username.empty()) {  
        cout << "Không có học sinh nào trong danh sách.\n";
        return;
    }
	for (int i = 1; i < username.size(); i++) {
		cout << "Nhập điểm\n";
		cout << "Học sinh: " << username[i] << endl;
		int b1, b2, b3, b4, b5, b6, b7, b8, b9;
		cin>> b1>> b2>> b3>> b4>> b5>> b6>> b7>> b8>> b9;
	}
}