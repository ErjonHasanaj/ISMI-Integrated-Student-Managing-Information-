#include "sinfo.h"
#include <stdio.h>

// Function to print the total number of students
void tot_s(int i) {
    printf("The total number of students is %d\n", i);
    printf("You can have a maximum of 50 students.\n");
    printf("You can have %d more students.\n", 50 - i);
}

// Function to delete a student by the roll number
void del_s(struct sinfo st[], int *i) {
    int a;
    printf("Enter the Matriculation Number which you want to delete\n");
    scanf("%d", &a);
    int found = 0;

    for (int j = 0; j < *i; j++) {
        if (a == st[j].matricnr) {
            for (int k = j; k < *i - 1; k++) {
                st[k] = st[k + 1];
            }
            *i = *i - 1;
            found = 1;
            printf("The Matriculation Number %d is removed successfully.\n", a);
            break;
        }
    }

    if (!found) {
        printf("Student with Matriculation Number %d not found.\n", a);
    }
}

// Function to update a student's data
void up_s(struct sinfo st[], int i) {
    int x;
    printf("Enter the Matriculation number to update the entry: ");
    scanf("%d", &x);

    for (int j = 0; j < i; j++) {
        if (st[j].matricnr == x) {
            printf("1. First name\n2. Last name\n3. Matriculation no.\n4. CGPA\n5. Courses\n");
            int z;
            scanf("%d", &z);
            switch (z) {
                case 1:
                    printf("Enter the new first name: \n");
                    scanf("%49s", st[j].fname);
                    break;
                case 2:
                    printf("Enter the new last name: \n");
                    scanf("%49s", st[j].lname);
                    break;
                case 3:
                    printf("Enter the new matriculation number: \n");
                    scanf("%d", &st[j].matricnr);
                    break;
                case 4:
                    printf("Enter the new CGPA: \n");
                    scanf("%f", &st[j].cgpa);
                    break;
                case 5:
                    printf("Enter the new course IDs \n");
                    for (int k = 0; k < 5; k++) {
                        scanf("%d", &st[j].cid[k]);
                    }
                    break;
                default:
                    printf("Invalid option.\n");
            }
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", x);
}

