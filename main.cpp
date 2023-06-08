//
// Created by erasy on 07.06.2023.
// Сделать +- такой проект где будет регистрация и авторизация. Создайете текст файл где будет user (user.txt). Там вы будете хранить данные в формате username password
// Пороли надо хранить в зашифрованном формате. При запуске от нас требуется 2 числа 1 - sign up. 2 - sign in.
// Example. 1 ------ Kamila qwe123
// пропускаем через хеш после обратно запихать.
// 2 ----- Kamila qwe123
// После регистрации выводите сообщение 1 (( 1."Success Registration" ))  2 (( 2. "User not found"    3."Invalid password"   4."Welcome, Kamila"))
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace ::std;
class Myclass{
public:
    int start() {
        int a;
        cout << "1.Sign up" << endl << "Sign in" << endl << "Choose 1 or 2: ";
        cin >> a;
        if (a == 1) {
            reg();
        } else if (a == 2) {
            string username,password;
            cout << "Write username: ";
            cin >> username;
            cout << "Write password: ";
            cin >> password;
            if(check_users(username,password) == true){
                cout <<"Welcome!  " << username;
            }
            else{
                cout << "This account does not exist" << endl;
                int a;
                cout << "If you want to sign up. Choose 1. But if you want to back in main Choose 2" << endl;
                cin >> a;
                if (a == 1){
                    reg();
                }
                else{
                    start();
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////
    bool check_users(const string& username, const string& password) {
        // Открываем файл для чтения
        ifstream file("C:\\Users\\erasy\\CLionProjects\\hash_keshmark\\users.txt");

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                // Проверяем каждую строку файла на соответствие имени пользователя и пароля
                if (line.find(username + "" + password) != string::npos) {
                    // Найдено совпадение
                    file.close();
                    return true;
                }
            }
            file.close();
        }
    }




////////////////////////////////////////////////////////////////////////////////
    int reg() {
        string username, password;
        cout << "Write username: ";
        cin >> username;
        cout << "Write password: ";
        cin >> password;
        // Открываем файл для записи
        ofstream file("C:\\Users\\erasy\\CLionProjects\\hash_keshmark\\users.txt", ios::app);
        const int k = 31, mod = 1e9+7;

        string hash = password;
        long long h = 0, m = 1;
        for (char c : password) {
            int x = (int) (c - 'a' + 1);
            h = (h + m * x) % mod;
            m = (m * k) % mod;
        }
        password = to_string(m);

        if (file.is_open()) {
            // Записываем имя пользователя и пароль в файл
            file << username << password << endl;
            file.close();
            cout << "Registration successfully" << endl;
        } else {
            cout << "File can't open." << endl;
        }

        return 0;
    }
////////////////////////////////////////////////////////////////////

};
int main(){
    Myclass amongus;
    amongus.start();
}