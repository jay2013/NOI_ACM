#include<cstdio>
#include<algorithm>
#define SIZE 220
using namespace std;
long long dp[SIZE][SIZE],a[SIZE];
long long ans;
int main()
{
    int N,i,j,k;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        a[N+i]=a[i];
        dp[i][i]=0;
    }
    for(j=1;j<N;j++)
    {
        for(i=1;i<=N;i++)
        {
            dp[i][i+j]=0;
            for(k=0;k<j;k++)
            {
                dp[i][i+j]=max(dp[i][i+j],dp[i][i+k]+dp[i+k+1][i+j]+a[i]*a[i+k+1]*a[i+j+1]);
            }
            //printf("%d %d %d\n",i,i+j,dp[i][i+j]);
        }
    }
    ans=0;
    for(i=1;i<=N;i++)
    {
        ans=max(ans,dp[i][i+N-1]);
    }
    printf("%lld\n",ans);
    return 0;
}
