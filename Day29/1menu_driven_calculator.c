#include <stdio.h>

int main()
{
    int choice;
    double num1, num2, result;

    do
    {
        printf("\n===== Menu Driven Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
        {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
        }

        switch (choice)
        {
        case 1:
            result = num1 + num2;
            printf("Addition = %.2lf\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("Subtraction = %.2lf\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("Multiplication = %.2lf\n", result);
            break;

        case 4:
            if (num2 == 0)
            {
                printf("Division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
                printf("Division = %.2lf\n", result);
            }
            break;

        case 5:
            printf("Exiting calculator...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
