#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_UNITS 10
#define MAX_STUDENTS 10

/* ---------- STRUCT DEFINITIONS ---------- */
typedef struct {
    char unitCode[10];
    char unitName[30];
} Unit;

typedef struct {
    char username[20];
    float score;
} Student;

/* ---------- GLOBAL DATA ---------- */
Unit units[MAX_UNITS];
Student students[MAX_STUDENTS];
int unitCount = 0;
int studentCount = 0;

/* ---------- FUNCTION DECLARATIONS ---------- */
void mainMenu();
void login();

void teacherMenu();
void listUnits();
void addUnit();
void deleteUnit();
void listStudentsInUnit();
void unitStatistics();

void studentMenu();
void listAvailableUnits();
void enrollUnit();
void dropUnit();
void checkScores();
void generateRandomScore();

/* ---------- MAIN ---------- */
int main() {
    srand(time(NULL));
    mainMenu();
    return 0;
}

/* ---------- MAIN MENU ---------- */
void mainMenu() {
    int choice;
    do {
        printf("\n==============================\n");
        printf("   STUDENT MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("==============================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            login();
        else if (choice == 2)
            printf("Exiting program...\n");
        else
            printf("Invalid choice!\n");

    } while (choice != 2);
}

/* ---------- LOGIN ---------- */
void login() {
    char username[20];

    printf("\nEnter username: ");
    scanf("%s", username);

    if (strcmp(username, "teacher01") == 0) {
        teacherMenu();
    } else if (strcmp(username, "student01") == 0) {
        studentMenu();
    } else {
        printf("Invalid user!\n");
    }
}

/* ================= TEACHER FUNCTIONS ================= */

void teacherMenu() {
    int choice;
    do {
        printf("\n==============================\n");
        printf("   TEACHER MENU (teacher01)\n");
        printf("==============================\n");
        printf("1. List my teaching units\n");
        printf("2. Add a new unit\n");
        printf("3. Delete a unit\n");
        printf("4. List students in a unit\n");
        printf("5. Show unit statistics\n");
        printf("6. Logout\n");
        printf("==============================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: listUnits(); break;
            case 2: addUnit(); break;
            case 3: deleteUnit(); break;
            case 4: listStudentsInUnit(); break;
            case 5: unitStatistics(); break;
            case 6: printf("Logging out...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
}

void listUnits() {
    int i;
    printf("\n--- Teaching Units ---\n");
    for (i = 0; i < unitCount; i++) {
        printf("%d. %s - %s\n", i + 1, units[i].unitCode, units[i].unitName);
    }
}

void addUnit() {
    if (unitCount >= MAX_UNITS) {
        printf("Unit list is full!\n");
        return;
    }
    printf("Enter unit code: ");
    scanf("%s", units[unitCount].unitCode);
    printf("Enter unit name: ");
    scanf(" %[^\n]", units[unitCount].unitName);
    unitCount++;
    printf("Unit added successfully!\n");
}

void deleteUnit() {
    char code[10];
    int i, j;
    printf("Enter unit code to delete: ");
    scanf("%s", code);

    for (i = 0; i < unitCount; i++) {
        if (strcmp(units[i].unitCode, code) == 0) {
            for (j = i; j < unitCount - 1; j++) {
                units[j] = units[j + 1];
            }
            unitCount--;
            printf("Unit deleted!\n");
            return;
        }
    }
    printf("Unit not found!\n");
}

void listStudentsInUnit() {
    printf("\nStudents enrolled: %d\n", studentCount);
}

void unitStatistics() {
    printf("\nTotal units: %d\n", unitCount);
}

/* ================= STUDENT FUNCTIONS ================= */

void studentMenu(const char *user_id) {
    int choice;
    do {
        printf("\n==============================\n");
        printf("   STUDENT MENU (%s)\n", user_id);
        printf("==============================\n");
        printf("1. List available units\n");
        printf("2. List my enrolled units\n");
        printf("3. Enroll in a unit\n");
        printf("4. Drop a unit\n");
        printf("5. Check my scores\n");
        printf("6. Generate random score (TEST)\n");
        printf("7. Logout\n");
        printf("==============================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: listAvailableUnits(); break;
            case 2: listAvailableUnits(); break;
            case 3: enrollUnit(); break;
            case 4: dropUnit(); break;
            case 5: checkScores(); break;
            case 6: generateRandomScore(); break;
            case 7: printf("Logging out...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);
}

void listAvailableUnits() {
    listUnits();
}

void enrollUnit() {
    printf("Enroll feature simulated.\n");
}

void dropUnit() {
    printf("Drop feature simulated.\n");
}

void checkScores() {
    int i;
    for (i = 0; i < studentCount; i++) {
        printf("%s - Score: %.2f\n", students[i].username, students[i].score);
    }
}

void generateRandomScore() {
    if (studentCount >= MAX_STUDENTS) return;
    strcpy(students[studentCount].username, "student01");
    students[studentCount].score = (rand() % 101) / 10.0;
    studentCount++;
    printf("Random score generated!\n");
}
