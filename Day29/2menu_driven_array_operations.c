#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size)
{
    int i;

    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX_SIZE];
    int size = 0, choice, i, pos, value, found, temp;

    do
    {
        printf("\n===== Menu Driven Array Operations =====\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Update Element\n");
        printf("7. Sort Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &size);

            if (size < 0 || size > MAX_SIZE)
            {
                printf("Invalid size! Size must be between 0 and %d.\n", MAX_SIZE);
                size = 0;
                break;
            }

            printf("Enter %d elements:\n", size);
            for (i = 0; i < size; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("Array created successfully.\n");
            break;

        case 2:
            displayArray(arr, size);
            break;

        case 3:
            if (size == MAX_SIZE)
            {
                printf("Array is full. Cannot insert more elements.\n");
                break;
            }

            printf("Enter position to insert (1 to %d): ", size + 1);
            scanf("%d", &pos);

            if (pos < 1 || pos > size + 1)
            {
                printf("Invalid position.\n");
                break;
            }

            printf("Enter value to insert: ");
            scanf("%d", &value);

            for (i = size; i >= pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos - 1] = value;
            size++;
            printf("Element inserted successfully.\n");
            break;

        case 4:
            if (size == 0)
            {
                printf("Array is empty. Cannot delete element.\n");
                break;
            }

            printf("Enter position to delete (1 to %d): ", size);
            scanf("%d", &pos);

            if (pos < 1 || pos > size)
            {
                printf("Invalid position.\n");
                break;
            }

            value = arr[pos - 1];
            for (i = pos - 1; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            size--;
            printf("Deleted element: %d\n", value);
            break;

        case 5:
            if (size == 0)
            {
                printf("Array is empty.\n");
                break;
            }

            printf("Enter value to search: ");
            scanf("%d", &value);
            found = 0;

            for (i = 0; i < size; i++)
            {
                if (arr[i] == value)
                {
                    printf("Element found at position %d.\n", i + 1);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Element not found.\n");
            }
            break;

        case 6:
            if (size == 0)
            {
                printf("Array is empty. Cannot update element.\n");
                break;
            }

            printf("Enter position to update (1 to %d): ", size);
            scanf("%d", &pos);

            if (pos < 1 || pos > size)
            {
                printf("Invalid position.\n");
                break;
            }

            printf("Enter new value: ");
            scanf("%d", &value);
            arr[pos - 1] = value;
            printf("Element updated successfully.\n");
            break;

        case 7:
            if (size == 0)
            {
                printf("Array is empty. Cannot sort.\n");
                break;
            }

            for (i = 0; i < size - 1; i++)
            {
                int j;
                for (j = i + 1; j < size; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Array sorted in ascending order.\n");
            break;

        case 8:
            printf("Exiting array operations system...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
