#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 40
#define MAX_NAME 50
#define MAX_REGISTRATION 20

// Structure definitions
typedef struct {
    char course_code[20];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char the_grade;
} Grade;

typedef struct {
    char registration_number[MAX_REGISTRATION];
    char name[MAX_NAME];
    int age;
    Course course;
    Grade grade;
} Student;

// Array of students
Student students[MAX_STUDENTS];
int num_students = 0; // Current number of students

// Function to add a student
void addStudent(const char* registration_number, const char* name, int age, Course course) {
    if (num_students >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    strcpy(students[num_students].registration_number, registration_number);
    strcpy(students[num_students].name, name);
    students[num_students].age = age;
    students[num_students].course = course;
    num_students++;
}

// Function to edit a student's details
void editStudentDetails(int index, const char* name, int age) {
    if (index < 0 || index >= num_students) {
        printf("Invalid student index.\n");
        return;
    }
    strcpy(students[index].name, name);
    students[index].age = age;
}

// Function to add marks and calculate grades
void addMarksAndCalculateGrade(int index, int mark) {
    if (index < 0 || index >= num_students) {
        printf("Invalid student index.\n");
        return;
    }
    students[index].grade.mark = mark;
    if (mark > 69) students[index].grade.the_grade = 'A';
    else if (mark > 59) students[index].grade.the_grade = 'B';
    else if (mark > 49) students[index].grade.the_grade = 'C';
    else if (mark > 39) students[index].grade.the_grade = 'D';
    else students[index].grade.the_grade = 'E';
}

int main() {
    // Example of usage
    Course course1 = {"CS101", "Introduction to Computer Science"};
    addStudent("123", "John Doe", 20, course1);
    editStudentDetails(0, "John Doe Jr.", 21);
    addMarksAndCalculateGrade(0, 75);
    
    // Print the student's details to verify
    printf("Student: %s, Age: %d, Grade: %c\n", students[0].name, students[0].age, students[0].grade.the_grade);
    return 0;
}
