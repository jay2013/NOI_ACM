#include<stdio.h>
#include<string.h>
#define SIZE 60
using namespace std;
int n,m,i,j,dp[SIZE][SIZE],x1,y1,x2,y2;
int main()
{
    scanf("%d %d %d %d %d %d",&n,&m,&x1,&y1,&x2,&y2);
    memset(dp,0,sizeof(dp));
    dp[x1][y1]=1;
    for(i=x1+1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp[i][j]+=dp[i-1][j-2];
            dp[i][j]+=dp[i-1][j+2];
            dp[i][j]+=dp[i-2][j-1];
            dp[i][j]+=dp[i-2][j+1];
        }
    }
    printf("%d\n",dp[x2][y2]);
    return 0;
}
