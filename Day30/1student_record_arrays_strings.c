// Write a program to create student record system using arrays and strings.

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_SIZE 50

int findStudent(int rolls[], int count, int roll)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (rolls[i] == roll)
        {
            return i;
        }
    }

    return -1;
}

void displayStudent(int roll, char name[], float marks)
{
    printf("%-10d %-25s %.2f\n", roll, name, marks);
}

void addStudent(int rolls[], char names[][NAME_SIZE], float marks[], int *count)
{
    int roll;

    if (*count == MAX_STUDENTS)
    {
        printf("Student record is full.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &roll);

    if (findStudent(rolls, *count, roll) != -1)
    {
        printf("Roll number already exists.\n");
        return;
    }

    rolls[*count] = roll;

    printf("Enter student name: ");
    scanf(" %[^\n]", names[*count]);

    printf("Enter marks: ");
    scanf("%f", &marks[*count]);

    (*count)++;

    printf("Student added successfully.\n");
}

void displayAllStudents(int rolls[], char names[][NAME_SIZE], float marks[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\n%-10s %-25s %s\n", "Roll", "Name", "Marks");

    for (i = 0; i < count; i++)
    {
        displayStudent(rolls[i], names[i], marks[i]);
    }
}

void searchStudent(int rolls[], char names[][NAME_SIZE], float marks[], int count)
{
    int roll, index;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    index = findStudent(rolls, count, roll);

    if (index == -1)
    {
        printf("Student not found.\n");
    }
    else
    {
        printf("\n%-10s %-25s %s\n", "Roll", "Name", "Marks");
        displayStudent(rolls[index], names[index], marks[index]);
    }
}

void updateStudent(int rolls[], char names[][NAME_SIZE], float marks[], int count)
{
    int roll, index;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    index = findStudent(rolls, count, roll);

    if (index == -1)
    {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", names[index]);

    printf("Enter new marks: ");
    scanf("%f", &marks[index]);

    printf("Student updated successfully.\n");
}

void deleteStudent(int rolls[], char names[][NAME_SIZE], float marks[], int *count)
{
    int roll, index, i;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    index = findStudent(rolls, *count, roll);

    if (index == -1)
    {
        printf("Student not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        rolls[i] = rolls[i + 1];
        strcpy(names[i], names[i + 1]);
        marks[i] = marks[i + 1];
    }

    (*count)--;

    printf("Student deleted successfully.\n");
}

int main()
{
    int rolls[MAX_STUDENTS];
    char names[MAX_STUDENTS][NAME_SIZE];
    float marks[MAX_STUDENTS];
    int count = 0, choice;

    do
    {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(rolls, names, marks, &count);
            break;

        case 2:
            displayAllStudents(rolls, names, marks, count);
            break;

        case 3:
            searchStudent(rolls, names, marks, count);
            break;

        case 4:
            updateStudent(rolls, names, marks, count);
            break;

        case 5:
            deleteStudent(rolls, names, marks, &count);
            break;

        case 6:
            printf("Exiting student record system.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
