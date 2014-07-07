#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[50];
long long dp[41][7];
long long calc(int i,int j)
{
    long long ans=0;
    for(int x=i-1;x<j;x++)
        ans=ans*10+str[x]-'0';
    return ans;
}
int main()
{
    int N,K,i,k,t;
    scanf("%d %d",&N,&K);
    scanf("%s",str);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=N;i++)dp[i][0]=calc(i,i);
    for(i=1;i<=N;i++)
    {
        for(k=1;k<=K;k++)
        {
            if(i<=k)dp[i][k]=0;
            else
            {
                dp[i][k]=0;
                for(t=1;t<i;t++)
                {
                    dp[i][k]=max(dp[i][k],dp[i-t][k-1]*calc(i-t+1,i));
                }
            }
        }
    }
    printf("%lld\n",dp[N][K]);
    return 0;
}
