#include<stdio.h>
#include<string.h>
#define SIZE 51
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
/*
    可以优化到三维dp[][][]
*/
int main()
{
    int m,n,i,j,k,l,Map[SIZE][SIZE],dp[SIZE][SIZE][SIZE][SIZE];
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
                for(l=1;l<=n;l++)
                {
                    if(i!=k||j!=l||(i==m&&j==n&&k==m&&l==n))
                    {
                        dp[i][j][k][l]=Map[i][j]+Map[k][l]+max(dp[i-1][j][k-1][l],max(dp[i-1][j][k][l-1],max(dp[i][j-1][k][l-1],dp[i][j-1][k-1][l])));
                    }
                }
            }
        }
    }
    printf("%d\n",dp[m][n][m][n]);
    return 0;
}
