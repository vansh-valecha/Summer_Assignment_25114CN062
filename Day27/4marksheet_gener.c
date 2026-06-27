//Write a program to Create marksheet generation system

#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

void calculateResult(struct Student *s)
{
    int i;

    s->total = 0;

    for (i = 0; i < 5; i++)
    {
        s->total = s->total + s->marks[i];
    }

    s->percentage = s->total / 5.0;

    if (s->percentage >= 90)
    {
        s->grade = 'A';
    }
    else if (s->percentage >= 75)
    {
        s->grade = 'B';
    }
    else if (s->percentage >= 60)
    {
        s->grade = 'C';
    }
    else if (s->percentage >= 40)
    {
        s->grade = 'D';
    }
    else
    {
        s->grade = 'F';
    }
}

int findStudent(struct Student *s, int count, int roll)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            return i;
        }
    }

    return -1;
}

void saveToFile(struct Student *s, int count)
{
    FILE *fp;

    fp = fopen("marksheet.dat", "wb");

    if (fp == NULL)
    {
        printf("File not opened.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct Student), count, fp);

    fclose(fp);
}

void loadFromFile(struct Student **s, int *count, int *capacity)
{
    FILE *fp;

    fp = fopen("marksheet.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        *capacity = 2;
        *s = (struct Student *)malloc((*capacity) * sizeof(struct Student));
        return;
    }

    fread(count, sizeof(int), 1, fp);

    if (*count == 0)
    {
        *capacity = 2;
    }
    else
    {
        *capacity = *count;
    }

    *s = (struct Student *)malloc((*capacity) * sizeof(struct Student));

    fread(*s, sizeof(struct Student), *count, fp);

    fclose(fp);
}

int main()
{
    struct Student *s;
    int count = 0, capacity = 0;
    int choice, roll, index, i, j;

    loadFromFile(&s, &count, &capacity);

    do
    {
        printf("\n===== Marksheet Generation System =====\n");
        printf("1. Add Student Marksheet\n");
        printf("2. Display All Marksheets\n");
        printf("3. Search Marksheet\n");
        printf("4. Update Marks\n");
        printf("5. Delete Marksheet\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == capacity)
            {
                capacity = capacity * 2;
                s = (struct Student *)realloc(s, capacity * sizeof(struct Student));
            }

            printf("Enter roll number: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index != -1)
            {
                printf("Roll number already exists.\n");
            }
            else
            {
                s[count].roll = roll;

                printf("Enter student name: ");
                scanf(" %[^\n]", s[count].name);

                printf("Enter marks of 5 subjects:\n");
                for (i = 0; i < 5; i++)
                {
                    printf("Subject %d: ", i + 1);
                    scanf("%d", &s[count].marks[i]);
                }

                calculateResult(&s[count]);

                count++;

                saveToFile(s, count);

                printf("Marksheet added successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No marksheets found.\n");
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    printf("\n----- Marksheet -----\n");
                    printf("Roll: %d\n", s[i].roll);
                    printf("Name: %s\n", s[i].name);

                    for (j = 0; j < 5; j++)
                    {
                        printf("Subject %d Marks: %d\n", j + 1, s[i].marks[j]);
                    }

                    printf("Total: %d / 500\n", s[i].total);
                    printf("Percentage: %.2f%%\n", s[i].percentage);
                    printf("Grade: %c\n", s[i].grade);
                }
            }
            break;

        case 3:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index == -1)
            {
                printf("Marksheet not found.\n");
            }
            else
            {
                printf("\n----- Marksheet Found -----\n");
                printf("Roll: %d\n", s[index].roll);
                printf("Name: %s\n", s[index].name);

                for (i = 0; i < 5; i++)
                {
                    printf("Subject %d Marks: %d\n", i + 1, s[index].marks[i]);
                }

                printf("Total: %d / 500\n", s[index].total);
                printf("Percentage: %.2f%%\n", s[index].percentage);
                printf("Grade: %c\n", s[index].grade);
            }
            break;

        case 4:
            printf("Enter roll number to update marks: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index == -1)
            {
                printf("Student not found.\n");
            }
            else
            {
                printf("Enter new marks of 5 subjects:\n");

                for (i = 0; i < 5; i++)
                {
                    printf("Subject %d: ", i + 1);
                    scanf("%d", &s[index].marks[i]);
                }

                calculateResult(&s[index]);

                saveToFile(s, count);

                printf("Marks updated successfully.\n");
            }
            break;

        case 5:
            printf("Enter roll number to delete marksheet: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index == -1)
            {
                printf("Marksheet not found.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    s[i] = s[i + 1];
                }

                count--;

                saveToFile(s, count);

                printf("Marksheet deleted successfully.\n");
            }
            break;

        case 6:
            saveToFile(s, count);
            printf("Thank you for using Marksheet Generation System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    free(s);

    return 0;
}
