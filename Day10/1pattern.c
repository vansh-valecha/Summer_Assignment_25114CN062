#include <stdio.h>
int main()
{
    int i, j;
    //1st loop rum for row & second for coloumn . coulumn rum upto 3,5...
    for (i = 1; i <= 5; i++)
    {
        for (j = 4; j >= i; j--)
        {
          //provide starting space
            printf(" ");
        }
        for (j = 1; j <= i * 2 - 1; j++)
        {
          //it will give *.
            printf("*");
        }
      //it shoft to the next line after first row.
        printf("\n");
    }
    return 0;
}
