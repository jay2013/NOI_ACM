#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int V,n,a[33],i,j,dp[204800];
    scanf("%d %d",&V,&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        for(j=V;j>=a[i];j--)
        {
            if(dp[j-a[i]]+a[i]>dp[j])dp[j]=dp[j-a[i]]+a[i];
        }
    }
    printf("%d\n",V-dp[V]);
    return 0;
}
