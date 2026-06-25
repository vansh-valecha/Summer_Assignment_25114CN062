// Write a program to Create ATM simulation
#include <stdio.h>
int main()
{
 // phele dashboard show hoga the choice le ga uska bad phele balance deposit krna pda ga kyuki hum store nhi kr rha ha 
 // deposit ka phele or bad bhi sara option chla ga    
    int inp, bal = 0, wd, ch = 1, dp;
    printf("Welcome to ATM\n");

    while (ch != 0)
    {
        printf("1. check balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("enter your choice:");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            printf("your balance is %d\n", bal);
            break;
        case 2:
            printf("Enter amount to deposit:");
            scanf("%d", &dp);
            bal = bal + dp;
            printf("Amount deposited successfully.\n");
            printf("new balance is:%d\n", bal);
            break;
        case 3:
            printf("Enter amount to withdraw:");
            scanf("%d", &wd);
            if (bal >= wd)
            {
                printf("Please collect your cash.\n");
                bal = bal - wd;
                printf("Remaining balance is:%d\n", bal);
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            break;
        case 4:
            printf("Thank you for using ATM.");
            ch = 0;
            break;
        default:
            printf("invalid choice.\n");
        }
        if (ch != 0)
        {
            printf("if u want to continue press 1 stop tap 0:");
            scanf("%d", &ch);
        }
    }
    return 0;
}
