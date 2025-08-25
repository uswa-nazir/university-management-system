
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int ID;
    string address;

public:
    Person(string n, int i, string a) {
        name = n;
        ID = i;
        address = a;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
    }
};

class Student : public Person {
private:
    string program;
    int year;
    double GPA;

public:
    Student(string n, int i, string a, string p, int y, double g) : Person(n, i, a) {
        program = p;
        year = y;
        GPA = g;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Program: " << program << endl;
        cout << "Year: " << year << endl;
        cout << "GPA: " << GPA << endl;
    }
};

class Faculty : public Person {
private:
    string department;
    string designation;

public:
    Faculty(string n, int i, string a, string d, string des) : Person(n, i, a) {
        department = d;
        designation = des;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string jobTitle;

public:
    Staff(string n, int i, string a, string d, string jt) : Person(n, i, a) {
        department = d;
        jobTitle = jt;
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Job Title: " << jobTitle << endl;
    }
};

int main() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Faculty" << endl;
    cout << "3. Staff" << endl;
    cin >> choice;

    string name, address;
    int ID;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter address: ";
    cin >> address;

    Person* person;

    switch (choice) {
        case 1: {
            string program;
            int year;
            double GPA;

            cout << "Enter program: ";
            cin >> program;
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter GPA: ";
            cin >> GPA;

            person = new Student(name, ID, address, program, year, GPA);
            break;
        }
        case 2: {
            string department, designation;

            cout << "Enter department: ";
            cin >> department;
            cout << "Enter designation: ";
            cin >> designation;

            person = new Faculty(name, ID, address, department, designation);
            break;
        }
        case 3: {
            string department, jobTitle;

            cout << "Enter department: ";
            cin >> department;
            cout << "Enter job title: ";
            cin >> jobTitle;

            person = new Staff(name, ID, address, department, jobTitle);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    person->displayInfo();

    delete person;

    return 0;
}



