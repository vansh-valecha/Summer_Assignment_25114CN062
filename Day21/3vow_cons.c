// Write a program to Count vowels and consonants.
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int vow = 0, cons = 0, i;
    printf("enter the string:");
    scanf("%[^\n]s", str);//input ka liya space ka sath
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
            str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
            str[i] == 'O' || str[i] == 'U')
        {
            vow++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') ||
                 (str[i] >= 'A' && str[i] <= 'Z'))
        {
            cons++;
        }
    }
    printf("vowel:%d", vow);
    printf("consonents:%d", cons);
    return 0;
}
