// Write a program to Create quiz application.
#include <stdio.h>
int main()
{
    // isme phle eques pucha ga user se input le ga then ans se compare kara ga ki correct ha ya nhi
    char ans;
    int sc = 0;
    printf("Welcome to Quiz Application\n");

    printf("\nQuestion 1:\n");
    printf("What is the capital of India?\n");
    printf("A. Mumbai\n");
    printf("B. Delhi\n");
    printf("C. Kolkata\n");
    printf("D. Chennai\n");
    printf("Enter your answer:");
    scanf(" %c", &ans);
    if (ans == 'B')
    {
        printf("Correct answer!\n");
        sc = sc + 1;
    }
    else
    {
        printf("Wrong answer!\n");
    }

    printf("Question 2:\n");
    printf("Which language is used for system programming?\n");
    printf("A. HTML\n");
    printf("B. CSS\n");
    printf("C. C\n");
    printf("D. SQL\n");
    printf("Enter your answer:");
    scanf(" %c", &ans); // due to \n send by previous %c
    if (ans == 'C')
    {
        printf("Correct answer!\n");
        sc = sc + 1;
    }
    else
    {
        printf("Wrong answer!\n");
    }
    printf("Question 3:\n");
    printf("How many days are there in a week?\n");
    printf("A. 5\n");
    printf("B. 6\n");
    printf("C. 7\n");
    printf("D. 8\n");
    printf("Enter your answer:");
    scanf(" %c", &ans);
    if (ans == 'C')
    {
        printf("Correct answer!\n");
        sc = sc + 1;
    }
    else
    {
        printf("Wrong answer!\n");
    }
    printf("Quiz completed.\n");
    printf("Your score is: %d out of 3", sc);
    return 0;
}
