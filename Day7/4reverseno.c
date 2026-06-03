#include <stdio.h>
int rev(int n, int re)
{
   if (n == 0)
   {
      return re;
   }
   else
   {
      return rev(n / 10, re * 10 + n % 10);
   }
}
int main()
{
   int n;
   printf("enter a no:");
   scanf("%d", &n);
   if (n != 0)
   {
      printf("reverse of %d is %d", n, rev(n, 0));
   }
  return 0;
}
