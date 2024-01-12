#include "sinfo.h"
#include <stdio.h>
#include <stdlib.h>

// Function prototypes from other files
void add_student(struct sinfo st[], int *i);
void find_rl(struct sinfo st[], int i);
void find_fn(struct sinfo st[], int i);
void find_c(struct sinfo st[], int i);
void tot_s(int i);
void del_s(struct sinfo st[], int *i);
void up_s(struct sinfo st[], int i);
void export_students_to_csv(struct sinfo st[], int n);
int is_valid_gpa(float gpa);

// Function to compare students based on CGPA for sorting
int compare_students_by_cgpa(const void *a, const void *b) {
    const struct sinfo *student_a = (const struct sinfo *)a;
    const struct sinfo *student_b = (const struct sinfo *)b;

    // Compare CGPAs
    if (student_a->cgpa < student_b->cgpa) return -1;
    if (student_a->cgpa > student_b->cgpa) return 1;
    return 0;
}

void sort_students_by_cgpa(struct sinfo st[], int n) {
    // Sort students by CGPA
    qsort(st, n, sizeof(struct sinfo), compare_students_by_cgpa);

    // Print the sorted list
    printf("Students sorted by CGPA:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s %s, Matriculation Number: %d, CGPA: %.2f\n",
            st[i].fname, st[i].lname, st[i].matricnr, st[i].cgpa);
    }
}

int main() {
    struct sinfo st[MAX_STUDENTS];
    int i = 0;
    int choice;

    while (1) {
        printf("\nThe Task that you want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by Matriculation Number\n");
        printf("3. Find the Student Details by First Name\n");
        printf("4. Find the Student Details by Course Id\n");
        printf("5. Find the Total number of Students\n");
        printf("6. Delete the Students Details by Matriculation Number\n");
        printf("7. Update the Students Details by Matriculation Number\n");
        printf("8. Sort students by CGPA (ascending)\n");
        printf("9. Export student data to CSV\n");
        printf("10. To Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(st, &i);
                break;
            case 2:
                find_rl(st, i);
                break;
            case 3:
                find_fn(st, i);
                break;
            case 4:
                find_c(st, i);
                break;
            case 5:
                tot_s(i);
                break;
            case 6:
                del_s(st, &i);
                break;
            case 7:
                up_s(st, i);
                break;
            case 8:
                sort_students_by_cgpa(st, i);
                printf("Students sorted by CGPA (ascending).\n");
                break;
            case 9:
                export_students_to_csv(st, i);
                break;
            case 10:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
