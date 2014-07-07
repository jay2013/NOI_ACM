#include<stdio.h>
void Ext_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        int t;
        Ext_gcd(b,a%b,x,y);
        t=x;
        x=y;
        y=t-(a/b)*y;
    }
}
int main()
{
    int a,b,x,y;
    scanf("%d %d",&a,&b);
    Ext_gcd(a,b,x,y);
    while(x<0)
    {
        x+=b;
    }
    while(x>b)
    {
        x-=b;
    }
    printf("%d\n",x);
    return 0;
}
