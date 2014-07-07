#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,j,data[85][85],dp[85][85],k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    long long sum = 0L;
    for(i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        for(j=0;j<m;j++)
        {
            for(k=1;k<=m;k++)
            {
                if(k+j>m)break;
                dp[k][k+j]= max(2*(dp[k+1][k+j]+data[i][k]),2*(dp[k][k+j-1]+data[i][k+j]));
            }
        }
        //printf("%d\n",dp[1][m]);
        sum+=dp[1][m];
    }
    printf("%lld\n",sum);
    return 0;
}
