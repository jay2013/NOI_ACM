#include<stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    int x0,y0;
    scanf("%d %d",&x0,&y0);
    printf("%d\n",gcd(x0,y0));
    return 0;
}
