#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("grades.txt");
    if (!out) {
        cout << "Unable to open the file" << endl;
        return 1;
    }else{

    int g;
    cout << "Enter 5 integer grades:\n";
    for (int i = 0; i < 5; i++) {
        cin >> g;
        out << g << endl;
    }
    out.close();

    ifstream in("grades.txt");
    if (!in) {
        cout << "Unable to open the file" << endl;
        return 1;
    }

    cout << "Grades:\n";
    while (in >> g) {
        cout << g << endl;
    }
    in.close();

    int delGrade;
    cout << "Enter grade to delete: ";
    cin >> delGrade;

    ifstream x("grades.txt");
    ofstream temp("temp.txt");
    if (!x || !temp) {
        cout << "Unable to open the file" << endl;
        return 1;
    }

    while (x >> g) {
        if (g != delGrade) {
            temp << g << endl;
        }
    }
    x.close();
    temp.close();

    if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0) {
        cout << "Grade deleted successfully." << endl;
    } else {
        cout << "Error updating the file." << endl;
    }
}
    return 0;
}
