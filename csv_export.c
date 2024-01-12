#include <stdio.h>   // For file operations
#include "sinfo.h"   // For the student structure definition

// Function to export student data to a CSV file
void export_students_to_csv(struct sinfo st[], int n) {
    FILE *file = fopen("student_data.csv", "w");
    if (file == NULL) {
        printf("Error opening the CSV file\n");
        return;
    }

    // Write CSV header
    fprintf(file, "First Name,Last Name,Matric Number,CGPA,Course IDs\n");

    // Write student data
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%s,%d,%.2f,", st[i].fname, st[i].lname, st[i].matricnr, st[i].cgpa);

        // Write course IDs
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%d", st[i].cid[j]);
            if (j < 4) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Student data exported to student_data.csv\n");
}
