// Write a program to Reverse a string.
#include <stdio.h>
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
// ye swap kra ga jab tak i chota rhai ga j se matlab beach me jab a jaya ga string ka
void rev(char str[])
{
    int i, j;
    char temp;
    i = 0;
    j = length(str) - 1;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    printf("reverse string:%s", str);
}
int main()
{
    char str[100];
    printf("enter the string:");
    gets(str);
    rev(str);
    return 0;
}
