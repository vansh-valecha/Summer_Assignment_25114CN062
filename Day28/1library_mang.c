// Write a program to Create library management system.

#include <stdio.h>
#include <stdlib.h>

struct Book
{
    int id;
    char title[100];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int findBook(struct Book *b, int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (b[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void saveToFile(struct Book *b, int count)
{
    FILE *fp;

    fp = fopen("library.dat", "wb");

    if (fp == NULL)
    {
        printf("File not opened.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(b, sizeof(struct Book), count, fp);

    fclose(fp);
}

void loadFromFile(struct Book **b, int *count, int *capacity)
{
    FILE *fp;

    fp = fopen("library.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        *capacity = 2;
        *b = (struct Book *)malloc((*capacity) * sizeof(struct Book));
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

    *b = (struct Book *)malloc((*capacity) * sizeof(struct Book));

    fread(*b, sizeof(struct Book), *count, fp);

    fclose(fp);
}

int main()
{
    struct Book *b;
    int count = 0, capacity = 0;
    int choice, id, index, i, copies, issuedCopies;

    loadFromFile(&b, &count, &capacity);

    do
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Issue Book\n");
        printf("7. Return Book\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == capacity)
            {
                capacity = capacity * 2;
                b = (struct Book *)realloc(b, capacity * sizeof(struct Book));
            }

            printf("Enter book ID: ");
            scanf("%d", &id);

            index = findBook(b, count, id);

            if (index != -1)
            {
                printf("Book ID already exists.\n");
            }
            else
            {
                b[count].id = id;

                printf("Enter book title: ");
                scanf(" %[^\n]", b[count].title);

                printf("Enter author name: ");
                scanf(" %[^\n]", b[count].author);

                printf("Enter total copies: ");
                scanf("%d", &b[count].totalCopies);

                if (b[count].totalCopies < 0)
                {
                    b[count].totalCopies = 0;
                }

                b[count].availableCopies = b[count].totalCopies;

                count++;

                saveToFile(b, count);

                printf("Book added successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No book records found.\n");
            }
            else
            {
                printf("\nID\tTitle\t\tAuthor\t\tTotal\tAvailable\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d\t%s\t\t%s\t\t%d\t%d\n",
                           b[i].id,
                           b[i].title,
                           b[i].author,
                           b[i].totalCopies,
                           b[i].availableCopies);
                }
            }
            break;

        case 3:
            printf("Enter book ID to search: ");
            scanf("%d", &id);

            index = findBook(b, count, id);

            if (index == -1)
            {
                printf("Book not found.\n");
            }
            else
            {
                printf("Book found.\n");
                printf("ID: %d\n", b[index].id);
                printf("Title: %s\n", b[index].title);
                printf("Author: %s\n", b[index].author);
                printf("Total copies: %d\n", b[index].totalCopies);
                printf("Available copies: %d\n", b[index].availableCopies);
            }
            break;

        case 4:
            printf("Enter book ID to update: ");
            scanf("%d", &id);

            index = findBook(b, count, id);

            if (index == -1)
            {
                printf("Book not found.\n");
            }
            else
            {
                issuedCopies = b[index].totalCopies - b[index].availableCopies;

                printf("Enter new title: ");
                scanf(" %[^\n]", b[index].title);

                printf("Enter new author name: ");
                scanf(" %[^\n]", b[index].author);

                printf("Enter new total copies: ");
                scanf("%d", &copies);

                if (copies < issuedCopies)
                {
                    printf("Total copies cannot be less than issued copies (%d).\n", issuedCopies);
                }
                else
                {
                    b[index].totalCopies = copies;
                    b[index].availableCopies = copies - issuedCopies;

                    saveToFile(b, count);

                    printf("Book updated successfully.\n");
                }
            }
            break;

        case 5:
            printf("Enter book ID to delete: ");
            scanf("%d", &id);

            index = findBook(b, count, id);

            if (index == -1)
            {
                printf("Book not found.\n");
            }
            else if (b[index].availableCopies != b[index].totalCopies)
            {
                printf("Cannot delete book because some copies are issued.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    b[i] = b[i + 1];
                }

                count--;

                saveToFile(b, count);

                printf("Book deleted successfully.\n");
            }
            break;

        case 6:
            printf("Enter book ID to issue: ");
            scanf("%d", &id);

            index = findBook(b, count, id);

            if (index == -1)
            {
                printf("Book not found.\n");
            }
            else if (b[index].availableCopies == 0)
            {
                printf("Book is not available right now.\n");
            }
            else
            {
                b[index].availableCopies--;

                saveToFile(b, count);

                printf("Book issued successfully.\n");
            }
            break;

        case 7:
            printf("Enter book ID to return: ");
            scanf("%d", &id);

            index = findBook(b, count, id);

            if (index == -1)
            {
                printf("Book not found.\n");
            }
            else if (b[index].availableCopies == b[index].totalCopies)
            {
                printf("All copies are already available.\n");
            }
            else
            {
                b[index].availableCopies++;

                saveToFile(b, count);

                printf("Book returned successfully.\n");
            }
            break;

        case 8:
            saveToFile(b, count);
            printf("Thank you for using Library Management System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 8);

    free(b);

    return 0;
}
