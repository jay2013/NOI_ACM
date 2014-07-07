#include<stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int main()
{
    int x0,y0,i,ans=0;
    scanf("%d %d",&x0,&y0);
    for(i=x0;i<=y0;i++)
    {
        if(y0%i==0)
        {
            if(gcd(i,x0*y0/i)==x0&&lcm(i,x0*y0/i)==y0)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
