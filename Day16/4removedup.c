//Write a program to Remove duplicates from array. 
#include <stdio.h>
#include <stdlib.h>

void input(int a[], int n)
{
    int i;
    printf("enter array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void del(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<n-1;k++)
                {
                    a[k-1]=a[k];
                }
                n--; // dec the array size
                j--; // start loop from same position ie nullify i++ effect
            }
        }     
    }
    output(a,n);   
}

int main()
{
    int n, *a;
    printf("enter size of array:");
    scanf("%d", &n);
    // locate the memory for array of size n
    a = (int *)malloc(sizeof(int) * n);
    input(a, n);
    del(a, n);
    free(a);
    return 0;
}
