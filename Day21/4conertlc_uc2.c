//Write a program to Convert lowercase to uppercase. 
#include<stdio.h>
//withou use of liberary only with asscii code difference 'a'=97;'A'=65
int main()
{
    char str[100];
    int i;
    printf("enter the string:");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
           str[i]=str[i]-32;
        }
    }
    printf("%s",str);
    return 0;
}
