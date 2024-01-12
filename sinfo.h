#ifndef SINFO_H
#define SINFO_H

#define MAX_STUDENTS 55
#define MAX_COURSES 5

// Structure to store the student
struct sinfo {
    char fname[50];
    char lname[50];
    int matricnr;
    float cgpa;
    int cid[MAX_COURSES];
};

// Function prototypes
void add_student(struct sinfo st[], int *i);
void find_rl(struct sinfo st[], int i);
void find_fn(struct sinfo st[], int i);
void find_c(struct sinfo st[], int i);
void tot_s(int i);
void del_s(struct sinfo st[], int *i);
void up_s(struct sinfo st[], int i);
void export_students_to_csv(struct sinfo st[], int n);
int is_valid_gpa(float gpa);

#endif
