// Write a program to Check anagram strings.
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int i, j, found;
    int visited[100] = {0}; // same character ko dobara check na kare isliye visited array ka use kra ga

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    if (strlen(str1) != strlen(str2))
    {
        printf("Not anagram strings");
        return 0;
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        found = 0;

        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j] && visited[j] == 0)
            {
                visited[j] = 1;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            printf("Not anagram strings");
            return 0;
        }
    }

    printf("Anagram strings");

    return 0;
}
