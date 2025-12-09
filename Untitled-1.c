#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// =================================================================================
// 1. STRUCTURE DEFINITIONS (Based on your Image)
// =================================================================================

struct Student {
    int StudentID;
    char Name[50];
    char Class[80];
};

struct mark {
    int StudentID;
    int SubjectID;
    float Adt_points;      // Attendance / Attitude points
    float mid_points;      // Midterm points
    float points;          // Final exam points
    float average_points;  // Calculated average
};

struct Subject {
    int SubjectID;
    char Subjectname[30];
    int Semester;
    char Teacher_name[30];
};

// =================================================================================
// 2. GLOBAL STORAGE
// =================================================================================

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 50
#define MAX_MARKS 1000

struct Student students[MAX_STUDENTS];
struct Subject subjects[MAX_SUBJECTS];
struct mark marks[MAX_MARKS];

int student_count = 0;
int subject_count = 0;
int mark_count = 0;

// =================================================================================
// 3. UTILITY FUNCTIONS
// =================================================================================

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Find index of student by ID
int find_student_index(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].StudentID == id) return i;
    }
    return -1;
}

// Find index of subject by ID
int find_subject_index(int id) {
    for (int i = 0; i < subject_count; i++) {
        if (subjects[i].SubjectID == id) return i;
    }
    return -1;
}

// =================================================================================
// 4. MANAGEMENT FUNCTIONS
// =================================================================================

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Student list is full.\n");
        return;
    }

    struct Student s;
    printf("\n--- Add New Student ---\n");
    printf("Enter Student ID: ");
    scanf("%d", &s.StudentID);
    clear_buffer();

    // Check if ID exists
    if (find_student_index(s.StudentID) != -1) {
        printf("Error: Student ID already exists!\n");
        return;
    }

    printf("Enter Name: ");
    fgets(s.Name, sizeof(s.Name), stdin);
    trim_newline(s.Name);

    printf("Enter Class: ");
    fgets(s.Class, sizeof(s.Class), stdin);
    trim_newline(s.Class);

    students[student_count++] = s;
    printf("Student added successfully!\n");
}

void add_subject() {
    if (subject_count >= MAX_SUBJECTS) {
        printf("Error: Subject list is full.\n");
        return;
    }

    struct Subject sub;
    printf("\n--- Add New Subject ---\n");
    printf("Enter Subject ID: ");
    scanf("%d", &sub.SubjectID);
    clear_buffer();

    if (find_subject_index(sub.SubjectID) != -1) {
        printf("Error: Subject ID already exists!\n");
        return;
    }

    printf("Enter Subject Name: ");
    fgets(sub.Subjectname, sizeof(sub.Subjectname), stdin);
    trim_newline(sub.Subjectname);

    printf("Enter Semester (Number): ");
    scanf("%d", &sub.Semester);
    clear_buffer();

    printf("Enter Teacher Name: ");
    fgets(sub.Teacher_name, sizeof(sub.Teacher_name), stdin);
    trim_newline(sub.Teacher_name);

    subjects[subject_count++] = sub;
    printf("Subject added successfully!\n");
}

void add_mark() {
    if (mark_count >= MAX_MARKS) {
        printf("Error: Mark storage is full.\n");
        return;
    }

    struct mark m;
    printf("\n--- Enter Marks ---\n");
    
    // 1. Select Student
    printf("Enter Student ID: ");
    scanf("%d", &m.StudentID);
    if (find_student_index(m.StudentID) == -1) {
        printf("Error: Student ID not found.\n");
        return;
    }

    // 2. Select Subject
    printf("Enter Subject ID: ");
    scanf("%d", &m.SubjectID);
    if (find_subject_index(m.SubjectID) == -1) {
        printf("Error: Subject ID not found.\n");
        return;
    }

    // 3. Enter Scores
    printf("Enter Attendance Points (Adt_points): ");
    scanf("%f", &m.Adt_points);

    printf("Enter Midterm Points (mid_points): ");
    scanf("%f", &m.mid_points);

    printf("Enter Final Points (points): ");
    scanf("%f", &m.points);

    // 4. Calculate Average 
    // Formula assumption: 10% Attendance + 40% Midterm + 50% Final
    m.average_points = (m.Adt_points * 0.1) + (m.mid_points * 0.4) + (m.points * 0.5);

    marks[mark_count++] = m;
    printf("Marks saved! Average calculated: %.2f\n", m.average_points);
}

// =================================================================================
// 5. DISPLAY FUNCTIONS
// =================================================================================

void display_students() {
    printf("\n%-10s %-30s %-20s\n", "ID", "Name", "Class");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-30s %-20s\n", 
            students[i].StudentID, students[i].Name, students[i].Class);
    }
}

void display_subjects() {
    printf("\n%-10s %-30s %-10s %-20s\n", "ID", "Subject Name", "Sem", "Teacher");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < subject_count; i++) {
        printf("%-10d %-30s %-10d %-20s\n", 
            subjects[i].SubjectID, subjects[i].Subjectname, 
            subjects[i].Semester, subjects[i].Teacher_name);
    }
}

void display_marks_report() {
    printf("\n%-15s %-20s %-20s %-10s\n", "Student Name", "Subject", "Teacher", "Average");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < mark_count; i++) {
        int s_idx = find_student_index(marks[i].StudentID);
        int sub_idx = find_subject_index(marks[i].SubjectID);

        if (s_idx != -1 && sub_idx != -1) {
            printf("%-15s %-20s %-20s %-10.2f\n",
                students[s_idx].Name,
                subjects[sub_idx].Subjectname,
                subjects[sub_idx].Teacher_name,
                marks[i].average_points
            );
        }
    }
}

// =================================================================================
// 6. MAIN MENU
// =================================================================================

int main() {
    // Pre-load some dummy data for testing
    struct Student s1 = {101, "Nguyen Van A", "IT-01"};
    students[student_count++] = s1;
    
    struct Subject sub1 = {501, "C Programming", 1, "Mr. Smith"};
    subjects[subject_count++] = sub1;

    int choice;
    do {
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. Add Subject\n");
        printf("3. Enter Marks for Student\n");
        printf("4. View All Students\n");
        printf("5. View All Subjects\n");
        printf("6. View Grade Report\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch(choice) {
            case 1: add_student(); break;
            case 2: add_subject(); break;
            case 3: add_mark(); break;
            case 4: display_students(); break;
            case 5: display_subjects(); break;
            case 6: display_marks_report(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}