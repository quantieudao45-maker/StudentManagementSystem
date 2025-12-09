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