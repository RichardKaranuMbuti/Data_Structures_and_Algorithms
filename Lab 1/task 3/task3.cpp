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
private:
    int mark;
    char the_grade;

public:
    Grade() : mark(0), the_grade('E') {} // Default constructor

    void setMark(int m) {
        if (m < 0 || m > 100) {
            cout << "Invalid mark. Must be between 0 and 100." << endl;
            return;
        }
        mark = m;
        calculateGrade();
    }

    char getGrade() const {
        return the_grade;
    }

private:
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
        grade.setMark(mark);
    }

    void printDetails() const {
        cout << "Registration Number: " << registration_number << endl
             << "Name: " << name << endl
             << "Age: " << age << endl
             << "Course Code: " << course.course_code << endl
             << "Course Name: " << course.course_name << endl
             << "Grade: " << grade.getGrade() << endl;
    }
};

vector<Student> students;

void addStudent(const Student& student) {
    if (students.size() >= 40) {
        cout << "Cannot add more students. Maximum capacity reached." << endl;
        return;
    }
    students.push_back(student);
}

int main() {
    // Example usage
    Course course1("CS101", "Introduction to Computer Science");

    Student student1("123456789", "John Doe", 20, course1);
    addStudent(student1);

    // Edit details
    students[0].editDetails("John Doe Jr.", 21);

    // Add marks and calculate grade
    students[0].addMarks(85);

    // Print details
    students[0].printDetails();

    return 0;
}
