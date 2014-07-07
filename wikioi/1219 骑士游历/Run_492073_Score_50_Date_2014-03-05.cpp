#include<stdio.h>
#include<string.h>
#define SIZE 55
using namespace std;
int n,m,i,j,dp[SIZE][SIZE],x1,y1,x2,y2;
int check(int x,int y)
{
    if(x>0&&x<=n&&y>0&&y<=m)return 1;
    else return 0;
}
int main()
{
    scanf("%d %d %d %d %d %d",&n,&m,&x1,&y1,&x2,&y2);
    memset(dp,0,sizeof(dp));
    dp[x1][y1]=1;
    for(i=x1+1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            //(i-1,j-2)
            if(check(i-1,j-2))dp[i][j]+=dp[i-1][j-2];
            //(i-1,j+2)
            if(check(i-1,j+2))dp[i][j]+=dp[i-1][j+2];
            //(i-2,j-1)
            if(check(i-2,j-1))dp[i][j]+=dp[i-2][j-1];
            //(i-2,j+1)
            if(check(i-2,j+1))dp[i][j]+=dp[i-2][j+1];
        }
    }
    printf("%d\n",dp[x2][y2]);
    return 0;
}
