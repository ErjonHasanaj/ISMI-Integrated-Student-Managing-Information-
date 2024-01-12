#include <sinfo.h>
#include <stdio.h>
#include <string.h>

void find_rl(struct sinfo st[], int i) {
    int x;
    printf("Enter the Matriculation Number of the student\n");
    scanf("%d", &x); // Get roll number from user input

    int found = 0; // Flag to check if student is found

    // Iterating through all the students
    for (int j = 0; j < i; j++) {
        // If the roll number is found
        if (x == st[j].matricnr) {
            printf("The Student's Details are:\n");
            printf("The First name is %s\n", st[j].fname);
            printf("The Last name is %s\n", st[j].lname);
            printf("The CGPA is %f\n", st[j].cgpa);

            // Printing the courses in which the student is enrolled
            for (int k = 0; k < 5; k++) {
                printf("The course ID is %d\n", st[j].cid[k]);
            }
            found = 1;
            break; // Exit the loop as we found the student
        }
    }

    if (!found) {
        printf("Student with Matriculation Number %d not found.\n", x);
    }
}

void find_fn(struct sinfo st[], int i) {
    char a[50];
    printf("Enter the First Name of the student\n");
    scanf("%49s", a); // Read first name from user input

    int found = 0; // Flag to check if student is found

    // Iterating through the students list
    for (int j = 0; j < i; j++) {
        // Compare the first names
        if (!strcmp(st[j].fname, a)) {
            printf("The Student's Details are:\n");
            printf("The First name is %s\n", st[j].fname);
            printf("The Last name is %s\n", st[j].lname);
            printf("The Roll Number is %d\n", st[j].matricnr);
            printf("The CGPA is %f\n", st[j].cgpa);

            // Print the course IDs
            for (int k = 0; k < 5; k++) {
                printf("The course ID is %d\n", st[j].cid[k]);
            }
            found = 1;
            break; // Found a student, break out of the loop
        }
    }

    if (!found) {
        printf("No student found with the First Name '%s'.\n", a);
    }
}

void find_c(struct sinfo st[], int i) {
    int id;
    printf("Enter the course ID\n");
    scanf("%d", &id);  // Get course ID from user input

    int found = 0;  // Flag to check if any student is enrolled in the course

    // Iterating through all the students
    for (int j = 0; j < i; j++) {
        // Check if the student is enrolled in the course
        for (int k = 0; k < 5; k++) {
            if (id == st[j].cid[k]) {
                printf("Student Details:\n");
                printf("First Name: %s\n", st[j].fname);
                printf("Last Name: %s\n", st[j].lname);
                printf("Matriculation Number: %d\n", st[j].matricnr);
                printf("CGPA: %f\n", st[j].cgpa);
                found = 1;
                // No need to break here as we want to find all students in the course
            }
        }
    }

    if (!found) {
        printf("No students found enrolled in Course ID %d.\n", id);
    }
}


