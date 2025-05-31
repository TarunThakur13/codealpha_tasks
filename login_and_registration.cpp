#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool loginUser(const string& username, const string& password) {
    ifstream infile("users.txt");
    string storedUser, storedPass;

    while (infile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            return true;
        }
    }
    return false;
}

void registerUser(const string& username, const string& password) {
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    cout << "✅ Registration successful!\n";
}

void displayMenu() {
    cout << "====== USER AUTH SYSTEM ======\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Choose an option: ";
}

int main() {
    int option;
    string username, password;

    displayMenu();
    cin >> option;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (option == 1) {
        registerUser(username, password);
    } else if (option == 2) {
        if (loginUser(username, password))
            cout << "✅ Login successful!\n";
        else
            cout << "❌ Invalid credentials.\n";
    } else {
        cout << "⚠️ Invalid option selected.\n";
    }

    return 0;
}
