#include "ReportCardSystem.h"
#include <iostream>
using namespace std;

void ReportCardSystem::addStudent() {
    int id;
    string name;
    int numSubjects;
    vector<float> marks;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    for (int i = 0; i < numSubjects; i++) {
        float mark;
        cout << "Enter mark for subject " << i + 1 << ": ";
        cin >> mark;
        marks.push_back(mark);
    }

    Student newStudent(id, name, marks);
    students.push_back(newStudent);

    cout << "✅ Student added successfully!\n";
}

void ReportCardSystem::displayAllStudents() const {
    if (students.empty()) {
        cout << "⚠️ No student records found.\n";
        return;
    }

    for (const auto& student : students) {
        cout << "\n-----------------------------\n";
        student.displayReportCard();
    }
}

void ReportCardSystem::run() {
    int choice;

    do {
        cout << "\n===== Student Report Card Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 0:
                cout << "👋 Exiting... Goodbye!\n";
                break;
            default:
                cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
