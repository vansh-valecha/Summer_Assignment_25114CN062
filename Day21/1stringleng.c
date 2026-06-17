// Write a program to Find string length without strlen().
#include <stdio.h>
// count kra ga har ek element ko jab tak null character na a jaya .
int length(char str[])
{
    int i = 0, len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
int main()
{
    char str[100];
    printf("enter the string: ");
    gets(str);
    printf("length of string :%d", length(str));
    return 0;
}
