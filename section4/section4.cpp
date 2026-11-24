#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;

    ofstream outFile("persons.txt");
    for (int i = 0; i < n; i++) {
        Person p;
        cout << "Enter name and age: ";
        cin >> p.name >> p.age;
        outFile << p.name << " " << p.age << endl;
    }
    outFile.close();

    ifstream inFile("persons.txt");
    vector<Person> people;
    Person temp;
    while (inFile >> temp.name >> temp.age) {
        people.push_back(temp);
    }
    inFile.close();

    Person youngest = people[0];
    Person oldest = people[0];

    for (int i = 1; i < people.size(); i++) {
        if (people[i].age < youngest.age) {
            youngest = people[i];
        }
        if (people[i].age > oldest.age) {
            oldest = people[i];
        }
    }

    ofstream resFile("results.txt");
    resFile << "Youngest: " << youngest.name << " " << youngest.age << endl;
    resFile << "Oldest: " << oldest.name << " " << oldest.age << endl;
    resFile.close();
    cout <<"okay";

    return 0;
}
