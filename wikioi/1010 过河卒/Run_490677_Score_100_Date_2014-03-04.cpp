#include<stdio.h>
#include<string.h>
int Map[20][20],dp[20][20],n,m,x,y,i,j;
int main()
{
    scanf("%d %d %d %d",&x,&y,&n,&m);
    memset(Map,0,sizeof(Map));
    memset(dp,0,sizeof(dp));
    Map[n-1][m-2]=1;
    Map[n+1][m-2]=1;
    Map[n-2][m-1]=1;
    Map[n+2][m-1]=1;
    Map[n][m]=1;
    Map[n-2][m+1]=1;
    Map[n-1][m+2]=1;
    Map[n+1][m+2]=1;
    Map[n+2][m+1]=1;
    dp[0][0]=1;
    int up,left;
    for(i=1;i<=y;i++)
    {
        if(Map[0][i]==1)dp[0][i]=0;
        else dp[0][i]=dp[0][i-1];
    }
    for(j=1;j<=x;j++)
    {
        if(Map[j][0]==1)dp[j][0]=0;
        else dp[j][0]=dp[j-1][0];
    }
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=y;j++)
        {
            if(Map[i][j]==1)dp[i][j]=0;
            else dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    printf("%d\n",dp[x][y]);
    return 0;
}
