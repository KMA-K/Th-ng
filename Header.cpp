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
	cin >> x.phone;	
	x.next = nullptr;
}
void print_student(student x) {
	cout << "hoten " << x.hoten << "   ";
	cout << "hoten " << x.mssv << "   ";
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
void update_list(list& ls_student) {

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
		int jey5;
		while (j < tmp.length()) {
			key5 += tmp[j];
			j++;
		}
		jey5 = stoi(key5);
		mKstu->hoten = key1;
		mKstu->mssv = key2;
		mKstu->lop = key3;
		mKstu->pob = key4;
		mKstu->phone = jey5;
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
	else if (x.quantity == k) {
		student* tmp = new student();
		cout << "Nhap thong tin thay doi\n";
		studentinfo(*tmp);
		student* current = x.head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = tmp;
		x.tail = tmp;
	}
	else if (k == 1) {
		student* tmp = new student();
		cout << "Nhap thong tin thay doi\n";
		studentinfo(*tmp);
		tmp->next = x.head->next;
		x.head = tmp;
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
}
void log_in_courses() {
	int k = 0;
	vector<pair<int,int>>v;
	ifstream in;
	in.open("Text1.txt", ios::out);
	int x;
	while (in >> x) {
		int x1;
		in >> x1;
		v.push_back(make_pair(x,x1));
		k++;
	}
	in.close();
	ofstream out;
	out.open("Text1.txt", ios::app);
	cout << "co dang ky hay khong: neu co nhan yes khong thi nhan no" << endl;
	string a;
	cin >> a;
	if (a == "yes") {
		k++;
		v.push_back(make_pair(k, 1));
		out << v[k-1].first << " " << v[k-1].second << endl;
	}
	else if (a == "no") {
		k++;
		v.push_back(make_pair(k, 0));
		out << v[k - 1].first << " " << v[k - 1].second << endl;
	}
	else {
		cout << "dang ky that bai\n";
	}

	out.close();

}
