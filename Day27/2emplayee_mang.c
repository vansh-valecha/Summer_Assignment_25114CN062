//Write a program to Create employee management system.

#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

int findEmployee(struct Employee *e, int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (e[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void saveToFile(struct Employee *e, int count)
{
    FILE *fp;

    fp = fopen("employees.dat", "wb");

    if (fp == NULL)
    {
        printf("File not opened.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(e, sizeof(struct Employee), count, fp);

    fclose(fp);
}

void loadFromFile(struct Employee **e, int *count, int *capacity)
{
    FILE *fp;

    fp = fopen("employees.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        *capacity = 2;
        *e = (struct Employee *)malloc((*capacity) * sizeof(struct Employee));
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

    *e = (struct Employee *)malloc((*capacity) * sizeof(struct Employee));

    fread(*e, sizeof(struct Employee), *count, fp);

    fclose(fp);
}

int main()
{
    struct Employee *e;
    int count = 0, capacity = 0;
    int choice, id, index, i;

    loadFromFile(&e, &count, &capacity);

    do
    {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == capacity)
            {
                capacity = capacity * 2;
                e = (struct Employee *)realloc(e, capacity * sizeof(struct Employee));
            }

            printf("Enter employee ID: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index != -1)
            {
                printf("Employee ID already exists.\n");
            }
            else
            {
                e[count].id = id;

                printf("Enter employee name: ");
                scanf(" %[^\n]", e[count].name);

                printf("Enter department: ");
                scanf(" %[^\n]", e[count].department);

                printf("Enter salary: ");
                scanf("%f", &e[count].salary);

                count++;

                saveToFile(e, count);

                printf("Employee added successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No employee records found.\n");
            }
            else
            {
                printf("\nID\tName\t\tDepartment\t\tSalary\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d\t%s\t\t%s\t\t%.2f\n",
                           e[i].id,
                           e[i].name,
                           e[i].department,
                           e[i].salary);
                }
            }
            break;

        case 3:
            printf("Enter employee ID to search: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index == -1)
            {
                printf("Employee not found.\n");
            }
            else
            {
                printf("Employee found.\n");
                printf("ID: %d\n", e[index].id);
                printf("Name: %s\n", e[index].name);
                printf("Department: %s\n", e[index].department);
                printf("Salary: %.2f\n", e[index].salary);
            }
            break;

        case 4:
            printf("Enter employee ID to update: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index == -1)
            {
                printf("Employee not found.\n");
            }
            else
            {
                printf("Enter new name: ");
                scanf(" %[^\n]", e[index].name);

                printf("Enter new department: ");
                scanf(" %[^\n]", e[index].department);

                printf("Enter new salary: ");
                scanf("%f", &e[index].salary);

                saveToFile(e, count);

                printf("Employee updated successfully.\n");
            }
            break;

        case 5:
            printf("Enter employee ID to delete: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index == -1)
            {
                printf("Employee not found.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    e[i] = e[i + 1];
                }

                count--;

                saveToFile(e, count);

                printf("Employee deleted successfully.\n");
            }
            break;

        case 6:
            saveToFile(e, count);
            printf("Thank you for using Employee Management System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    free(e);

    return 0;
}

