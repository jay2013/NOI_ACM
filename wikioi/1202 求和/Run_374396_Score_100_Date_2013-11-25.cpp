#include<stdio.h>
int main()
{
    int n,sum=0,i,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        sum+=tmp;
    }
    printf("%d\n",sum);
    return 0;
}
