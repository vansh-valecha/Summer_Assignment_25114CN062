// Write a program to Check string rotation.
// agr string1 +string 2 ko mila kr str2 ka char check kra ga agr ha to wo rotation hoga
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], temp[200];

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    if (strlen(str1) != strlen(str2))
    {
        printf("Not rotation string");
        return 0;
    }

    strcpy(temp, str1); // copy kra ga temp me str1 ka char
    strcat(temp, str1); // str1 ka char ko temp me add kra ga

    if (strstr(temp, str2) != NULL) // strstr(mainString, searchString)check kra ga agr searchString mainString me hoga to return kra ga address of first occurrence otherwise NULL return kra ga
    {
        printf("Rotation string");
    }
    else
    {
        printf("Not rotation string");
    }

    return 0;
}
