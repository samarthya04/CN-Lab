#include <stdio.h>
#include <stdlib.h>

struct student_info
{
    int roll_no;
    char *name;
    float CGPA;
    int day;
    int month;
    int year;
};

void displayINFO_value(int roll, char *name, float cgpa, int d, int m, int y)
{
    printf("Name: %s\n", name);
    printf("Roll No.: %d\n", roll);
    printf("CGPA: %.2f\n", cgpa);
    printf("DOB: %d-%d-%d\n\n", d, m, y);
}

void displayINFO_address(int *roll, char *name, float *cgpa, int *d, int *m, int *y)
{
    printf("Name: %s\n", name);
    printf("Roll No.: %d\n", *roll);
    printf("CGPA: %.2f\n", *cgpa);
    printf("DOB: %d-%d-%d\n\n", *d, *m, *y);
}

int main(int argc, char *argv[])
{
    struct student_info info;

    info.roll_no = atoi(argv[1]);
    info.name = argv[2];
    info.CGPA = atof(argv[3]);
    info.day = atoi(argv[4]);
    info.month = atoi(argv[5]);
    info.year = atoi(argv[6]);

    printf("Using Call by value:\n");
    displayINFO_value(info.roll_no, info.name, info.CGPA, info.day, info.month, info.year);
    printf("Using Call by address:\n");
    displayINFO_address(&info.roll_no, info.name, &info.CGPA, &info.day, &info.month, &info.year);

    return 0;
}
