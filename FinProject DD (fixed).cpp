//MINI PROJECT LAB C programming
// Nguyễn Mạnh Dũng
// Tạ Nguyễn Thiết Đính
#include <stdio.h>
#include <string.h>

// 1. STRUCT DECLARATION - Must be placed at the top
struct Birth {
    int date;
    int month;
    int year;
};

struct Student {
    int studentCode;
    char name[100];
    struct Birth birth; // Nested struct
    char address[100];
    char phoneNumber[15];
    char grade[10];
};

struct Subject {
    int subjectCode;
    char subjectName[100];
    int semester;
    int numberOfCredit;
    char teacherName[100];
};

struct Score {
    int studentCode;
    int subjectCode;
    float attendancePoint;
    float midtermScore;
    float testScore;
    float averageScore;
};

// 2. FUNCTION PROTOTYPES
void MainMenu();
void StudentManagingMenu();
void DisplayStudentList(struct Student students[], int numberOfStudents);

// 3. MAIN FUNCTION
int main() {
    int choice = 0;
    struct Student students[1000]; // Array to store up to 1000 students
    int numberOfStudents = 0;      // Current number of students

    do {
        MainMenu();
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("You have exited the program. Goodbye!\n");
                break;
            
            case 1: { // Student Management
                int studentMenuChoice = 0;
                do {
                    StudentManagingMenu();
                    printf("Enter your selection: ");
                    scanf("%d", &studentMenuChoice);
                    
                    switch (studentMenuChoice) {
                        case 0: break; // Return to main menu
                        case 1:
                            DisplayStudentList(students, numberOfStudents);
                            break;
                        case 2: printf("Feature: Add New Student (Not implemented yet)\n"); break;
                        case 3: printf("Feature: Update Information (Not implemented yet)\n"); break;
                        case 4: printf("Feature: Remove Student (Not implemented yet)\n"); break;
                        case 5: printf("Feature: Sort Students (Not implemented yet)\n"); break;
                        case 6: printf("Feature: Display by Class (Not implemented yet)\n"); break;
                        case 7: printf("Feature: Search by ID (Not implemented yet)\n"); break;
                        case 8: printf("Feature: Search by Name (Not implemented yet)\n"); break;
                        default: printf("Invalid selection, please try again!\n"); break;
                    }
                } while (studentMenuChoice != 0);
                break;
            }
            
            case 2:
                printf("Subject Management Feature (Not implemented yet)\n");
                break;
            
            case 3:
                printf("Score Management Feature (Not implemented yet)\n");
                break;
                
            default:
                printf("Invalid selection, please try again!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// 4. FUNCTION DEFINITIONS
void MainMenu() {
    printf("\n----- STUDENT MANAGEMENT SYSTEM -----\n");
    printf("1. Student Management\n");
    printf("2. Subject Management\n");
    printf("3. Score Management\n");
    printf("0. Exit Program\n");
    printf("-------------------------------------\n");
}

void StudentManagingMenu() {
    printf("\n----- STUDENT MENU -----\n");
    printf("1. Display Student List\n");
    printf("2. Add New Student\n");
    printf("3. Update Student Information\n");
    printf("4. Remove Student\n");
    printf("5. Sort Students\n");
    printf("6. Display List by Class\n");
    printf("7. Search by Student ID\n");
    printf("8. Search by Name\n");
    printf("0. Return to Main Menu\n");
    printf("------------------------\n");
}

void DisplayStudentList(struct Student students[], int numberOfStudents) {
    if (numberOfStudents == 0) {
        printf("\nThe student list is empty!\n");
        return;
    }
    
    // Header formatting
    printf("\n%-10s %-20s %-15s %-15s %-15s %-10s\n", 
           "ID", "Full Name", "Date of Birth", "Address", "Phone Number", "Class");
    
    // Print each student
    for (int i = 0; i < numberOfStudents; i++) {
        printf("%-10d %-20s %02d/%02d/%04d      %-15s %-15s %-10s\n",
               students[i].studentCode,
               students[i].name,
               students[i].birth.date, students[i].birth.month, students[i].birth.year,
               students[i].address,
               students[i].phoneNumber,
               students[i].grade);
    }
}