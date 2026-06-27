// Write a program to Create student record management system. 
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

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

    fp = fopen("students.dat", "wb");

    if (fp == NULL)
    {
        printf("File not opened.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct Student), count, fp);

    fclose(fp);
}

void loadFromFile(struct Student **s, int *count, int *capacity)//**s main pointer ka address
{
    FILE *fp;

    fp = fopen("students.dat", "rb");

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
    int choice, roll, index, i;

    loadFromFile(&s, &count, &capacity);

    do
    {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
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

                printf("Enter name: ");
                scanf(" %[^\n]", s[count].name);

                printf("Enter marks: ");
                scanf("%f", &s[count].marks);

                count++;//update the indexing

                saveToFile(s, count);

                printf("Student added successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No records found.\n");
            }
            else
            {
                printf("\nRoll\tName\t\tMarks\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d\t%s\t\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
                }
            }
            break;

        case 3:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index == -1)
            {
                printf("Student not found.\n");
            }
            else
            {
                printf("Student found.\n");
                printf("Roll: %d\n", s[index].roll);
                printf("Name: %s\n", s[index].name);
                printf("Marks: %.2f\n", s[index].marks);
            }
            break;

        case 4:
            printf("Enter roll number to update: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index == -1)
            {
                printf("Student not found.\n");
            }
            else
            {
                printf("Enter new name: ");
                scanf(" %[^\n]", s[index].name);

                printf("Enter new marks: ");
                scanf("%f", &s[index].marks);

                saveToFile(s, count);

                printf("Student updated successfully.\n");
            }
            break;

        case 5:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);

            index = findStudent(s, count, roll);

            if (index == -1)
            {
                printf("Student not found.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    s[i] = s[i + 1];
                }

                count--;

                saveToFile(s, count);

                printf("Student deleted successfully.\n");
            }
            break;

        case 6:
            saveToFile(s, count);
            printf("Thank you for using system.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    free(s);

    return 0;
}
