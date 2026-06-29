#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

struct Product
{
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

void removeNewline(char str[])
{
    int length = strlen(str);

    if (length > 0 && str[length - 1] == '\n')
    {
        str[length - 1] = '\0';
    }
}

int findProduct(struct Product products[], int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (products[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void displayProduct(struct Product product)
{
    printf("%-10d %-20s %-10d %.2f\n",
           product.id,
           product.name,
           product.quantity,
           product.price);
}

int main()
{
    struct Product products[MAX_PRODUCTS];
    int count = 0, choice, id, index, i;
    float totalValue;

    do
    {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count == MAX_PRODUCTS)
            {
                printf("Inventory is full. Cannot add more products.\n");
                break;
            }

            printf("Enter product ID: ");
            scanf("%d", &id);

            if (findProduct(products, count, id) != -1)
            {
                printf("Product ID already exists.\n");
                break;
            }

            products[count].id = id;
            printf("Enter product name: ");
            getchar();
            fgets(products[count].name, NAME_LENGTH, stdin);
            removeNewline(products[count].name);

            printf("Enter quantity: ");
            scanf("%d", &products[count].quantity);

            printf("Enter price: ");
            scanf("%f", &products[count].price);

            count++;
            printf("Product added successfully.\n");
            break;

        case 2:
            if (count == 0)
            {
                printf("No products available.\n");
                break;
            }

            printf("%-10s %-20s %-10s %s\n", "ID", "Name", "Quantity", "Price");
            for (i = 0; i < count; i++)
            {
                displayProduct(products[i]);
            }
            break;

        case 3:
            printf("Enter product ID to search: ");
            scanf("%d", &id);
            index = findProduct(products, count, id);

            if (index == -1)
            {
                printf("Product not found.\n");
            }
            else
            {
                printf("%-10s %-20s %-10s %s\n", "ID", "Name", "Quantity", "Price");
                displayProduct(products[index]);
            }
            break;

        case 4:
            printf("Enter product ID to update: ");
            scanf("%d", &id);
            index = findProduct(products, count, id);

            if (index == -1)
            {
                printf("Product not found.\n");
                break;
            }

            printf("Enter new product name: ");
            getchar();
            fgets(products[index].name, NAME_LENGTH, stdin);
            removeNewline(products[index].name);

            printf("Enter new quantity: ");
            scanf("%d", &products[index].quantity);

            printf("Enter new price: ");
            scanf("%f", &products[index].price);

            printf("Product updated successfully.\n");
            break;

        case 5:
            printf("Enter product ID to delete: ");
            scanf("%d", &id);
            index = findProduct(products, count, id);

            if (index == -1)
            {
                printf("Product not found.\n");
                break;
            }

            for (i = index; i < count - 1; i++)
            {
                products[i] = products[i + 1];
            }

            count--;
            printf("Product deleted successfully.\n");
            break;

        case 6:
            totalValue = 0;

            for (i = 0; i < count; i++)
            {
                totalValue += products[i].quantity * products[i].price;
            }

            printf("Total inventory value = %.2f\n", totalValue);
            break;

        case 7:
            printf("Exiting inventory management system...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
