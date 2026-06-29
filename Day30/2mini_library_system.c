// Write a program to create mini library system.

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_SIZE 80
#define AUTHOR_SIZE 50

int findBook(int ids[], int count, int id)
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

void displayBook(int id, char title[], char author[], int total, int available)
{
    printf("%-8d %-28s %-22s %-8d %d\n", id, title, author, total, available);
}

void addBook(int ids[], char titles[][TITLE_SIZE], char authors[][AUTHOR_SIZE],
             int totalCopies[], int availableCopies[], int *count)
{
    int id, copies;

    if (*count == MAX_BOOKS)
    {
        printf("Library is full.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    if (findBook(ids, *count, id) != -1)
    {
        printf("Book ID already exists.\n");
        return;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]", titles[*count]);

    printf("Enter author name: ");
    scanf(" %[^\n]", authors[*count]);

    printf("Enter total copies: ");
    scanf("%d", &copies);

    if (copies < 0)
    {
        copies = 0;
    }

    ids[*count] = id;
    totalCopies[*count] = copies;
    availableCopies[*count] = copies;

    (*count)++;

    printf("Book added successfully.\n");
}

void displayBooks(int ids[], char titles[][TITLE_SIZE], char authors[][AUTHOR_SIZE],
                  int totalCopies[], int availableCopies[], int count)
{
    int i;

    if (count == 0)
    {
        printf("No books found.\n");
        return;
    }

    printf("\n%-8s %-28s %-22s %-8s %s\n", "ID", "Title", "Author", "Total", "Available");

    for (i = 0; i < count; i++)
    {
        displayBook(ids[i], titles[i], authors[i], totalCopies[i], availableCopies[i]);
    }
}

void searchBook(int ids[], char titles[][TITLE_SIZE], char authors[][AUTHOR_SIZE],
                int totalCopies[], int availableCopies[], int count)
{
    int id, index;

    printf("Enter book ID to search: ");
    scanf("%d", &id);

    index = findBook(ids, count, id);

    if (index == -1)
    {
        printf("Book not found.\n");
    }
    else
    {
        printf("\n%-8s %-28s %-22s %-8s %s\n", "ID", "Title", "Author", "Total", "Available");
        displayBook(ids[index], titles[index], authors[index],
                    totalCopies[index], availableCopies[index]);
    }
}

void issueBook(int ids[], int availableCopies[], int count)
{
    int id, index;

    printf("Enter book ID to issue: ");
    scanf("%d", &id);

    index = findBook(ids, count, id);

    if (index == -1)
    {
        printf("Book not found.\n");
    }
    else if (availableCopies[index] == 0)
    {
        printf("Book is not available.\n");
    }
    else
    {
        availableCopies[index]--;
        printf("Book issued successfully.\n");
    }
}

void returnBook(int ids[], int totalCopies[], int availableCopies[], int count)
{
    int id, index;

    printf("Enter book ID to return: ");
    scanf("%d", &id);

    index = findBook(ids, count, id);

    if (index == -1)
    {
        printf("Book not found.\n");
    }
    else if (availableCopies[index] == totalCopies[index])
    {
        printf("All copies are already available.\n");
    }
    else
    {
        availableCopies[index]++;
        printf("Book returned successfully.\n");
    }
}

void deleteBook(int ids[], char titles[][TITLE_SIZE], char authors[][AUTHOR_SIZE],
                int totalCopies[], int availableCopies[], int *count)
{
    int id, index, i;

    printf("Enter book ID to delete: ");
    scanf("%d", &id);

    index = findBook(ids, *count, id);

    if (index == -1)
    {
        printf("Book not found.\n");
        return;
    }

    if (availableCopies[index] != totalCopies[index])
    {
        printf("Cannot delete book because some copies are issued.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        ids[i] = ids[i + 1];
        strcpy(titles[i], titles[i + 1]);
        strcpy(authors[i], authors[i + 1]);
        totalCopies[i] = totalCopies[i + 1];
        availableCopies[i] = availableCopies[i + 1];
    }

    (*count)--;

    printf("Book deleted successfully.\n");
}

int main()
{
    int ids[MAX_BOOKS];
    char titles[MAX_BOOKS][TITLE_SIZE];
    char authors[MAX_BOOKS][AUTHOR_SIZE];
    int totalCopies[MAX_BOOKS], availableCopies[MAX_BOOKS];
    int count = 0, choice;

    do
    {
        printf("\n===== Mini Library System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(ids, titles, authors, totalCopies, availableCopies, &count);
            break;

        case 2:
            displayBooks(ids, titles, authors, totalCopies, availableCopies, count);
            break;

        case 3:
            searchBook(ids, titles, authors, totalCopies, availableCopies, count);
            break;

        case 4:
            issueBook(ids, availableCopies, count);
            break;

        case 5:
            returnBook(ids, totalCopies, availableCopies, count);
            break;

        case 6:
            deleteBook(ids, titles, authors, totalCopies, availableCopies, &count);
            break;

        case 7:
            printf("Exiting mini library system.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
