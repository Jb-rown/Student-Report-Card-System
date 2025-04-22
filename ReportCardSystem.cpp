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
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudentById(); break;
            case 4: updateStudentById(); break;
            case 5: deleteStudentById(); break;
            case 0: cout << "👋 Exiting... Goodbye!\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    
}

void ReportCardSystem::searchStudentById() const {
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;

    for (const auto& student : students) {
        if (student.getId() == searchId) {
            cout << "\n🎯 Student found:\n";
            student.displayReportCard();
            return;
        }
    }

    cout << "❌ Student not found.\n";
}

void ReportCardSystem::updateStudentById() {
    int searchId;
    cout << "Enter student ID to update: ";
    cin >> searchId;

    for (auto& student : students) {
        if (student.getId() == searchId) {
            int numSubjects;
            vector<float> newMarks;
            cout << "Enter number of subjects: ";
            cin >> numSubjects;

            for (int i = 0; i < numSubjects; i++) {
                float mark;
                cout << "Enter mark for subject " << i + 1 << ": ";
                cin >> mark;
                newMarks.push_back(mark);
            }

            student.updateMarks(newMarks);
            cout << "✅ Marks updated successfully.\n";
            return;
        }
    }

    cout << "❌ Student not found.\n";
}

void ReportCardSystem::deleteStudentById() {
    int deleteId;
    cout << "Enter student ID to delete: ";
    cin >> deleteId;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == deleteId) {
            students.erase(it);
            cout << "🗑️ Student deleted successfully.\n";
            return;
        }
    }

    cout << "❌ Student not found.\n";
}
