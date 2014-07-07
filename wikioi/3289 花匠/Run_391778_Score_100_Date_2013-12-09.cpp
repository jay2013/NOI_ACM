#include<stdio.h>
#define SIZE 100010
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,a[SIZE],S[SIZE][2],i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    S[1][0]=1;
    S[1][1]=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            S[i][0]=max(S[i-1][1]+1,S[i-1][0]);
            S[i][1]=S[i-1][1];
        }
        else if(a[i]<a[i-1])
        {
            S[i][1]=max(S[i-1][0]+1,S[i-1][1]);
            S[i][0]=S[i-1][0];
        }
        else
        {
            S[i][0]=S[i-1][0];
            S[i][1]=S[i-1][1];
        }
    }
    printf("%d\n",S[n][1]>S[n][0]?S[n][1]:S[n][0]);
    return 0;
}
