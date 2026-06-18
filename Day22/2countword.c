// Write a program to Count words in a sentence.

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int count = 0, i, inword = 0;
    printf("enter the string:");
    scanf("%[^\n]s", str); // input ka liya space ka sath
    // we use inward so that after space reach then it start rather then h e l l o seperately
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') // we use and because space is also treat as character
        {
            if (inword == 0)
            {
                count++;
                inword = 1;
            }
        }
        else
        {
            inword = 0;
        }
    }

    printf("word in sentence:%d", count);
    return 0;
}
