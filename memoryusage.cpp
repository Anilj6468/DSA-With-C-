// ============================================================
//   STUDENT MANAGEMENT SYSTEM — C++ CLASS TEMPLATE
//   Features: Add, Display, Remove, Search + Memory Calc
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// ──────────────────────────────────────────────
//  CLASS TEMPLATE: Student
// ──────────────────────────────────────────────
class Student {
private:
    int    id;
    string name;

public:
    // ── Constructor to Initialize id and name ──
    Student(int studentId, string studentName)
        : id(studentId), name(studentName) {}

    // ── Getters ──
    int    getId()   const { return id;   }
    string getName() const { return name; }

    // ── Method: Display Student Details ──
    void displayDetails() const {
        cout << "  | ID   : " << id   << endl;
        cout << "  | Name : " << name << endl;
        cout << "  | Memory Size : " << sizeof(*this) + name.capacity()
             << " bytes" << endl;
        cout << "  +------------------------------" << endl;
    }

    // ── Memory size of this object ──
    size_t getMemorySize() const {
        return sizeof(*this) + name.capacity();
    }
};


// ──────────────────────────────────────────────
//  CLASS TEMPLATE: StudentManager
// ──────────────────────────────────────────────
class StudentManager {
private:
    vector<Student> students;   // Vector to hold all students

    // ── Helper: Calculate total memory used ──
    void showMemoryInfo() const {
        size_t totalMem = sizeof(students);
        for (const auto& s : students)
            totalMem += s.getMemorySize();

        cout << "\n  [MEMORY CALCULATE]" << endl;
        cout << "  Vector overhead     : " << sizeof(students) << " bytes" << endl;
        cout << "  Student count       : " << students.size()  << endl;
        cout << "  Total memory used   : " << totalMem         << " bytes" << endl;
        cout << "  Vector capacity     : " << students.capacity() << " slots" << endl;
    }

public:
    // ── TASK 1: Add a Student using push_back() ──
    void addStudent(int id, const string& name) {
        // Check for duplicate ID
        for (const auto& s : students) {
            if (s.getId() == id) {
                cout << "\n  [ERROR] Student with ID " << id
                     << " already exists!\n" << endl;
                return;
            }
        }
        students.push_back(Student(id, name));   // push_back()
        cout << "\n  [SUCCESS] Student \"" << name
             << "\" (ID: " << id << ") added successfully." << endl;
        showMemoryInfo();
    }

    // ── TASK 2: Display All Students ──
    void displayAll() const {
        if (students.empty()) {
            cout << "\n  [INFO] No students in the list.\n" << endl;
            return;
        }
        cout << "\n  ================================" << endl;
        cout << "      STUDENT LIST (" << students.size() << " record/s)" << endl;
        cout << "  ================================" << endl;
        for (const auto& s : students) {
            cout << "  +------------------------------" << endl;
            s.displayDetails();
        }

        // Memory summary
        size_t totalMem = sizeof(students);
        for (const auto& s : students)
            totalMem += s.getMemorySize();
        cout << "\n  [MEMORY] Total memory used by list: "
             << totalMem << " bytes\n" << endl;
    }

    // ── TASK 3: Remove a Student by ID ──
    void removeById(int id) {
        auto it = find_if(students.begin(), students.end(),
            [id](const Student& s) { return s.getId() == id; });

        if (it == students.end()) {
            cout << "\n  [ERROR] Student with ID " << id
                 << " not found.\n" << endl;
        } else {
            cout << "\n  [SUCCESS] Removed student: \"" << it->getName()
                 << "\" (ID: " << id << ")" << endl;
            students.erase(it);
            showMemoryInfo();
        }
    }

    // ── TASK 4: Search for a Student by ID ──
    void searchById(int id) const {
        cout << "\n  [SEARCH] Looking for ID: " << id << " ..." << endl;
        for (const auto& s : students) {
            if (s.getId() == id) {
                cout << "  [FOUND]" << endl;
                cout << "  +------------------------------" << endl;
                s.displayDetails();
                return;
            }
        }
        cout << "  [NOT FOUND] No student with ID " << id << endl;
    }

    // ── BONUS: Search by Name ──
    void searchByName(const string& name) const {
        cout << "\n  [SEARCH] Looking for name: \"" << name << "\" ..." << endl;
        bool found = false;
        for (const auto& s : students) {
            if (s.getName() == name) {
                if (!found) {
                    cout << "  [FOUND]" << endl;
                    cout << "  +------------------------------" << endl;
                }
                s.displayDetails();
                found = true;
            }
        }
        if (!found)
            cout << "  [NOT FOUND] No student named \"" << name << "\"\n" << endl;
    }
};


// ──────────────────────────────────────────────
//  MENU-DRIVEN MAIN FUNCTION
// ──────────────────────────────────────────────
int main() {
    StudentManager manager;
    int choice;

    cout << "============================================" << endl;
    cout << "    STUDENT MANAGEMENT SYSTEM (C++)         " << endl;
    cout << "    With Memory Calculate Feature           " << endl;
    cout << "============================================" << endl;

    do {
        cout << "\n  ── MENU ──────────────────────────" << endl;
        cout << "  1. Add Student" << endl;
        cout << "  2. Display All Students" << endl;
        cout << "  3. Remove Student by ID" << endl;
        cout << "  4. Search Student by ID" << endl;
        cout << "  5. Search Student by Name" << endl;
        cout << "  0. Exit" << endl;
        cout << "  ──────────────────────────────────" << endl;
        cout << "  Enter your choice: ";
        cin  >> choice;
        cin.ignore();  // clear newline from buffer

        switch (choice) {

            case 1: {   // ADD STUDENT
                int    id;
                string name;
                cout << "\n  Enter Student ID   : ";
                cin  >> id;
                cin.ignore();
                cout << "  Enter Student Name : ";
                getline(cin, name);
                manager.addStudent(id, name);
                break;
            }

            case 2:     // DISPLAY ALL
                manager.displayAll();
                break;

            case 3: {   // REMOVE BY ID
                int id;
                cout << "\n  Enter Student ID to remove: ";
                cin  >> id;
                manager.removeById(id);
                break;
            }

            case 4: {   // SEARCH BY ID
                int id;
                cout << "\n  Enter Student ID to search: ";
                cin  >> id;
                manager.searchById(id);
                break;
            }

            case 5: {   // SEARCH BY NAME
                string name;
                cin.ignore();
                cout << "\n  Enter Student Name to search: ";
                getline(cin, name);
                manager.searchByName(name);
                break;
            }

            case 0:
                cout << "\n  Exiting... Goodbye!\n" << endl;
                break;

            default:
                cout << "\n  [ERROR] Invalid choice. Try again.\n" << endl;
        }

    } while (choice != 0);

    return 0;
}

// ============================================================
//  HOW TO COMPILE & RUN:
//
//  Step 1 — Compile:
//     g++ -std=c++17 -o student_management student_management.cpp
//
//  Step 2 — Run:
//     ./student_management          (Linux/Mac)
//     student_management.exe        (Windows)
// ============================================================
