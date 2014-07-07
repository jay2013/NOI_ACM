#include<stdio.h>
int main()
{
    int a,b,k;
    scanf("%d %d",&a,&b);
    for(k=1;;k++)
    {
        if((k*b+1)%a==0)
        {
            printf("%d\n",(k*b+1)/a);
            break;
        }
    }
    return 0;
}
