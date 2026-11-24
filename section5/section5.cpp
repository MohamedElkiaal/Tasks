#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[20];
    int id;
    float grade;
    char delim = '$';
    char choice = 'y';

    ofstream file("students.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error opening file";
        return 1;
    }

    while (choice == 'y' || choice == 'Y') {
        cout << "Enter Name: ";
        cin.getline(name, 20);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Do you want to add more records? (y/n): ";
        cin >> choice;
        cin.ignore();
    }

    file.close();
    return 0;
}
