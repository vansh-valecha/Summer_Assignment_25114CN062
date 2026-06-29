#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 200

void removeNewline(char str[])
{
    int length = strlen(str);

    if (length > 0 && str[length - 1] == '\n')
    {
        str[length - 1] = '\0';
    }
}

void readString(char str[], int size)
{
    getchar();
    fgets(str, size, stdin);
    removeNewline(str);
}

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH], copy[MAX_LENGTH];
    int choice, i, length, vowels, consonants;

    str1[0] = '\0';
    str2[0] = '\0';

    do
    {
        printf("\n===== Menu Driven String Operations =====\n");
        printf("1. Enter First String\n");
        printf("2. Find Length\n");
        printf("3. Copy String\n");
        printf("4. Concatenate String\n");
        printf("5. Compare Two Strings\n");
        printf("6. Reverse String\n");
        printf("7. Count Vowels and Consonants\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter first string: ");
            readString(str1, MAX_LENGTH);
            printf("String saved successfully.\n");
            break;

        case 2:
            length = strlen(str1);
            printf("Length of string = %d\n", length);
            break;

        case 3:
            strcpy(copy, str1);
            printf("Copied string = %s\n", copy);
            break;

        case 4:
            printf("Enter second string to concatenate: ");
            readString(str2, MAX_LENGTH);

            if (strlen(str1) + strlen(str2) >= MAX_LENGTH)
            {
                printf("Cannot concatenate. Result is too long.\n");
            }
            else
            {
                strcat(str1, str2);
                printf("After concatenation = %s\n", str1);
            }
            break;

        case 5:
            printf("Enter second string to compare: ");
            readString(str2, MAX_LENGTH);

            if (strcmp(str1, str2) == 0)
            {
                printf("Both strings are equal.\n");
            }
            else
            {
                printf("Strings are not equal.\n");
            }
            break;

        case 6:
            length = strlen(str1);
            printf("Reverse string = ");
            for (i = length - 1; i >= 0; i--)
            {
                printf("%c", str1[i]);
            }
            printf("\n");
            break;

        case 7:
            vowels = 0;
            consonants = 0;

            for (i = 0; str1[i] != '\0'; i++)
            {
                char ch = tolower(str1[i]);

                if (ch >= 'a' && ch <= 'z')
                {
                    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    {
                        vowels++;
                    }
                    else
                    {
                        consonants++;
                    }
                }
            }

            printf("Vowels = %d\n", vowels);
            printf("Consonants = %d\n", consonants);
            break;

        case 8:
            printf("Exiting string operations system...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
