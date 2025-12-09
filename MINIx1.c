#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- DATA STRUCTURES ---

// Structure for Date of Birth
typedef struct {
    int day, month, year;
} Date;

// Structure for Student
typedef struct {
    int studentId;
    char fullName[50];
    Date dob; // Date of Birth
    char address[100];
    char phoneNumber[20];
    char className[20];
} Student;

// Structure for Subject (Course)
typedef struct {
    char subjectId[20];
    char subjectName[50];
    int credits;
    char lecturer[50];
} Subject;

// Structure for Grades
typedef struct {
    int studentId;
    char subjectId[20];
    float attendanceScore;
    float midtermScore;
    float finalScore;
    float averageScore;
} Grade;

// --- HELPER FUNCTIONS ---

// Function to remove the newline character from fgets
void removeNewline(char x[]) {
    size_t len = strlen(x);
    if (len > 0 && x[len - 1] == '\n') {
        x[len - 1] = '\0';
    }
}

// --- STUDENT MANAGEMENT FUNCTIONS ---

void displayHeader() {
    printf("\n%-10s %-20s %-12s %-15s %-15s %-10s\n", 
           "ID", "Full Name", "DOB", "Address", "Phone", "Class");
    printf("----------------------------------------------------------------------------------\n");
}

void displayStudent(Student sv) {
    printf("%-10d %-20s %02d/%02d/%04d   %-15s %-15s %-10s\n", 
           sv.studentId, sv.fullName, sv.dob.day, sv.dob.month, sv.dob.year, 
           sv.address, sv.phoneNumber, sv.className);
}

void displayStudentList(Student arr[], int n) {
    displayHeader();
    for (int i = 0; i < n; i++) {
        displayStudent(arr[i]);
    }
    printf("----------------------------------------------------------------------------------\n");
}

void addStudent(Student arr[], int *n) {
    printf("\n--- ADD NEW STUDENT (No. %d) ---\n", *n + 1);
    Student sv;
    
    printf("Enter Student ID: ");
    scanf("%d", &sv.studentId);
    getchar(); // Clear input buffer

    printf("Enter Full Name: ");
    fgets(sv.fullName, sizeof(sv.fullName), stdin);
    removeNewline(sv.fullName);

    printf("Enter Date of Birth (day month year): ");
    scanf("%d%d%d", &sv.dob.day, &sv.dob.month, &sv.dob.year);
    getchar();

    printf("Enter Address: ");
    fgets(sv.address, sizeof(sv.address), stdin);
    removeNewline(sv.address);

    printf("Enter Phone Number: ");
    fgets(sv.phoneNumber, sizeof(sv.phoneNumber), stdin);
    removeNewline(sv.phoneNumber);

    printf("Enter Class Name: ");
    fgets(sv.className, sizeof(sv.className), stdin);
    removeNewline(sv.className);

    arr[*n] = sv;
    (*n)++;
    printf("Student added successfully!\n");
}

void updateStudent(Student arr[], int n) {
    int id;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i].studentId == id) {
            found = 1;
            printf("Enter new information for student ID %d:\n", id);
            getchar(); // Clear input buffer

            printf("Enter Full Name: ");
            fgets(arr[i].fullName, sizeof(arr[i].fullName), stdin);
            removeNewline(arr[i].fullName);

            printf("Enter Date of Birth (day month year): ");
            scanf("%d%d%d", &arr[i].dob.day, &arr[i].dob.month, &arr[i].dob.year);
            getchar();

            printf("Enter Address: ");
            fgets(arr[i].address, sizeof(arr[i].address), stdin);
            removeNewline(arr[i].address);

            printf("Enter Phone Number: ");
            fgets(arr[i].phoneNumber, sizeof(arr[i].phoneNumber), stdin);
            removeNewline(arr[i].phoneNumber);

            printf("Enter Class Name: ");
            fgets(arr[i].className, sizeof(arr[i].className), stdin);
            removeNewline(arr[i].className);
            
            printf("Student updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent(Student arr[], int *n) {
    int id;
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);
    int found = 0;

    for (int i = 0; i < *n; i++) {
        if (arr[i].studentId == id) {
            found = 1;
            // Shift elements to the left
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            printf("Student with ID %d has been deleted.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student not found for deletion.\n");
    }
}

void displayStudentsByClass(Student arr[], int n) {
    char classToFind[20];
    getchar(); // Clear buffer from previous input
    printf("\nEnter Class Name to filter: ");
    fgets(classToFind, sizeof(classToFind), stdin);
    removeNewline(classToFind);

    printf("\n--- STUDENT LIST FOR CLASS: %s ---\n", classToFind);
    displayHeader();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].className, classToFind) == 0) {
            displayStudent(arr[i]);
            count++;
        }
    }
    if (count == 0) printf("No students found in this class.\n");
    else printf("----------------------------------------------------------------------------------\n");
}

void searchByName(Student arr[], int n) {
    char nameToFind[50];
    getchar();
    printf("\nEnter name to search: ");
    fgets(nameToFind, sizeof(nameToFind), stdin);
    removeNewline(nameToFind);

    printf("\nSearch Results:\n");
    displayHeader();
    for(int i = 0; i < n; i++) {
        if(strstr(arr[i].fullName, nameToFind) != NULL) {
             displayStudent(arr[i]);
        }
    }
    printf("----------------------------------------------------------------------------------\n");
}

// --- MENUS ---

void studentMenu(Student arr[], int *n) {
    int choice;
    do {
        printf("\n=== STUDENT MANAGEMENT ===\n");
        printf("1. Display student list\n");
        printf("2. Add new student\n");
        printf("3. Update student info\n");
        printf("4. Delete student\n");
        printf("5. Search student by name\n");
        printf("6. Filter students by class\n");
        printf("0. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayStudentList(arr, *n); break;
            case 2: addStudent(arr, n); break;
            case 3: updateStudent(arr, *n); break;
            case 4: deleteStudent(arr, n); break;
            case 5: searchByName(arr, *n); break;
            case 6: displayStudentsByClass(arr, *n); break;
            case 0: break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

void mainMenu() {
    Student studentList[100];
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== STUDENT MANAGEMENT SYSTEM ===\n");
        printf("1. Student Management\n");
        printf("2. Subject Management (Under development)\n");
        printf("3. Grade Management (Under development)\n");
        printf("0. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                studentMenu(studentList, &studentCount);
                break;
            case 2:
                printf("Feature under development...\n");
                break;
            case 3:
                printf("Feature under development...\n");
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (choice != 0);
}

int main() {
    mainMenu();
    return 0;
}