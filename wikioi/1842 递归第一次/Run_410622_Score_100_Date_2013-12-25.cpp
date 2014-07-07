#include<stdio.h>
int f(int x)
{
    if(x>=0)return 5;
    else return f(x+1)+f(x+2)+1;
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",f(x));
    return 0;
}
