#include<cstdio>
#include<algorithm>
using namespace std;
int A[5000],n,MAX,i,j,dp[1000];
void init()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
}
void doit()
{
    MAX=1,dp[0]=1;
    for(i=1;i<n;i++)
    {
        dp[i]=1;
        for(j=i-1;j>=0;j--)
        {
            if(A[i]>A[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(dp[i]>MAX)MAX=dp[i];
    }
}
int main()
{
    init();
    doit();
    printf("%d\n",MAX);
    return 0;
}
