// Write a program to Create contact management system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    int id;
    char name[50];
    char phone[20];
    char email[60];
    char address[100];
};

int findContactById(struct Contact *c, int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (c[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int findContactByName(struct Contact *c, int count, char name[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(c[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void saveToFile(struct Contact *c, int count)
{
    FILE *fp;

    fp = fopen("contacts.dat", "wb");

    if (fp == NULL)
    {
        printf("File not opened.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(c, sizeof(struct Contact), count, fp);

    fclose(fp);
}

void loadFromFile(struct Contact **c, int *count, int *capacity)
{
    FILE *fp;

    fp = fopen("contacts.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        *capacity = 2;
        *c = (struct Contact *)malloc((*capacity) * sizeof(struct Contact));
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

    *c = (struct Contact *)malloc((*capacity) * sizeof(struct Contact));

    fread(*c, sizeof(struct Contact), *count, fp);

    fclose(fp);
}

void printContact(struct Contact c)
{
    printf("ID: %d\n", c.id);
    printf("Name: %s\n", c.name);
    printf("Phone: %s\n", c.phone);
    printf("Email: %s\n", c.email);
    printf("Address: %s\n", c.address);
}

int main()
{
    struct Contact *c;
    int count = 0, capacity = 0;
    int choice, id, index, i, searchChoice;
    char searchName[50];

    loadFromFile(&c, &count, &capacity);

    do
    {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == capacity)
            {
                capacity = capacity * 2;
                c = (struct Contact *)realloc(c, capacity * sizeof(struct Contact));
            }

            printf("Enter contact ID: ");
            scanf("%d", &id);

            index = findContactById(c, count, id);

            if (index != -1)
            {
                printf("Contact ID already exists.\n");
            }
            else
            {
                c[count].id = id;

                printf("Enter name: ");
                scanf(" %[^\n]", c[count].name);

                printf("Enter phone number: ");
                scanf(" %[^\n]", c[count].phone);

                printf("Enter email: ");
                scanf(" %[^\n]", c[count].email);

                printf("Enter address: ");
                scanf(" %[^\n]", c[count].address);

                count++;

                saveToFile(c, count);

                printf("Contact added successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No contact records found.\n");
            }
            else
            {
                printf("\nID\tName\t\tPhone\t\tEmail\t\tAddress\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d\t%s\t\t%s\t\t%s\t\t%s\n",
                           c[i].id,
                           c[i].name,
                           c[i].phone,
                           c[i].email,
                           c[i].address);
                }
            }
            break;

        case 3:
            printf("Search by:\n");
            printf("1. Contact ID\n");
            printf("2. Name\n");
            printf("Enter your choice: ");
            scanf("%d", &searchChoice);

            if (searchChoice == 1)
            {
                printf("Enter contact ID to search: ");
                scanf("%d", &id);

                index = findContactById(c, count, id);
            }
            else if (searchChoice == 2)
            {
                printf("Enter name to search: ");
                scanf(" %[^\n]", searchName);

                index = findContactByName(c, count, searchName);
            }
            else
            {
                printf("Invalid search choice.\n");
                break;
            }

            if (index == -1)
            {
                printf("Contact not found.\n");
            }
            else
            {
                printf("Contact found.\n");
                printContact(c[index]);
            }
            break;

        case 4:
            printf("Enter contact ID to update: ");
            scanf("%d", &id);

            index = findContactById(c, count, id);

            if (index == -1)
            {
                printf("Contact not found.\n");
            }
            else
            {
                printf("Enter new name: ");
                scanf(" %[^\n]", c[index].name);

                printf("Enter new phone number: ");
                scanf(" %[^\n]", c[index].phone);

                printf("Enter new email: ");
                scanf(" %[^\n]", c[index].email);

                printf("Enter new address: ");
                scanf(" %[^\n]", c[index].address);

                saveToFile(c, count);

                printf("Contact updated successfully.\n");
            }
            break;

        case 5:
            printf("Enter contact ID to delete: ");
            scanf("%d", &id);

            index = findContactById(c, count, id);

            if (index == -1)
            {
                printf("Contact not found.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    c[i] = c[i + 1];
                }

                count--;

                saveToFile(c, count);

                printf("Contact deleted successfully.\n");
            }
            break;

        case 6:
            saveToFile(c, count);
            printf("Thank you for using Contact Management System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    free(c);

    return 0;
}
