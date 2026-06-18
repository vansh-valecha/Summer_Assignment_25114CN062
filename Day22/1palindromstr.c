// Write a program to Check palindrome string.
#include <stdio.h>
#include <string.h>
//phele copy kra ga pher check kra ga original se cmpi se matlab capital & small sab check kra ga
int main()
{
    char str[100], rev[100];
    int i = 0, j, len;
    printf("enter the string:");
    gets(str);
    len = strlen(str);
    j = len - 1;
    while (str[i] != '\0')
    {
        rev[j] = str[i];
        i++;
        j--;
    }
    rev[len] = '\0';
    if (strcmpi(str, rev) == 0)
    {
        printf("Palindrome string\n");
    }
    else
    {
        printf("Not palindrome string\n");
    }
    return 0;
}
