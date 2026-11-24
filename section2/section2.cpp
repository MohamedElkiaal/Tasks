#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("fruit.txt");
    if (!inFile.is_open()) {
        cout << "Error opening fruit.txt" << endl;
        return 1;
    }

    string line;
    cout << "Fruits in file:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening fruit.txt for appending" << endl;
        return 1;
    }

    outFile << "Fresh Fruits" << endl;
    outFile.close();

    return 0;
}
