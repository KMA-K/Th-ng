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
    SetConsoleOutputCP(CP_UTF8);
    vector<string> username = clone_info("user_name.txt");
    if (username.empty()) {
        cout << "Không có học sinh nào trong danh sách.\n";
        return;
    }

    string ss[9]{ "Xác suất thống kê", "Quản trị học", "Phương pháp nghiên cứu",
                  "Nhập môn CNTT", "Kỹ thuật lập trình", "Cấu trúc rời rạc",
                  "Cơ sở dữ liệu", "Kiến trúc máy tính", "Mạng máy tính" };

    for (int i = 1; i < username.size(); i++) {
        cout << "Nhập điểm\n";
        cout << "Học sinh: " << username[i] << endl;
        vector<int> point;
        for (int j = 0; j < 9; j++) {
            cout << ss[j] << ": ";
            int x;
            cin >> x;
            point.push_back(x);
        }

        cout << "Xác nhận\n";
        cout << "yes or no\n";
        cout << "Nhập lựa chọn: ";
        string tmp;
        cin >> tmp;

        if (tmp == "yes") {
            echo_task2("point.txt", point); // Sẽ tìm thấy định nghĩa của template
            system("cls");
        }
        else {
            system("cls");
            i = i - 1;
        }
    }
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
    vector<string>point;//Mảng lưu điểm
    point = clone_info("point.txt");
    if (point.empty()) {
        cout << "Không có học sinh nào trong danh sách có điểm.\n";
        return;
    }
    for (int i = 0; i < point.size(); i++) {
        stringstream ss(point[i]);
        vector<double>v;
        string x;
        while (ss >> x) {
            double xx = round((stod(x) / 3) * 100) / 100;
            v.push_back(xx);
        }
        echo_task2_1("average.txt", v);
    }
    
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

