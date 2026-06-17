// Write a program to Convert lowercase to uppercase.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//check kra ka ctype liberary ki help se ki agr wo lower case ha to usko upper me conver kr de
int main()
{
    char str[100];
    int i;
    printf("enter the string:");
    gets(str);
    for (i = 0; i < strlen(str); i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    printf("%s", str);
    return 0;
}
