#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
public:
    string course_code;
    string course_name;
    Course(string code, string name) : course_code(code), course_name(name) {}
};

class Grade {
public:
    int mark;
    char the_grade;
    void calculateGrade() {
        if (mark > 69) the_grade = 'A';
        else if (mark > 59) the_grade = 'B';
        else if (mark > 49) the_grade = 'C';
        else if (mark > 39) the_grade = 'D';
        else the_grade = 'E';
    }
};

class Student {
public:
    string registration_number;
    string name;
    int age;
    Course course;
    Grade grade;

    Student(string regNo, string name, int age, Course course) : registration_number(regNo), name(name), age(age), course(course) {}

    void editDetails(string newName, int newAge) {
        name = newName;
        age = newAge;
    }

    void addMarks(int mark) {
        grade.mark = mark;
        grade.calculateGrade();
    }
};

vector<Student> students;

void addStudent(string registration_number, string name, int age, Course course) {
    if (students.size() >= 40) {
        cout << "Cannot add more students." << endl;
        return;
    }
    Student student(registration_number, name, age, course);
    students.push_back(student);
}

int main() {
    // Example usage
    Course course1("CS101", "Introduction to Computer Science");
    addStudent("123", "Felix Oloo", 20, course1);
    students[0].editDetails("Richard Karanu.", 21);
    students[0].addMarks(85);

    // Print the student's details to verify
    cout << "Student: " << students[0].name << ", Age: " << students[0].age << ", Grade: " << students[0].grade.the_grade << endl;
    return 0;
}

