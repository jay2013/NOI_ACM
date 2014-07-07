#include<stdio.h>
int f(int n)
{
    if(n==0)return 0;
    else if(n==1)return 1;
    else return 2*f(n-1)+1;
}
void step(int n,int a,int b,int c)
{
    if(n==1)
    {
        printf("%d from %c to %c\n",n,a-1+'A',c-1+'A');
    }
    else
    {
        step(n-1,a,c,b);
        printf("%d from %c to %c\n",n,a-1+'A',c-1+'A');
        step(n-1,b,a,c);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    step(n,1,2,3);
    return 0;
}
