#include<stdio.h>
int main()
{
    int N,a[10010],next[10010],ans[10010],i,dp[10010],j,s,tmp;
    scanf("%d",&N);
    for(i=1; i<=N; i++)scanf("%d",&a[i]),dp[i]=0;
    dp[N]=1;
    next[N]=-1;
    for(i=N-1; i>=1; i--)
    {
        dp[i]=1;
        next[i]=-1;
        for(j=i+1; j<=N; j++)
        {
            if(a[i]<a[j]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                next[i]=j;
            }
        }
    }
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d",&tmp);
        int pos=-1;
        for(i=1; i<=N; i++)
        {
            if(dp[i]==tmp)
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)printf("Impossible\n");
        else
        {
            int cnt=0;
            while(1)
            {
                ans[++cnt]=a[pos];
                if(next[pos]==-1)break;
                pos=next[pos];
            }
            for(i=1; i<=cnt; i++)
            {
                printf("%d%c",ans[i],i==cnt?'\n':' ');
            }
        }
    }
    return 0;
}
