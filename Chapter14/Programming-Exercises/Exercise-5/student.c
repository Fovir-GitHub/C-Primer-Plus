// Write a program that fits the following recipe :
// a.Externally define a  name structure template with two members :
// a string to hold the first name and a string to hold the second name.
// b.Externally define a  student structure template with three members :
// a  namestructure, a  grade array to hold three floating - point scores,
// and a variable to hold the average of those three scores.
// c.Have the  main() function declare an array of  CSIZE(with  CSIZE = 4)
// student structures and initialize the name portions
// to names of your choice.Use functions to perform the tasks described
// in parts d., e., f., and g.
// d.Interactively acquire scores for each student
// by prompting the user with a student name and a request for scores.
// Place the scores in the grade array portion of the appropriate structure.
// The required looping can be done in  main() or in the function,
// as you prefer.
// e.Calculate the average score value for each structure and assign it
// to the proper member.
// f.Print the information in each structure.
// g.Print the class average for each of the numeric structure members.

#include <stdio.h>

#define NAMESIZE 41
#define GRADE 3
#define CSIZE 4

typedef struct _NAME_
{
    char FirstName[NAMESIZE];
    char SecondName[NAMESIZE];
} name;

typedef struct _STUDENT_
{
    name  Name;
    float Grade[GRADE];
    float AverageGrade;
} student;

void GetScore(student stu[], int n);
void GenerateAverageGrade(student stu[], int n);
void PrintInformation(student stu[], int n);
void PrintClassAverage(student stu[], int n);

int main(void)
{
    // freopen("./data.in", "r", stdin);
    student Student[CSIZE] = {{{"Smith", "Emily"}},
                              {{"Lee", "Alexander"}},
                              {{"Johnson", "Hannah"}},
                              {{"Williams", "Jackson"}}};

    GetScore(Student, CSIZE);
    GenerateAverageGrade(Student, CSIZE);
    PrintInformation(Student, CSIZE);
    PrintClassAverage(Student, CSIZE);

    return 0;
}

void GetScore(student stu[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Please enter %s %s's grades:\n", stu[i].Name.FirstName,
               stu[i].Name.SecondName);

        for (int j = 0; j < GRADE; j++) scanf("%f", &stu[i].Grade[j]);
    }

    return;
}

void GenerateAverageGrade(student stu[], int n)
{
    for (int i = 0; i < n; i++)
    {
        float sum = (float) 0;
        for (int j = 0; j < GRADE; j++) sum += stu[i].Grade[j];
        stu[i].AverageGrade = (float) sum / GRADE;
    }

    return;
}

void PrintInformation(student stu[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %s: Chinese: %g, Math: %g, English: %g,"
               "Average score: %.1f\n",
               stu[i].Name.FirstName, stu[i].Name.SecondName, stu[i].Grade[0],
               stu[i].Grade[1], stu[i].Grade[2], stu[i].AverageGrade);
    return;
}

void PrintClassAverage(student stu[], int n)
{
    float sum;
    char * class[GRADE] = {"Chinese", "Math", "English"};

    for (int i = 0; i < GRADE; i++)
    {
        sum = (float) 0;
        for (int j = 0; j < n; j++) sum += stu[j].Grade[i];
        printf("%s: %.1f\n", class[i], (float) sum / GRADE);
    }

    return;
}