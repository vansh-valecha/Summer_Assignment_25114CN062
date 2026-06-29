// Write a program to create mini employee management system.

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_SIZE 50
#define DEPT_SIZE 40

int findEmployee(int ids[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}

void displayEmployee(int id, char name[], char department[], float salary)
{
    printf("%-8d %-22s %-18s %.2f\n", id, name, department, salary);
}

void addEmployee(int ids[], char names[][NAME_SIZE], char departments[][DEPT_SIZE],
                 float salaries[], int *count)
{
    int id;

    if (*count == MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter employee ID: ");
    scanf("%d", &id);

    if (findEmployee(ids, *count, id) != -1)
    {
        printf("Employee ID already exists.\n");
        return;
    }

    ids[*count] = id;

    printf("Enter employee name: ");
    scanf(" %[^\n]", names[*count]);

    printf("Enter department: ");
    scanf(" %[^\n]", departments[*count]);

    printf("Enter salary: ");
    scanf("%f", &salaries[*count]);

    (*count)++;

    printf("Employee added successfully.\n");
}

void displayEmployees(int ids[], char names[][NAME_SIZE], char departments[][DEPT_SIZE],
                      float salaries[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\n%-8s %-22s %-18s %s\n", "ID", "Name", "Department", "Salary");

    for (i = 0; i < count; i++)
    {
        displayEmployee(ids[i], names[i], departments[i], salaries[i]);
    }
}

void searchEmployee(int ids[], char names[][NAME_SIZE], char departments[][DEPT_SIZE],
                    float salaries[], int count)
{
    int id, index;

    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    index = findEmployee(ids, count, id);

    if (index == -1)
    {
        printf("Employee not found.\n");
    }
    else
    {
        printf("\n%-8s %-22s %-18s %s\n", "ID", "Name", "Department", "Salary");
        displayEmployee(ids[index], names[index], departments[index], salaries[index]);
    }
}

void updateEmployee(int ids[], char names[][NAME_SIZE], char departments[][DEPT_SIZE],
                    float salaries[], int count)
{
    int id, index;

    printf("Enter employee ID to update: ");
    scanf("%d", &id);

    index = findEmployee(ids, count, id);

    if (index == -1)
    {
        printf("Employee not found.\n");
        return;
    }

    printf("Enter new employee name: ");
    scanf(" %[^\n]", names[index]);

    printf("Enter new department: ");
    scanf(" %[^\n]", departments[index]);

    printf("Enter new salary: ");
    scanf("%f", &salaries[index]);

    printf("Employee updated successfully.\n");
}

void deleteEmployee(int ids[], char names[][NAME_SIZE], char departments[][DEPT_SIZE],
                    float salaries[], int *count)
{
    int id, index, i;

    printf("Enter employee ID to delete: ");
    scanf("%d", &id);

    index = findEmployee(ids, *count, id);

    if (index == -1)
    {
        printf("Employee not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        ids[i] = ids[i + 1];
        strcpy(names[i], names[i + 1]);
        strcpy(departments[i], departments[i + 1]);
        salaries[i] = salaries[i + 1];
    }

    (*count)--;

    printf("Employee deleted successfully.\n");
}

void showHighestSalary(int ids[], char names[][NAME_SIZE], char departments[][DEPT_SIZE],
                       float salaries[], int count)
{
    int i, maxIndex;

    if (count == 0)
    {
        printf("No employee records found.\n");
        return;
    }

    maxIndex = 0;

    for (i = 1; i < count; i++)
    {
        if (salaries[i] > salaries[maxIndex])
        {
            maxIndex = i;
        }
    }

    printf("\nEmployee with highest salary:\n");
    printf("%-8s %-22s %-18s %s\n", "ID", "Name", "Department", "Salary");
    displayEmployee(ids[maxIndex], names[maxIndex], departments[maxIndex], salaries[maxIndex]);
}

int main()
{
    int ids[MAX_EMPLOYEES];
    char names[MAX_EMPLOYEES][NAME_SIZE];
    char departments[MAX_EMPLOYEES][DEPT_SIZE];
    float salaries[MAX_EMPLOYEES];
    int count = 0, choice;

    do
    {
        printf("\n===== Mini Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Show Highest Salary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(ids, names, departments, salaries, &count);
            break;

        case 2:
            displayEmployees(ids, names, departments, salaries, count);
            break;

        case 3:
            searchEmployee(ids, names, departments, salaries, count);
            break;

        case 4:
            updateEmployee(ids, names, departments, salaries, count);
            break;

        case 5:
            deleteEmployee(ids, names, departments, salaries, &count);
            break;

        case 6:
            showHighestSalary(ids, names, departments, salaries, count);
            break;

        case 7:
            printf("Exiting employee management system.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
