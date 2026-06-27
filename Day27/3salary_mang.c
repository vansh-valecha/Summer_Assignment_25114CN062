//Write a program to Create salary management system.

#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float pf;
    float netSalary;
};

void calculateSalary(struct Employee *e)
{
    e->hra = e->basicSalary * 0.20;//House Rent Allowance
    e->da = e->basicSalary * 0.10;//Dearness Allowance
    e->pf = e->basicSalary * 0.05;//Provident Fund

    e->netSalary = e->basicSalary + e->hra + e->da - e->pf;
}

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

    fp = fopen("salary.dat", "wb");

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

    fp = fopen("salary.dat", "rb");

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
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee Salary\n");
        printf("2. Display Salary Records\n");
        printf("3. Search Salary Record\n");
        printf("4. Update Basic Salary\n");
        printf("5. Delete Salary Record\n");
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

                printf("Enter basic salary: ");
                scanf("%f", &e[count].basicSalary);

                calculateSalary(&e[count]);

                count++;

                saveToFile(e, count);

                printf("Salary record added successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No salary records found.\n");
            }
            else
            {
                printf("\nID\tName\t\tBasic\t\tHRA\t\tDA\t\tPF\t\tNet Salary\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d\t%s\t\t%.2f\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
                           e[i].id,
                           e[i].name,
                           e[i].basicSalary,
                           e[i].hra,
                           e[i].da,
                           e[i].pf,
                           e[i].netSalary);
                }
            }
            break;

        case 3:
            printf("Enter employee ID to search: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index == -1)
            {
                printf("Salary record not found.\n");
            }
            else
            {
                printf("Salary record found.\n");
                printf("ID: %d\n", e[index].id);
                printf("Name: %s\n", e[index].name);
                printf("Basic Salary: %.2f\n", e[index].basicSalary);
                printf("HRA: %.2f\n", e[index].hra);
                printf("DA: %.2f\n", e[index].da);
                printf("PF: %.2f\n", e[index].pf);
                printf("Net Salary: %.2f\n", e[index].netSalary);
            }
            break;

        case 4:
            printf("Enter employee ID to update salary: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index == -1)
            {
                printf("Employee not found.\n");
            }
            else
            {
                printf("Enter new basic salary: ");
                scanf("%f", &e[index].basicSalary);

                calculateSalary(&e[index]);

                saveToFile(e, count);

                printf("Salary updated successfully.\n");
            }
            break;

        case 5:
            printf("Enter employee ID to delete: ");
            scanf("%d", &id);

            index = findEmployee(e, count, id);

            if (index == -1)
            {
                printf("Salary record not found.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    e[i] = e[i + 1];
                }

                count--;

                saveToFile(e, count);

                printf("Salary record deleted successfully.\n");
            }
            break;

        case 6:
            saveToFile(e, count);
            printf("Thank you for using Salary Management System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    free(e);

    return 0;
}
