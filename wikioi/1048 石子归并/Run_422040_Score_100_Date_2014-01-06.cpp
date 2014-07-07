#include<cstdio>
#include<algorithm>
using namespace std;
int n,w[110],dp[110][110],sum[110],i,j,k;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum[i]=sum[i-1]+w[i];
    }
    for(j=0;j<n;j++)
    {
        for(i=1;i<=n-j;i++)
        {
            if(j==0)
            {
                dp[i][i+j]=0;
            }
            else
            {
                dp[i][i+j]=90000000;
                for(k=0;k<j;k++)
                {
                    dp[i][i+j]=min(dp[i][i+j],dp[i][i+k]+dp[i+k+1][i+j]+sum[i+j]-sum[i-1]);
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
