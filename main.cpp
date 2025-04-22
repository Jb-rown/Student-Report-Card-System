#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    vector<float> marks = {85, 90, 78}; // Sample marks
    // Create a Student object using the parameterized constructor
    Student student1(1, "John Brown", marks);

    cout << "Student Report Card\n-------------------\n";
    student1.displayReportCard();

    return 0;
}
