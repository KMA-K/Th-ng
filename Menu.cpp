#include "Menu.h"
void pauseScreen() {
    cout << "Nhấn Enter để quay lại \n";
    cin.ignore();
    cin.get();
}
void menu_tinh() {
    SetConsoleOutputCP(CP_UTF8);
    int c;

    do {
        system("cls");
        cout << "------------------------Portal sinh viên------------------\n";
        cout << "1. Đăng nhập\n";
        cout << "2. Đăng ký\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn: ";
        cin >> c;

        switch (c) {
        case 1: {
            system("cls");
            cout << "Đăng nhập tài khoản học sinh hay tài khoản giáo viên\n";
            cout << "Học sinh nhập (hs), Giáo viên nhập (gv)\n";
            cout << "Nhập lựa chọn: ";
            string a;
            cin >> a;

            int tmp = -1; 
            //Học sinh
            if (a == "hs") {
                tmp = log_in_member();
                if (tmp == -1) {
                    cout << "Đăng nhập không hợp lệ!\n";
                    pauseScreen();
                }
                else {
                    dashboard(tmp);
                }
            }
            // giáo viên
            else if (a == "gv") {
                cin.ignore();
                tmp = log_in_admin_1();
                if (tmp == -1) {
                    cout << "Đăng nhập không hợp lệ!\n";
                    pauseScreen();
                }
                else {
                    dashboard_tea(tmp);
                }
            }
            else {
                cout << "Lựa chọn không hợp lệ!\n";
                pauseScreen();
            }

            
            break;
        }
        case 2:
            
            cout << "Lựa chọn kiểu tài khoản\n";
            cout << "1.Học sinh\n";
            cout << "2.Giáo viên\n";
            cout << "Chọn: ";
            int tmp_1_1;
            cin >> tmp_1_1;
            if (tmp_1_1 == 1) {
                cin.ignore();
                register_std();
            }
            else if(tmp_1_1 == 2) {
                system("cls");
                cin.ignore();
                register_tea();
            }
            cout << "Đăng ký thành công" << endl;
            pauseScreen();
            break;
        case 0:
            cout << "Thoát chương trình.\n";
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
            break;
        }
    } while (c != 0);
}
void dashboard(int op) {
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    int x = op;
    int cc;

    do {
        system("cls");
        cout << "---------------------- Dashboard ----------------------\n";
        cout << "1. Xem thông tin cá nhân\n";
        cout << "2. Sửa thông tin cá nhân\n";
        cout << "3. Đăng ký học phần\n";
        cout << "4. Bảng điểm\n";
        cout << "0. Quay lại\n";
        cout << "Nhập lựa chọn: ";
        cin >> cc;

        switch (cc) {
        case 1: {
            system("cls");
            list list_of_student;
            list_of_student.head = nullptr;
            list_of_student.tail = nullptr;
            list_of_student.quantity = 0;
            update_list(list_of_student);
            print_student(list_of_student, x);
            free_list(list_of_student);
            pauseScreen();
            break;
        }
        case 2: {
            system("cls");
            cin.ignore();
            list list_of_student;
            list_of_student.head = nullptr;
            list_of_student.tail = nullptr;
            list_of_student.quantity = 0;
            update_list(list_of_student);
            fix_data(list_of_student, x);
            echo_list(list_of_student);
            free_list(list_of_student);
            pauseScreen();
            break;
        }
        case 3:
            system("cls");
            
            log_in_courses(x-1);
            pauseScreen();
            break;
        case 4:
            system("cls");
            scoreboard_1(x);
            pauseScreen();
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
            break;
        }
    } while (cc != 0);
}
void register_std() {
    SetConsoleOutputCP(CP_UTF8);
    string name = "Bao An";
    string pass = "1";
    ifo_task_1_student(name, pass);
    list list_of_student;
    list_of_student.head = nullptr;
    list_of_student.tail = nullptr;
    list_of_student.quantity = 0;
    update_list(list_of_student);
    make_list(list_of_student);
    echo_list(list_of_student);
    free_list(list_of_student);

   
}
void ifo_task_1_student(string username_admin, string pass_admin) {
    SetConsoleOutputCP(CP_UTF8);
    vector<string>pass;
    vector<string>position;
    vector<string>username;
    //Cập nhật sô liệu quản lý 
    position.push_back("admin");
    username.push_back(username_admin);
    pass.push_back(pass_admin);
    cout << "Nhập theo cú pháp usernam - pass\n";
    int n = 1;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nhập: ";
        string curr;
        getline(cin, curr);
        stringstream ss(curr);
        string tmp_username, tmp_pass, tmp_position;
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
void dashboard_tea(int op) {
    SetConsoleOutputCP(CP_UTF8);
    system("cls");

    int x = op;
    int cc;

    do {
        system("cls");
        cout << "---------------------- Dashboard ----------------------\n";
        cout << "1. Bảng điểm của tất cả sinh viên\n";
        cout << "2.Nhập điểm cho tất cả học sinh\n";
        cout << "3. Sửa đổi,thêm sinh viên\n";
        cout << "4.Sửa đổi, thêm học phần cho sinh viên\n";
        cout << "5.Nhập điểm cho từng học sinh\n";

        cout << "0. Quay lại\n";
        cout << "Nhập lựa chọn: ";
        cin >> cc;

        switch (cc) {
        case 1: {
            system("cls");
            scoreboard();
            pauseScreen();
            break;
        }
        case 2: {
            system("cls");
            update_student_point();
            update_student_average();
            pauseScreen();
            break;
        }
        case 3:
            system("cls");
            case3();
            pauseScreen();
            break;
        case 4:
            system("cls");
            case4();
            scoreboard_1(x);
            pauseScreen();
            break;
        case 5: {
            case5();
            pauseScreen();
        }
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
            break;
        }
    } while (cc != 0);
}
