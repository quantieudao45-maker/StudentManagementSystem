//MINI PROJECT LAB C programming
// Nguyễn Mạnh Dũng
// Tạ Nguyễn Thiết Đính
#include <stdio.h>
#include <string>
struct Birth
{
    int date;
    int month;
    int year;
};
struct Student
struct score
struct subject
void MainMenu()
void StudentManagingMenu()
void DisplayStudentList( struct Student ArrStudent[], int NumberOfStudent)
{
    printf("DisplayStudentList \n");
    printf("studentCode\t Name\t Birth\t Address\t PhoneNumber\t Grade\n");
    for (int i = 0; i<NumberOfStudent; i++) {
        printf("%d \t %s \t %d\\%d\\%d\t %s\t%s\t %s \n",ArrStudent[i].StudentCode,ArrStudent[i].Birth.month,ArrStudent[i].Birth.year,ArrStudent[i].address,ArrStudent[i].PhoneNumber,ArrStudent[i].grade);

    }

}
{
    int studentCode;
    char Name[100];
    struct Birth birth 
    char address[100]
    char Phonenumber[10]
    char grade[10]
};
struct Score
{
    int stdudentCode;
    int subjectCode;
    float attendancePoint;
    float midtermScore;
    float testScore;
    float averageScore;
};
struct Subject{
    int subjectCode;
    char subjectName[100]
    int semester;
    int numberofCredit;
    char teacherName[100];
};
void MainMenu(){
    printf("-----Student Managing System-----\n");
    printf("0. Exit the program\n");
    printf("1. Student Managing\n");
    printf("2. Managing subject\n");
    printf("3. Managing score\n");
    printf("---------------------------------\n");
}
void StudentManagingMenu()
{
    printf("-----Student Managing-----\n");
    printf("0. Exit the program\n");
    printf("1. display student list \n");
    printf("2. More information student\n");
    printf("3. Update student information\n");
    printf("4. Remove student from list\n");    
    printf("5. Sort students by first and last name\n");
    printf("6. Display list of students by class\n");
    printf("7. Search for students by student code\n");
    printf("8. Search for students by name\n");
    printf("---------------------------------\n");
}

int main() 
{
    int choose = 0
    struct student ArrStudent[1000]; 
    int NumberOfStudent = 0;
    do
    {
        MainMenu();
        printf("Enter your selection: "); 
        scanf("%d", &choose);
        switch(choose)
        {
        case 0;
        }
    

   

        
        case 0;
        { 
            printf("you have exited the program!\n");
            break;
        }
        case 1;
        {   
        int chooseStudentManaging=0;
        do
        { 
            StudentManagingMenu();
            printf("Enter your selection: "); 
            scanf("%d", &chooseStudentManaging);
            switch (chooseStudentManaging)
            {
            case 0:
            {
                break;
            }
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8;
            {    
                break;
            }
            default:
            {
                break;

            }
            
        }   while ((chooseStudentManaging !=0));

            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            printf("You entered incorrectly, please re-enter your selection!\n");
            break;
        }
        }