#include<stdio.h>
#include<string.h>
#define SIZE 51
using namespace std;
int Map[SIZE][SIZE],dp[SIZE][SIZE][SIZE];
int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int m,n,i,j,k,l;
    scanf("%d %d",&m,&n);
    memset(Map,0,sizeof(Map));
    memset(dp,0,sizeof(dp));
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&Map[i][j]);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=m;k++)
            {
                if(i!=k||(j!=(i+j-k))||(i==m&&j==n&&k==m))
                {
                    dp[i][j][k]=Map[i][j]+Map[k][i+j-k]+max(dp[i-1][j][k-1],max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j-1][k-1])));
                }
            }
        }
    }
    printf("%d\n",dp[m][n][m]);
    return 0;
}
