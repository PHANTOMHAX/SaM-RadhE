#include <stdio.h>

// Define the structure for student information
struct Student {
    int ID;
    char name[30];
    char grade;
    char subject[30];
    float marks;
};

int main() {
    // Declare an array of structures to store student information
    struct Student students[5];

    // Declare a pointer to a structure
    struct Student *ptr = students;

    // Input information for each student using pointer
    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &ptr->ID);

        printf("Name: ");
        scanf("%s", ptr->name);

        printf("Subject: ");
        scanf("%s", ptr->subject);

        printf("Marks: ");
        scanf("%f", &ptr->marks);

        // Calculate grade based on average marks
        ptr->grade = (ptr->marks >= 90) ? 'A' :
                     (ptr->marks >= 80) ? 'B' :
                     (ptr->marks >= 70) ? 'C' :
                     (ptr->marks >= 60) ? 'D' : 'F';

        // Move the pointer to the next structure in the array
        ptr++;
    }

    // Display the information and calculated grades
    printf("\nStudent Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d\n", students[i].ID);
        printf("Name: %s\n", students[i].name);
        printf("Subject: %s\n", students[i].subject);
        printf("Marks: %.2f\n", students[i].marks);
        printf("Grade: %c\n\n", students[i].grade);
    }

    return 0;
}
