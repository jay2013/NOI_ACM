#include<stdio.h>
int step(int n)
{
    if(n==1)return 0;
    else if(n%2==0)
    {
        return 1+step(n/2);
    }
    else
    {
        return 1+step(3*n+1);
    }
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",step(n));
    }
    return 0;
}
