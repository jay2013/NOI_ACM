#include<cstdio>
#include<algorithm>
using namespace std;
int A[1000],n,MAX,MIN,i,j,dp[1000],dp2[1000];
void init()
{
    n=0;
    while(scanf("%d",&A[n])!=EOF)n++;
}
void doit()
{
    MAX=1,MIN=0,dp[0]=1,dp2[0]=1;
    for(i=1;i<n;i++)
    {
        dp[i]=1;
        dp2[i]=1;
        for(j=i-1;j>=0;j--)
        {
            if(A[i]<A[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(dp[i]>MAX)MAX=dp[i];
        for(j=i-1;j>=0;j--)
        {
            if(A[i]>A[j])
            {
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
        if(dp2[i]>MIN)MIN=dp2[i];
    }
}
int main()
{
    init();
    doit();
    printf("%d %d\n",MAX,MIN);
    return 0;
}
