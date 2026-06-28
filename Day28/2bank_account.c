// Write a program to Create bank account system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    int accountNo;
    char name[100];
    char phone[20];
    char accountType[20];
    double balance;
};

int findAccount(struct Account *accounts, int count, int accountNo)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNo == accountNo)
        {
            return i;
        }
    }

    return -1;
}

void saveToFile(struct Account *accounts, int count)
{
    FILE *fp;

    fp = fopen("bank_accounts.dat", "wb");

    if (fp == NULL)
    {
        printf("File not opened.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(accounts, sizeof(struct Account), count, fp);

    fclose(fp);
}

void loadFromFile(struct Account **accounts, int *count, int *capacity)
{
    FILE *fp;

    fp = fopen("bank_accounts.dat", "rb");

    if (fp == NULL)
    {
        *count = 0;
        *capacity = 2;
        *accounts = (struct Account *)malloc((*capacity) * sizeof(struct Account));
        return;
    }

    fread(count, sizeof(int), 1, fp);

    if (*count == 0)
    {
        *capacity = 2;
    }
    else
    {
        *capacity = *count;
    }

    *accounts = (struct Account *)malloc((*capacity) * sizeof(struct Account));

    fread(*accounts, sizeof(struct Account), *count, fp);

    fclose(fp);
}

void displayAccount(struct Account account)
{
    printf("Account Number: %d\n", account.accountNo);
    printf("Name: %s\n", account.name);
    printf("Phone: %s\n", account.phone);
    printf("Account Type: %s\n", account.accountType);
    printf("Balance: %.2lf\n", account.balance);
}

int main()
{
    struct Account *accounts;
    int count = 0, capacity = 0;
    int choice, accountNo, index, i;
    double amount;

    loadFromFile(&accounts, &count, &capacity);

    do
    {
        printf("\n===== Bank Account System =====\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Update Account\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == capacity)
            {
                capacity = capacity * 2;
                accounts = (struct Account *)realloc(accounts, capacity * sizeof(struct Account));
            }

            printf("Enter account number: ");
            scanf("%d", &accountNo);

            index = findAccount(accounts, count, accountNo);

            if (index != -1)
            {
                printf("Account number already exists.\n");
            }
            else
            {
                accounts[count].accountNo = accountNo;

                printf("Enter account holder name: ");
                scanf(" %[^\n]", accounts[count].name);

                printf("Enter phone number: ");
                scanf(" %[^\n]", accounts[count].phone);

                printf("Enter account type (Savings/Current): ");
                scanf(" %[^\n]", accounts[count].accountType);

                printf("Enter opening balance: ");
                scanf("%lf", &accounts[count].balance);

                if (accounts[count].balance < 0)
                {
                    accounts[count].balance = 0;
                }

                count++;

                saveToFile(accounts, count);

                printf("Account created successfully.\n");
            }
            break;

        case 2:
            if (count == 0)
            {
                printf("No account records found.\n");
            }
            else
            {
                printf("\nAcc No\tName\t\tPhone\t\tType\t\tBalance\n");

                for (i = 0; i < count; i++)
                {
                    printf("%d\t%s\t\t%s\t\t%s\t\t%.2lf\n",
                           accounts[i].accountNo,
                           accounts[i].name,
                           accounts[i].phone,
                           accounts[i].accountType,
                           accounts[i].balance);
                }
            }
            break;

        case 3:
            printf("Enter account number to search: ");
            scanf("%d", &accountNo);

            index = findAccount(accounts, count, accountNo);

            if (index == -1)
            {
                printf("Account not found.\n");
            }
            else
            {
                printf("Account found.\n");
                displayAccount(accounts[index]);
            }
            break;

        case 4:
            printf("Enter account number: ");
            scanf("%d", &accountNo);

            index = findAccount(accounts, count, accountNo);

            if (index == -1)
            {
                printf("Account not found.\n");
            }
            else
            {
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);

                if (amount <= 0)
                {
                    printf("Amount must be greater than zero.\n");
                }
                else
                {
                    accounts[index].balance = accounts[index].balance + amount;
                    saveToFile(accounts, count);

                    printf("Amount deposited successfully.\n");
                    printf("New balance: %.2lf\n", accounts[index].balance);
                }
            }
            break;

        case 5:
            printf("Enter account number: ");
            scanf("%d", &accountNo);

            index = findAccount(accounts, count, accountNo);

            if (index == -1)
            {
                printf("Account not found.\n");
            }
            else
            {
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);

                if (amount <= 0)
                {
                    printf("Amount must be greater than zero.\n");
                }
                else if (amount > accounts[index].balance)
                {
                    printf("Insufficient balance.\n");
                }
                else
                {
                    accounts[index].balance = accounts[index].balance - amount;
                    saveToFile(accounts, count);

                    printf("Amount withdrawn successfully.\n");
                    printf("Remaining balance: %.2lf\n", accounts[index].balance);
                }
            }
            break;

        case 6:
            printf("Enter account number to update: ");
            scanf("%d", &accountNo);

            index = findAccount(accounts, count, accountNo);

            if (index == -1)
            {
                printf("Account not found.\n");
            }
            else
            {
                printf("Enter new account holder name: ");
                scanf(" %[^\n]", accounts[index].name);

                printf("Enter new phone number: ");
                scanf(" %[^\n]", accounts[index].phone);

                printf("Enter new account type: ");
                scanf(" %[^\n]", accounts[index].accountType);

                saveToFile(accounts, count);

                printf("Account updated successfully.\n");
            }
            break;

        case 7:
            printf("Enter account number to delete: ");
            scanf("%d", &accountNo);

            index = findAccount(accounts, count, accountNo);

            if (index == -1)
            {
                printf("Account not found.\n");
            }
            else
            {
                for (i = index; i < count - 1; i++)
                {
                    accounts[i] = accounts[i + 1];
                }

                count--;

                saveToFile(accounts, count);

                printf("Account deleted successfully.\n");
            }
            break;

        case 8:
            saveToFile(accounts, count);
            printf("Thank you for using Bank Account System.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 8);

    free(accounts);

    return 0;
}
