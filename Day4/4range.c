#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,z,i,arm,x,y,temp;
    printf("enter lower limit of range:");
    scanf("%d",&x);
    printf("enter upper limit of range:");
    scanf("%d",&y);

     if(x>=0&&y>=1)
     {
            printf("arm strong no in betweeen %d & %d is\n",x,y);
            for(i=x;i<=y;i++)
            {
                b=0;
                arm=0;


                    z=i;
                    temp=i;
                while(temp!=0)
                {
                    a=temp%10;
                    b++;
                    temp=temp/10;
                }
                temp=z;
            while(temp!=0)
                {
                    a=temp%10;
                    arm=arm+pow(a,b);
                    temp=temp/10;
                }
                if(arm==z)
                printf("%d\n",arm);
            }
        }    
     else
        {
            printf("not possible");
        }
}
    