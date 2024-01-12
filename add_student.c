#include "sinfo.h"
#include <stdio.h>
#include <string.h>

void add_student(struct sinfo st[], int *i) {
    // Implementation of add_student function
    printf("Add the Students Details\n");
    printf("-------------------------\n");

    char tempFirstName[50];
    char tempLastName[50];
    int tempMatricNr;
    float tempCgpa;
    int tempCid[5];

    printf("Enter the first name of student\n");
    scanf("%49s", tempFirstName);
    strcpy(st[*i].fname, tempFirstName); // Copying using strcpy

    printf("Enter the last name of student\n");
    scanf("%49s", tempLastName);
    strcpy(st[*i].lname, tempLastName); // Copying using strcpy

    printf("Enter the Matriculation Number\n");
    scanf("%d", &tempMatricNr);
    st[*i].matricnr = tempMatricNr;

    // GPA Validation
    do {
        printf("Enter the CGPA you obtained (between 0 and 4.0)\n");
        scanf("%f", &tempCgpa);

        if (!is_valid_gpa(tempCgpa)) {
            printf("Invalid CGPA. Please enter a CGPA between 0 and 4.0\n");
        }
    } while (!is_valid_gpa(tempCgpa));

    st[*i].cgpa = tempCgpa;

    printf("Enter the course ID of each course\n");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &tempCid[j]);
        st[*i].cid[j] = tempCid[j];
    }
    getchar();
    *i = *i + 1;

}