
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Prototype declaration of functions

void print(int ROWS,int COLS,int grades[ROWS][COLS],char students[COLS][20],char Fgrades[COLS]);
void getGrades(int ROWS, int COLS, int grades[ROWS][COLS], char students[COLS][20]);
//void printGrades(int ROWS, int COLS, int grades[ROWS][COLS]);
void getStudents(int COLS, char students[COLS][20]);
//void printStudents(int COLS, char students[COLS][20]);
void calcGrades(int ROWS, int COLS, int grades[ROWS][COLS], char Fgrades[]);
//void printFinalGrades(int COLS, char Fgrades[]);
// File pointer
FILE *fptr;
// main function definition
int main(int argc,char **argv)
{
    // To store number of students and number of assignments
    if(argc < 2){
        printf("\nEnter the File Name As Argument ");
        return -1;
    }
    else if(argc > 2){
        printf("\nToo Much Argument Please give only file name ");
        return -1;
    }
    int stu = 0, assign = 0;
    // Opens the file in read mode
    // command line argument argv[1] contains the file name
    fptr = fopen(argv[1], "r");
    // Checks if the file pointer is NULL then display the error message and stop
    if (fptr == NULL)
    {
        printf("Cannot open file %s\n",argv[1]);
        exit(0);
    }// End of if condition
    // Reads number of students and number of assignments from file
    fscanf(fptr, "%d%d", &stu, &assign);
    printf("\n Number of Students = %d \n Number of Assignment = %d", stu, assign);
    // Matrix for student names
    char students[stu][20];
    // Matrix for assignment marks
    int grades[assign][stu];
    // Array for grade
    char final_grade[stu];
    // Calls the functions to read data from file and calculate grade
    getStudents(stu, students);
    getGrades(assign, stu, grades, students);
    calcGrades(assign, stu, grades, final_grade);
    printf("\n");
    // Calls the function to display data
    /*printStudents(stu, students);
     printGrades(assign, stu, grades);
     printFinalGrades(stu, final_grade);*/
    
    print(assign,stu,grades,students,final_grade);
    return 0;
}// End of main function
// Function to display final grade of all the students
/*void printFinalGrades(int COLS, char Fgrades[])
 {
 int i = 0;
 // Loops till number of students
 for (i = 0; i < COLS; ++i)
 {
 // Displays grade
 printf("%24c", Fgrades[i]);
 }// End of for loop
 printf("\n");
 }// End of function
 // Function to calculate grade*/
void calcGrades(int ROWS, int COLS, int grades[ROWS][COLS], char Fgrades[])
{
    // Initializes the variables
    int avg = 0;
    int sum = 0;
    int i = 0, j = 0;
    // Loops till number of cols
    for (i = 0; i < COLS; ++i)
    {
        sum = 0;
        // Loops till number of rows
        for (j = 0; j < ROWS; ++j)
        {
            // Calculate total
            sum += grades[j][i];
        }// End of for loop
        // Calculate average
        avg = sum / ROWS;
        // Checks if average is greater than or equals to 90
        if (avg >= 90)
            // Assign grade as 'A'
            Fgrades[i] = 'A';
        // Otherwise checks if average is greater than or equals to 80
        else if (avg >= 80)
            // Assign grade as 'B'
            Fgrades[i] = 'B';
        // Otherwise checks if average is greater than or equals to 70
        else if (avg >= 70)
            // Assign grade as 'C'
            Fgrades[i] = 'C';
        // Otherwise checks if average is greater than or equals to 60
        else if (avg >= 60)
            // Assign grade as 'D'
            Fgrades[i] = 'D';
        // Otherwise less than 60
        else
            // Assign grade as 'F'
            Fgrades[i] = 'F';
    }// End of for loop
}// End of function
// Function to display student names
/*void printStudents(int COLS, char students[COLS][20])
 {
 int i = 0;
 int numA = COLS;
 // Loops till number of columns
 for (i = 0; i < numA; ++i)
 {
 // Displays name
 printf("%24s", students[i]);
 }
 printf("\n");
 }// End of function
 // Function to read student names from file*/
void getStudents(int COLS, char students[COLS][20])
{
    int i = 0, len = 0;
    // Loops till number of columns
    for (i = 0; i < COLS; ++i)
    {
        // Reads name from file and stores it in students i index position
        fscanf(fptr, "%s", students[i]);
        // Calculates length
        len = strlen(students[i]);
        // Assigns null at the end
        students[i][len] = '\0';
    }// End of for loop
}// End of function
// Function to display grade of each student
/*void printGrades(int ROWS, int COLS, int grades[ROWS][COLS])
 {
 int i = 0, j = 0;
 // Loops till number of rows
 for (i = 0; i < ROWS; ++i)
 {
 // Loops till number of columns
 for (j = 0; j < COLS; ++j)
 {
 // Displays grades
 printf("%24d", grades[i][j]);
 }// End of inner for loop
 printf("\n");
 }// End of outer for loop
 }// End of function
 // Function to read grade from the file*/
void getGrades(int ROWS, int COLS, int grades[ROWS][COLS], char students[COLS][20])
{
    int i = 0, j = 0;
    // Loops till number of rows
    for (i = 0; i < ROWS; ++i)
    {
        // Loops till number of columns
        for (j = 0; j < COLS; ++j)
        {
            // Reads grade from the file and stores it in matrix grades
            fscanf(fptr, "%d", &grades[i][j]);
        }// End of inner for loop
    }// End of outer for loop
}// End of function


void print(int ROWS,int COLS,int grades[ROWS][COLS],char students[COLS][20],char Fgrades[COLS]){
    int i,j;
    printf("\n-----------------------------------------------------------------------\n\n");
    for(i = 0;i<COLS;i++){
        printf("%s :\t ",students[i]);
        for(j = 0;j< ROWS;j++){
            printf("%d ",grades[j][i]);
        }
        printf(" %c \n",Fgrades[i]);
    }
}


