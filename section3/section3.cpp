#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("welcome.txt");
    if (!file.is_open()) {
        cout << "Error opening the file";
    }
    else {
        file << "Hello Everybody";
        cout << "Before update  Hello Everybody"<<endl;
        file.seekp(11);
        file << "one ";
        cout << "After update  Hello Everyone"<<endl;
    }
    file.close();
    return 0;
}
