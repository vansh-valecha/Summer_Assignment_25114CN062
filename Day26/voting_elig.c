//Write a program to Create voting eligibility system. 
#include<stdio.h>
// it will simply take the age then compare with 18
int main()
{
    int age;
    printf("Enter your age:");
    scanf("%d",&age);
    if(age<18)
    {
        printf("You are not eligible to vote.");
    }
    else
    {
         printf("You are eligible to vote.");
    }
    return 0;
}
