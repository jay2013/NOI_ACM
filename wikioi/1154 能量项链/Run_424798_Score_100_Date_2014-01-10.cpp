#include<cstdio>
#include<cstring>
#include<algorithm>
#define SIZE 220
using namespace std;
int dp[SIZE][SIZE],a[SIZE];
int ans;
int main()
{
    int N,i,j,k;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        a[N+i]=a[i];
    }
    memset(dp,0,sizeof(dp));
    for(j=1;j<N;j++)
    {
        for(i=1;i+j<2*N;i++)
        {
            int tmp=0;
            for(k=0;k<j;k++)
            {
                tmp=max(tmp,dp[i][i+k]+dp[i+k+1][i+j]+a[i]*a[i+k+1]*a[i+j+1]);
            }
            dp[i][i+j]=tmp;
        }
    }
    ans=0;
    for(i=1;i<=N;i++)
    {
        ans=max(ans,dp[i][i+N-1]);
    }
    printf("%d\n",ans);
    return 0;
}
