#include <stdio.h>

// Define the structure for student information
struct Student {
    int studentID;
    char name[50];
    char grade;
    char subject[50];
    float marks;
};

int main() {
    // Declare an array of structures to store student information
    struct Student students[5];

    // Input information for each student
    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Student ID: ");
        scanf("%d", &students[i].studentID);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Subject: ");
        scanf("%s", students[i].subject);

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        // Calculate grade based on average marks
        if (students[i].marks >= 90) {
            students[i].grade = 'A';
        } else if (students[i].marks >= 80) {
            students[i].grade = 'B';
        } else if (students[i].marks >= 70) {
            students[i].grade = 'C';
        } else if (students[i].marks >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }

    // Display the information and calculated grades
    printf("\nStudent Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student ID: %d\n", students[i].studentID);
        printf("Name: %s\n", students[i].name);
        printf("Subject: %s\n", students[i].subject);
        printf("Marks: %.2f\n", students[i].marks);
        printf("Grade: %c\n", students[i].grade);
        printf("\n");
    }

    return 0;
}
