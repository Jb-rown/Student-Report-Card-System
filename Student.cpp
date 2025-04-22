#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {} // Default constructor

Student::Student(int id, const string& name, const vector<float>& marks) // Parameterized constructor
    : id(id), name(name), marks(marks) {
    calculateAverageAndGrade();
}

void Student::calculateAverageAndGrade() { // Calculate average and grade
    float total = 0;
    for (float mark : marks) total += mark;
    average = marks.empty() ? 0 : total / marks.size();

    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'F';
}

void Student::displayReportCard() const {
    cout << "ID: " << id << "\nName: " << name << "\nMarks: ";
    for (float mark : marks) cout << mark << " ";
    cout << "\nAverage: " << average << "\nGrade: " << grade << "\n";
}

int Student::getId() const {
    return id;
}

string Student::getName() const { // Get student name
    return name;
}

void Student::updateMarks(const vector<float>& newMarks) { // Update marks and recalculate average and grade
    marks = newMarks;
    calculateAverageAndGrade();
}
