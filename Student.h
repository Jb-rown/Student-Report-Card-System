#ifndef STUDENT_H 
#define STUDENT_H  

#include <string> 
#include <vector>

class Student {
private:
    int id;
    std::string name; 
    std::vector<float> marks;
    float average;
    char grade;

public:
    Student(); 
    Student(int id, const std::string& name, const std::vector<float>& marks); 

    void calculateAverageAndGrade(); 
    void displayReportCard() const;

    int getId() const;
    std::string getName() const; // std::string getName() const { return name; }

    // Future features
    void updateMarks(const std::vector<float>& newMarks);
};

#endif 
