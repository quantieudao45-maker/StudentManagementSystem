#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- DATA STRUCTURES ---

// Structure for Date (used for Date of Birth)
typedef struct {
    int day, month, year;
} Date;

// Structure for Student
typedef struct {
    int studentId;          // Ma sinh vien
    char fullName[50];      // Ho va ten
    Date dateOfBirth;       // Ngay sinh
    char address[100];      // Dia chi
    char phoneNumber[20];   // So dien thoai
    char className[20];     // Lop
} Student;

// Structure for Subject (Course) - Defined in video plan
typedef struct {
    char subjectId[20];
    char subjectName[50];
    int credits;
    char lecturer[50];
} Subject;

// Structure for Grades - Defined in video plan
typedef struct {
    int studentId;
    char subjectId[20];
    float attendanceScore;  // Diem chuyen can
    float midtermScore;     // Diem giua ky
    float finalScore;       // Diem thi
    float averageScore;     // Diem trung binh
} Grade;

// --- HELPER FUNCTIONS ---

// Function to remove the trailing newline character from fgets input
void removeNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// --- STUDENT MANAGEMENT FUNCTIONS ---

// Display the header for the student table
void printHeader() {
    printf("\n%-10s %-25s %-12s %-20s %-15s %-10s\n", 
           "ID", "Full Name", "Birth Date", "Address", "Phone", "Class");
    printf("------------------------------------------------------------------------------------------------\n");
}

// Display a single student's information
void printStudent(Student st) {
    printf("%-10d %-25s %02d/%02d/%04d   %-20s %-15s %-10s\n", 
           st.studentId, st.fullName, st.dateOfBirth.day, st.dateOfBirth.month, st.dateOfBirth.year, 
           st.address, st.phoneNumber, st.className);
}

// Display the list of all students
void showAllStudents(Student list[], int count) {
    printHeader();
    for (int i = 0; i < count; i++) {
        printStudent(list[i]);
    }
    printf("------------------------------------------------------------------------------------------------\n");
}

// Function to add a new student
void addStudent(Student list[], int *count) {
    printf("\n--- ADD NEW STUDENT (No. %d) ---\n", *count + 1);
    Student newStudent;
    
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.studentId);
    getchar(); // Clear input buffer

    printf("Enter Full Name: ");
    fgets(newStudent.fullName, sizeof(newStudent.fullName), stdin);
    removeNewline(newStudent.fullName);

    printf("Enter Date of Birth (day month year): ");
    scanf("%d%d%d", &newStudent.dateOfBirth.day, &newStudent.dateOfBirth.month, &newStudent.dateOfBirth.year);
    getchar(); // Clear input buffer

    printf("Enter Address: ");
    fgets(newStudent.address, sizeof(newStudent.address), stdin);
    removeNewline(newStudent.address);

    printf("Enter Phone Number: ");
    fgets(newStudent.phoneNumber, sizeof(newStudent.phoneNumber), stdin);
    removeNewline(newStudent.phoneNumber);

    printf("Enter Class Name: ");
    fgets(newStudent.className, sizeof(newStudent.className), stdin);
    removeNewline(newStudent.className);

    list[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to update an existing student by ID
void updateStudent(Student list[], int count) {
    int id;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (list[i].studentId == id) {
            found = 1;
            printf("Updating information for Student ID %d:\n", id);
            getchar(); // Clear buffer

            printf("Enter New Full Name: ");
            fgets(list[i].fullName, sizeof(list[i].fullName), stdin);
            removeNewline(list[i].fullName);

            printf("Enter New Date of Birth (day month year): ");
            scanf("%d%d%d", &list[i].dateOfBirth.day, &list[i].dateOfBirth.month, &list[i].dateOfBirth.year);
            getchar();

            printf("Enter New Address: ");
            fgets(list[i].address, sizeof(list[i].address), stdin);
            removeNewline(list[i].address);

            printf("Enter New Phone Number: ");
            fgets(list[i].phoneNumber, sizeof(list[i].phoneNumber), stdin);
            removeNewline(list[i].phoneNumber);

            printf("Enter New Class Name: ");
            fgets(list[i].className, sizeof(list[i].className), stdin);
            removeNewline(list[i].className);
            
            printf("Student updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to delete a student by ID
void deleteStudent(Student list[], int *count) {
    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < *count; i++) {
        if (list[i].studentId == id) {
            found = 1;
            // Shift subsequent elements to the left to fill the gap
            for (int j = i; j < *count - 1; j++) {
                list[j] = list[j + 1];
            }
            (*count)--;
            printf("Student with ID %d has been deleted.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to display students belonging to a specific class
void showStudentsByClass(Student list[], int count) {
    char targetClass[20];
    getchar(); // Clear buffer
    printf("\nEnter Class Name to filter: ");
    fgets(targetClass, sizeof(targetClass), stdin);
    removeNewline(targetClass);

    printf("\n--- LIST OF STUDENTS IN CLASS: %s ---\n", targetClass);
    printHeader();
    int foundCount = 0;
    for (int i = 0; i < count; i++) {
        // Compare strings (case-sensitive)
        if (strcmp(list[i].className, targetClass) == 0) {
            printStudent(list[i]);
            foundCount++;
        }
    }
    if (foundCount == 0) printf("No students found in this class.\n");
    else printf("------------------------------------------------------------------------------------------------\n");
}

// Function to search for a student by name (contains)
void searchByName(Student list[], int count) {
    char namePart[50];
    getchar();
    printf("\nEnter name to search: ");
    fgets(namePart, sizeof(namePart), stdin);
    removeNewline(namePart);

    printf("\n--- SEARCH RESULTS ---\n");
    printHeader();
    int found = 0;
    for(int i = 0; i < count; i++) {
        // strstr checks if namePart is contained in fullName
        if(strstr(list[i].fullName, namePart) != NULL) {
             printStudent(list[i]);
             found = 1;
        }
    }
    if (!found) printf("No students found matching that name.\n");
    printf("------------------------------------------------------------------------------------------------\n");
}

// --- MENUS ---

void studentMenu(Student list[], int *count) {
    int choice;
    do {
        printf("\n========== STUDENT MANAGEMENT ==========\n");
        printf("1. Display all students\n");
        printf("2. Add new student\n");
        printf("3. Update student info\n");
        printf("4. Delete student\n");
        printf("5. Search student by name\n");
        printf("6. Filter students by class\n");
        printf("0. Return to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: showAllStudents(list, *count); break;
            case 2: addStudent(list, count); break;
            case 3: updateStudent(list, *count); break;
            case 4: deleteStudent(list, count); break;
            case 5: searchByName(list, *count); break;
            case 6: showStudentsByClass(list, *count); break;
            case 0: break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

void mainMenu() {
    // Array to store students (In-memory database)
    Student studentList[100]; 
    int studentCount = 0;
    int choice;

    do {
        printf("\n========== MAIN SYSTEM MENU ==========\n");
        printf("1. Manage Students\n");
        printf("2. Manage Subjects (Coming Soon)\n");
        printf("3. Manage Grades (Coming Soon)\n");
        printf("0. Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                studentMenu(studentList, &studentCount);
                break;
            case 2:
                printf("Feature is under development.\n");
                break;
            case 3:
                printf("Feature is under development.\n");
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 0);
}

// --- MAIN ENTRY POINT ---

int main() {
    mainMenu();
    return 0;
}