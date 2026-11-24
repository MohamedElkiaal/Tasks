#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fullName;
    int id;
    float grade;

    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Grade: ";
    cin >> grade;

    ofstream outFile("Student.txt");
    if (!outFile.is_open()) {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    outFile << "Full Name: " << fullName << endl;
    outFile << "ID: " << id << endl;
    outFile << "Grade: " << grade << endl;

    outFile.close();
    cout << "Student data saved successfully." << endl;

    return 0;
}
