#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool userExists(string username) {
    ifstream file("users.txt");
    string user, pass;

    while(file >> user >> pass) {
        if(user == username)
            return true;
    }
    return false;
}
void registerUser() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    if(userExists(username)) {
        cout << "Username already exists!\n";
        return;
    }
    cout << "Enter password: ";
    cin >> password;
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration successful!\n";
}
void loginUser() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream file("users.txt");
    string user, pass;
    while(file >> user >> pass) {
        if(user == username && pass == password) {
            cout << "Login successful!\n";
            return;
        }
    }
    cout << "Invalid credentials!\n";
}
int main() {
    int choice;
    do {
        cout << "\n MENU \n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 3);
    return 0;
}