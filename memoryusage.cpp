#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int id;
    string name;

public:

    Student(int i, string n) {
        id = i;
        name = n;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

void addStudent(vector<Student>& students) {
    int id;
    string name;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    students.push_back(Student(id, name));
    cout << "Student added successfully!\n";
}

void displayStudents(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\nStudent List:\n";
    for (Student s : students) {
        s.display();
    }
}

void removeStudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to remove: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getId() == id) {
            students.erase(it);
            cout << "Student removed successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void searchStudent(vector<Student>& students) {
    int choice;
    cout << "Search by: 1. ID  2. Name : ";
    cin >> choice;

    if (choice == 1) {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (Student s : students) {
            if (s.getId() == id) {
                s.display();
                return;
            }
        }
    } else if (choice == 2) {
        string name;
        cout << "Enter Name: ";
        cin >> name;

        for (Student s : students) {
            if (s.getName() == name) {
                s.display();
                return;
            }
        }
    }

    cout << "Student not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                removeStudent(students);
                break;
            case 4:
                searchStudent(students);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
};