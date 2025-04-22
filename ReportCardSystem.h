#ifndef REPORTCARDSYSTEM_H
#define REPORTCARDSYSTEM_H

#include "Student.h"
#include <vector>

class ReportCardSystem {
private:
    std::vector<Student> students;

public:
    void addStudent();
    void displayAllStudents() const;
    void searchStudentById() const;
    void updateStudentById();
    void deleteStudentById();

    void run();  // CLI menu loop
};

#endif
