#include<stdio.h>
int main()
{
    int a[1010],i,n,j;
    a[1]=1;
    for(i=2;i<1010;i++)
    {
        a[i]=1;
        for(j=1;j<=i/2;j++)
        {
            a[i]+=a[j];
        }
    }
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}
