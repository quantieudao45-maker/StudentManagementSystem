struct Student
{
    int StudentID;
    char Name[50];
    char Class[80];
};
struct mark
{
    int StudentID;
    int SubjectID;
    float Adt_points;
    float mid_points;
    float points;
    float average_points;
};
struct Subject{
    int SubjectID;
    char Subjectname[30];
    int Semester;
    char Teacher_name[30];
};