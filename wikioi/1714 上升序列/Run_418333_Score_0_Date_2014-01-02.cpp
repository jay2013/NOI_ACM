#include<stdio.h>
int main()
{
    int N,a[10010],ans[10010],i,dp[10010],j,s,tmp;
    scanf("%d",&N);
    for(i=1; i<=N; i++)scanf("%d",&a[i]),dp[i]=0;
    dp[N]=1;
    for(i=N-1; i>=1; i--)
    {
        dp[i]=1;
        for(j=i+1; j<=N; j++)
        {
            if(a[i]<a[j]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    //for(i=1;i<=N;i++)printf("%d ",dp[i]);
    //printf("\n");
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d",&tmp);
        int cnt=0;
        for(i=1; i<=N; i++)
        {
            if(dp[i]>=tmp&&tmp)
            {
                ans[++cnt]=a[i];
                tmp--;
            }
        }
        //printf("%d\n",tmp);
        if(tmp>0)printf("Impossible\n");
        else
        {
            for(i=1;i<=cnt;i++)
            {
                printf("%d%c",ans[i],i==cnt?'\n':' ');
            }
        }
    }
    return 0;
}
