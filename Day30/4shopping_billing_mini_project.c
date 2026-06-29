// Write a program to develop complete mini project using arrays, strings and functions.
// Mini project: Shopping billing system.

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_SIZE 50

int findItem(char names[][NAME_SIZE], int count, char itemName[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(names[i], itemName) == 0)
        {
            return i;
        }
    }

    return -1;
}

float calculateItemTotal(int quantity, float price)
{
    return quantity * price;
}

void addItem(char names[][NAME_SIZE], int quantities[], float prices[], int *count)
{
    char itemName[NAME_SIZE];
    int index, quantity;
    float price;

    if (*count == MAX_ITEMS)
    {
        printf("Bill is full. Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf(" %[^\n]", itemName);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    if (quantity <= 0 || price < 0)
    {
        printf("Invalid quantity or price.\n");
        return;
    }

    index = findItem(names, *count, itemName);

    if (index == -1)
    {
        strcpy(names[*count], itemName);
        quantities[*count] = quantity;
        prices[*count] = price;
        (*count)++;
    }
    else
    {
        quantities[index] += quantity;
        prices[index] = price;
    }

    printf("Item added successfully.\n");
}

void displayItems(char names[][NAME_SIZE], int quantities[], float prices[], int count)
{
    int i;
    float itemTotal;

    if (count == 0)
    {
        printf("No items added yet.\n");
        return;
    }

    printf("\n%-5s %-25s %-10s %-10s %s\n", "No.", "Item", "Qty", "Price", "Total");

    for (i = 0; i < count; i++)
    {
        itemTotal = calculateItemTotal(quantities[i], prices[i]);
        printf("%-5d %-25s %-10d %-10.2f %.2f\n",
               i + 1,
               names[i],
               quantities[i],
               prices[i],
               itemTotal);
    }
}

float calculateSubtotal(int quantities[], float prices[], int count)
{
    int i;
    float subtotal = 0;

    for (i = 0; i < count; i++)
    {
        subtotal += calculateItemTotal(quantities[i], prices[i]);
    }

    return subtotal;
}

float calculateDiscount(float subtotal)
{
    if (subtotal >= 5000)
    {
        return subtotal * 0.10f;
    }

    if (subtotal >= 2000)
    {
        return subtotal * 0.05f;
    }

    return 0;
}

void updateItem(char names[][NAME_SIZE], int quantities[], float prices[], int count)
{
    char itemName[NAME_SIZE];
    int index;

    printf("Enter item name to update: ");
    scanf(" %[^\n]", itemName);

    index = findItem(names, count, itemName);

    if (index == -1)
    {
        printf("Item not found.\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &quantities[index]);

    printf("Enter new price: ");
    scanf("%f", &prices[index]);

    if (quantities[index] <= 0 || prices[index] < 0)
    {
        printf("Invalid data. Item values changed to zero.\n");
        quantities[index] = 0;
        prices[index] = 0;
    }
    else
    {
        printf("Item updated successfully.\n");
    }
}

void deleteItem(char names[][NAME_SIZE], int quantities[], float prices[], int *count)
{
    char itemName[NAME_SIZE];
    int index, i;

    printf("Enter item name to delete: ");
    scanf(" %[^\n]", itemName);

    index = findItem(names, *count, itemName);

    if (index == -1)
    {
        printf("Item not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++)
    {
        strcpy(names[i], names[i + 1]);
        quantities[i] = quantities[i + 1];
        prices[i] = prices[i + 1];
    }

    (*count)--;

    printf("Item deleted successfully.\n");
}

void printFinalBill(char names[][NAME_SIZE], int quantities[], float prices[], int count)
{
    float subtotal, discount, tax, grandTotal;

    if (count == 0)
    {
        printf("No items available for bill.\n");
        return;
    }

    displayItems(names, quantities, prices, count);

    subtotal = calculateSubtotal(quantities, prices, count);
    discount = calculateDiscount(subtotal);
    tax = (subtotal - discount) * 0.05f;
    grandTotal = subtotal - discount + tax;

    printf("\nSubtotal   : %.2f\n", subtotal);
    printf("Discount   : %.2f\n", discount);
    printf("GST 5%%     : %.2f\n", tax);
    printf("Grand Total: %.2f\n", grandTotal);
}

int main()
{
    char names[MAX_ITEMS][NAME_SIZE];
    int quantities[MAX_ITEMS];
    float prices[MAX_ITEMS];
    int count = 0, choice;

    do
    {
        printf("\n===== Shopping Billing Mini Project =====\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Print Final Bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem(names, quantities, prices, &count);
            break;

        case 2:
            displayItems(names, quantities, prices, count);
            break;

        case 3:
            updateItem(names, quantities, prices, count);
            break;

        case 4:
            deleteItem(names, quantities, prices, &count);
            break;

        case 5:
            printFinalBill(names, quantities, prices, count);
            break;

        case 6:
            printf("Exiting shopping billing project.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
