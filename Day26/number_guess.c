// Write a program to create a number guessing game.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber, guess, attempts = 0;
    int inputResult;

    srand(time(0));                    // srand give random pattern everytime, time is use so that at every time it give different no
    secretNumber = (rand() % 100) + 1; // large random no ko chota me convert krna ka liya

    printf("Number Guessing Game\n");
    printf("I have chosen a number between 1 and 100.\n");

    while (1)
    {
        printf("Enter your guess: ");
        inputResult = scanf("%d", &guess); // is wo guess me to no le ga & input result dekha ga ki scanf work kra ha ya nhi

        if (inputResult == EOF)
        {
            printf("\nGame ended.\n");
            return 0;
        }

        if (inputResult != 1) // agr scanf chla ga matlab correct no ho ga to wo 1 return kr de ga
        {
            int ch;
            printf("Please enter a valid whole number.\n");
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                // Discard invalid input.
            }
            continue;
        }

        if (guess < 1 || guess > 100)
        {
            printf("Your guess must be between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess < secretNumber)
        {
            printf("Too low! Try again.\n");
        }
        else if (guess > secretNumber)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts.\n",
                   attempts);
            break;
        }
    }

    return 0;
}
