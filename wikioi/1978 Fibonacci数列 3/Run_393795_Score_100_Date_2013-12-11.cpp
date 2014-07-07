#include<stdio.h>
int main()
{
    int a[42],i,n;
    a[1]=a[2]=1;
    for(i=3;i<41;i++)a[i]=a[i-1]+a[i-2];
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}
