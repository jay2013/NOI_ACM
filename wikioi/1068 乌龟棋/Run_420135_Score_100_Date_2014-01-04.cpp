#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,dp[41][41][41][41],i,j,k,l,A[355],a=0,b=0,c=0,d=0,tmp;
int main()
{
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++)scanf("%d",&A[i]);
    for(i=1;i<=M;i++)
    {
        scanf("%d",&tmp);
        if(tmp==1)a++;
        else if(tmp==2)b++;
        else if(tmp==3)c++;
        else d++;
    }
    //dp[i][j][k][l]为使用i,j,k,l，获得的最多分数
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=b;j++)
        {
            for(k=0;k<=c;k++)
            {
                for(l=0;l<=d;l++)
                {
                    int tmpp=A[1+i+2*j+3*k+4*l];
                    if(i+j+k+l==0)dp[i][j][k][l]=A[1];
                    else
                    {
                        dp[i][j][k][l]=0;
                        if(i>0)dp[i][j][k][l]=max(dp[i][j][k][l],tmpp+dp[i-1][j][k][l]);
                        if(j>0)dp[i][j][k][l]=max(dp[i][j][k][l],tmpp+dp[i][j-1][k][l]);
                        if(k>0)dp[i][j][k][l]=max(dp[i][j][k][l],tmpp+dp[i][j][k-1][l]);
                        if(l>0)dp[i][j][k][l]=max(dp[i][j][k][l],tmpp+dp[i][j][k][l-1]);
                    }
                }
            }
        }
    }
    printf("%d\n",dp[a][b][c][d]);
    return 0;
}
