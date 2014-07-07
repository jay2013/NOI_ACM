#include<stdio.h>
#include<string.h>
int n,k,X,P[102],V[102],N[102],temp,ans;
double tmp;
int dp[102][1024];
void init()
{
    ans=0;
    scanf("%d %d %lf",&n,&k,&tmp);
    X=int(tmp*10);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf",&tmp);
        P[i]=int(tmp*10);
    }
    for(int i=1; i<=n; i++)scanf("%d",&V[i]);
    for(int i=1; i<=n; i++)scanf("%d",&N[i]);
    for(int i=2; i<=n; i++)
    {
        int flag=0;
        for(int j=1; j<i; j++)
        {
            if(N[i]==N[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            for(int j=i; j<n; j++)
            {
                P[j]=P[j+1];
                V[j]=V[j+1];
                N[j]=N[j+1];
            }
            i--;
            n--;
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        printf("%d %d %d \n",P[i],V[i],N[i]);
    }
    printf("weiueiwoiew\n");
    */
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&temp);
        int pos=-1;
        for(int j=1; j<=n; j++)
        {
            if(N[j]==temp)
            {
                X-=P[j];
                ans+=V[j];
                pos=j;
                break;
            }
        }
        for(int j=pos; j<n; j++)
        {
            P[j]=P[j+1];
            V[j]=V[j+1];
            N[j]=N[j+1];
        }
        n--;
    }
    /*
    for(int i=1; i<=n; i++)
    {
        printf("%d %d %d \n",P[i],V[i],N[i]);
    }
    printf("%d %d\n",X,ans);
    */
}
void deal_dp()
{
    memset(dp,0,sizeof(dp));
    for(int i=0;i<1024;i++)
    {
        if(P[1]<=i)dp[1][i]=V[1];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<1024;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=P[i]&&dp[i-1][j-P[i]]+V[i]>dp[i][j])
                dp[i][j]=dp[i-1][j-P[i]]+V[i];
        }
    }
    ans+=dp[n][X];
}
int main()
{
    init();
    deal_dp();
    printf("%d\n",ans);
    return 0;
}
