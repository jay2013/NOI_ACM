#include<stdio.h>
int main()
{
    int N,a[10010],pre[10010],MAX,ans[10010],i,dp[10010],j,s,tmp;
    scanf("%d",&N);
    for(i=1;i<=N;i++)scanf("%d",&a[i]),dp[i]=0;
    dp[1]=1;
    MAX=1;
    for(i=2;i<=N;i++)
    {
        dp[i]=1;
        pre[i]=-1;
        for(j=i-1;j>=1;j--)
        {
            if(a[i]>a[j]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
        }
        if(MAX<dp[i])MAX=dp[i];
    }
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d",&tmp);
        if(tmp>MAX)printf("Impossible\n");
        else
        {
            int pos=-1;
            for(i=1;i<=N;i++)
            {
                if(dp[i]==tmp)
                {
                    pos=i;
                    break;
                }
            }
            int cnt=0;
            while(1)
            {
                ans[cnt++]=a[pos];
                if(pre[pos]==-1)break;
                pos=pre[pos];
            }
            for(i=cnt-1;i>=0;i--)
            {
                printf("%d%c",ans[i],i==0?'\n':' ');
            }
        }
    }
    return 0;
}
