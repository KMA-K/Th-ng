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
// Định nghĩa template trước khi gọi nó
void update_student_point() {
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
    ofstream out;
    out.open("point.txt",ios::out);
    for (auto i : point) {
        out << i << endl;
    }
    out.close();
    
    free_list(list_of_student);
}
void scoreboard() {
    SetConsoleOutputCP(CP_UTF8);
    vector<string>username;//Mảng lưu tên
    username = clone_info("user_name.txt");
    if (username.empty()) {
        cout << "Không có học sinh nào trong danh sách.\n";
        return;
    }
    vector<string>point;//Mảng lưu điểm
    point = clone_info("point.txt");
    if (point.empty()) {
        cout << "Không có học sinh nào trong danh sách có điểm.\n";
        return;
    }
    vector<string>average;//Mảng lưu điểm trung bình tính chỉ
    average = clone_info("average.txt");
    if (average.empty()) {
        cout << "Không có học sinh nào trong danh sách có điểm.\n";
        return;
    }
    int tmp_x, tmp_y;
    tmp_x = 3;
    tmp_y = 0;
    for (int i = 0; i < point.size(); i++) {
        cout << "Học sinh: "<< username[i + 1] << endl;
        cout << "    Môn học          Số tính chỉ   Điểm học phần   Điểm trung bình tín chỉ   Trạng thái học tập   Số tín chỉ đã tích lũy" << endl;
        string s1[9]{ "Xác suất thống kê","Quản trị học","Phương pháp nghiên cứu",
           "Nhập môn CNTT","Kỹ thuật lập trình","Cấu trúc rời rạc","Cơ sở dữ liệu",
           "Kiến trúc máy tính","Mạng máy tính" };
        //tách mảng điểm thành từng diểm riêng lẻ
        stringstream sss(point[i]);
        vector<int> p;
        int x;
        while (sss >> x) {
            p.push_back(x);
        }
        //tách mảng điểm trung bình thành từng điểm riêng lẻ
        stringstream sss_aver(average[i]);
        vector<double> aver;
        double x_aver;
        while (sss_aver >> x_aver) {
            aver.push_back(x_aver);
        }
        //Xuất điểm của từng học sinh;
        for (int j = 0; j < 9; j++) {
           
            gotoxy(0, tmp_y+3+j);//Tên danh mục
            cout << s1[j];
            gotoxy(27, 3 + tmp_y + j);//số tín chỉ
            cout << 3;
            gotoxy(40, 3+tmp_y+j);//số điểm
            if (p[j] == -1) {
                gotoxy(35, 3 + tmp_y + j);
                cout << "Chưa đăng ký" << endl;
            }
            else{ cout << p[j]; }
            
            gotoxy(60, 3 + tmp_y + j);//điểm trung bình học phần
            if (aver[j] != -1) {
                cout << aver[j];
            }
            else {
                gotoxy(55, 3 + tmp_y + j);
                cout << "Chưa đăng ký" << endl;
            }
            // gotoxy(100, 3 + tmp_y + j);//số tín chỉ hoàn thành
            
            if (p[j] < 5) {
                gotoxy(85, 3 + tmp_y + j);//tình trạng học tập
                cout << "Faile";
            }
            else {
                gotoxy(85, 3 + tmp_y + j);//tình trạng học tập
                cout << "Pass";
            }
        }
        cout << endl;
        //tmp_y = 15 + 12 * i;
        tmp_y = tmp_y + 15;
        gotoxy(0, tmp_y);
        

    }
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void update_student_average() {
    SetConsoleOutputCP(CP_UTF8);
    vector<string> point; // Mảng lưu điểm
    point = clone_info("point.txt");

    if (point.empty()) {
        cout << "Không có học sinh nào trong danh sách có điểm.\n";
        return;
    }

    vector<string> average_data;

    for (int i = 0; i < point.size(); i++) {
        stringstream ss(point[i]);
        vector<double> v;
        string x;

        while (ss >> x) {
            if (x != "-1") {
                double xx = round((stod(x) / 3) * 100) / 100; // Tính trung bình
                v.push_back(xx);
            }
            else {
                v.push_back(-1);
            }
        }

        // Chuyển vector<double> thành vector<string>
        stringstream ss_result;
        for (double value : v) {
            ss_result << value << " ";
        }
        average_data.push_back(ss_result.str());
    }
    ofstream out;
    out.open("average.txt", ios::out);
    for (auto i : average_data) {
        out << i << endl;
    }
    out.close();
   
}
void scoreboard_1(int x_student) {
    SetConsoleOutputCP(CP_UTF8);
    vector<string>username;//Mảng lưu tên
    username = clone_info("user_name.txt");
    if (username.empty()) {
        cout << "Không có học sinh nào trong danh sách.\n";
        return;
    }
    vector<string>point;//Mảng lưu điểm
    point = clone_info("point.txt");
    if (point.empty()) {
        cout << "Không có học sinh nào trong danh sách có điểm.\n";
        return;
    }
    vector<string>average;//Mảng lưu điểm trung bình tính chỉ
    average = clone_info("average.txt");
    if (average.empty()) {
        cout << "Không có học sinh nào trong danh sách có điểm.\n";
        return;
    }
    int tmp_x, tmp_y;
    tmp_x = 3;
    tmp_y = 3;
    for (int i = 0; i < point.size(); i++) {
        if (i == x_student - 1) {
            gotoxy(0, tmp_y);
            cout << "Học sinh: " << username[i + 1] << endl;
            cout << "    Môn học          Số tính chỉ   Điểm học phần   Điểm trung bình tín chỉ   Trạng thái học tập   Số tín chỉ đã tích lũy" << endl;
            string s1[9]{ "Xác suất thống kê","Quản trị học","Phương pháp nghiên cứu",
               "Nhập môn CNTT","Kỹ thuật lập trình","Cấu trúc rời rạc","Cơ sở dữ liệu",
               "Kiến trúc máy tính","Mạng máy tính" };
            //tách mảng điểm thành từng diểm riêng lẻ
            stringstream sss(point[i]);
            vector<int> p;
            int x;
            while (sss >> x) {
                p.push_back(x);
            }
            //tách mảng điểm trung bình thành từng điểm riêng lẻ
            stringstream sss_aver(average[i]);
            vector<double> aver;
            double x_aver;
            while (sss_aver >> x_aver) {
                aver.push_back(x_aver);
            }
            //Xuất điểm của từng học sinh;
            for (int j = 0; j < 9; j++) {

                gotoxy(0, tmp_y + 3 + j);//Tên danh mục
                cout << s1[j];
                gotoxy(27, 3 + tmp_y + j);//số tín chỉ
                cout << 3;
                gotoxy(40, 3 + tmp_y + j);//số điểm
                cout << p[i];
                gotoxy(60, 3 + tmp_y + j);//điểm trung bình học phần
                cout << aver[j];
                // gotoxy(100, 3 + tmp_y + j);//số tín chỉ hoàn thành

                if (p[j] < 5) {
                    gotoxy(85, 3 + tmp_y + j);//tình trạng học tập
                    cout << "Faile";
                }
                else {
                    gotoxy(85, 3 + tmp_y + j);//tình trạng học tập
                    cout << "Pass";
                }
            }
            cout << endl;
            ////tmp_y = 15 + 12 * i;
            //tmp_y = tmp_y + 15;
            //gotoxy(0, tmp_y);

        }

    }
}

