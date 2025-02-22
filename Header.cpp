#include"Header.h"
void studentinfo(student &x) {
	cout << "nhap ten: ";
	getline(cin, x.hoten);
	cout << "MSSV: ";
	cin >> x.mssv;
	cout << "lop: ";
	cin >> x.lop;
	cin.ignore();
	cout << "place: ";
	getline(cin,x.pob);
	cout << "phone number: ";
	getline(cin, x.phone);
	x.next = nullptr;
}
void print_student(list x, int k) {
	SetConsoleOutputCP(CP_UTF8);
	int dem = 1;
	student* h = x.head;
	while (true) {
		if (x.quantity == 0 || x.quantity < k) {
			cout << "error\n";
			break;
		}
		else if (dem == k) {
			cout << "Họ và Tên: " << h->hoten << endl;
			cout << "Mã số sinh viên: " << h->mssv << endl;
			cout << "Lớp: " << h->lop << endl;
			cout << "Nơi sinh: " << h->pob << endl;
			cout << "Số điện thoại: " << h->phone << endl;
			break;
		}
		else {
			h = h->next;
			dem++;
		}
	}

}
void make_list(list &x) {
	student *mknew=new student();
	studentinfo(*mknew);
	if (x.head==nullptr) {
		x.head = mknew;
		x.tail = mknew;
		x.quantity = 1;
	}
	else {
		x.tail->next = mknew;
		x.quantity++;
		x.tail = mknew;
		
	}
}
void echo_list(list x) {
	ofstream out;
	out.open("Text.txt", ios::out);
	out << x.quantity << endl;
	student* tmp = x.head;
	for (int i = 0; i < x.quantity; i++) {
		out << tmp->hoten << "  " << tmp->mssv << "  " << tmp->lop << "  " << tmp->pob <<"  " << tmp->phone << endl;
		tmp = tmp->next;
	}
	out.close();
}
void update_list(list &ls_student) {

	ifstream in;
	in.open("Text.txt", ios::in);
	int k;
	in >> k;
	ls_student.quantity = k;
	in.ignore();
	for (int i = 0; i < k; i++) {
		string tmp;
	/*	int current;*/
		getline(in, tmp);
	/*	in >> current;*/
		student* mKstu = new student();
		//
		/*cout << tmp << endl;
		cout << current << endl;*/
		//
		string key1;
		int j = 0;
		while (j < tmp.length() && (tmp[j] != ' ' || tmp[j + 1] != ' ')) {
			key1 += tmp[j];
			j++;
		}
		j += 2;
		string key2;
		while (j < tmp.length() && (tmp[j] != ' ' || tmp[j + 1] != ' ')) {
			key2 += tmp[j];
			j++;
		}
		j += 2;
		string key3;
		while (j < tmp.length() && (tmp[j] != ' ' || tmp[j + 1] != ' ')) {
			key3 += tmp[j];
			j++;
		}
		j += 2;
		string key4;
		while (j < tmp.length() && (tmp[j] != ' ' || tmp[j + 1] != ' ')) {
			key4 += tmp[j];
			j++;
		}
		j += 2;
		string key5;
		
		while (j < tmp.length()) {
			key5 += tmp[j];
			j++;
		}
		
		mKstu->hoten = key1;
		mKstu->mssv = key2;
		mKstu->lop = key3;
		mKstu->pob = key4;
		mKstu->phone = key5;
		mKstu->next = nullptr;
		//
		/*cout << key1 << endl;
		cout << key2 << endl;
		cout << key3 << endl;
		cout << key4 << endl;*/
		//
		if (ls_student.head == nullptr) {
			ls_student.head = mKstu;
			ls_student.tail = mKstu;
		}
		else {
			ls_student.tail->next = mKstu;
			ls_student.tail = mKstu;
		}
	}
	in.close();
}
void fix_data(list& x,int k) {
	//cin.ignore();
	if (x.quantity == 0|| x.quantity<k ) {
		cout << "error\n";
	}
	
	else if (k == 1) {
		student* tmp = new student();
		cout << "Nhap thong tin thay doi\n";
		studentinfo(*tmp);
		tmp->next = x.head->next;
		x.head = tmp;
	}
	else if (x.quantity == k) {
		student* tmp = new student();
		cout << "Nhap thong tin thay doi\n";
		studentinfo(*tmp);
		student* current = x.head;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		current->next = tmp;
		x.tail = tmp;
	}
	else {
		student* tmp = new student();
		cout << "Nhap thong tin thay doi\n";
		studentinfo(*tmp);
		student* current = x.head;
		int dem = 1;
		while (dem < k - 1) {
			current = current->next;
			dem++;
		}
		tmp->next = current->next->next;
		current->next = tmp;
	}

}
void free_list(list& ls_student) {
	student* current = ls_student.head;
	while (current != nullptr) {
		student* temp = current;  // Lưu con trỏ hiện tại để giải phóng
		current = current->next;  // Di chuyển sang phần tử kế tiếp
		delete temp;              // Giải phóng phần tử hiện tại
	}
	// Đặt lại các con trỏ và số lượng phần tử về trạng thái ban đầu
	ls_student.head = nullptr;
	ls_student.tail = nullptr;
	ls_student.quantity = 0;
}//Hàm giải phóng bộ nhớ
void log_in_courses(int k) {
	string ss[9] = { "Xác suất thống kê", "Quản trị học", "Phương pháp nghiên cứu",
					 "Nhập môn CNTT", "Kỹ thuật lập trình", "Cấu trúc rời rạc",
					 "Cơ sở dữ liệu", "Kiến trúc máy tính", "Mạng máy tính" };

	vector<string> v;  
	ifstream in("Text1.txt");
	string curr;

	while (getline(in, curr)) {
		v.push_back(curr);
	}
	in.close();

	vector<int> lg;  
	for (int i = 0; i < 9; i++) {
		cout << ss[i] << endl;
		cout << "Đăng ký (yes/no): ";
		string tmp;
		cin >> tmp;
		if (tmp == "yes") {
			lg.push_back(i);
		}
		else {
			lg.push_back(-1);
		}
	}

	string curr1 = "";
	for (int i : lg) {
		curr1 += to_string(i) + " ";
	}

	while (v.size() <= k) {
		v.push_back("-1"); 
	}
	v[k] = curr1;
	ofstream out("Text1.txt");
	for (const string& line : v) {
		out << line << endl;
	}
	out.close();
}
void print_student_name(list x, int k) {
	SetConsoleOutputCP(CP_UTF8);
	int dem = 1;
	student* h = x.head;
	while (true) {
		if (x.quantity == 0 || x.quantity < k) {
			cout << "error\n";
			break;
		}
		else if (dem == k) {
			cout << "Họ và Tên: " << h->hoten;
			
			break;
		}
		else {
			h = h->next;
			dem++;
		}
	}

}
string student_x(list x, int k) {
	SetConsoleOutputCP(CP_UTF8);
	int dem = 1;
	student* h = x.head;
	while (true) {
		if (x.quantity == 0 || x.quantity < k||k<=0) {
			cout << "error\n";
			return "-1";
			break;
		}
		else if (dem == k) {
			return h->hoten ;
			
			break;
		}
		else {
			h = h->next;
			dem++;
		}
	}

}

