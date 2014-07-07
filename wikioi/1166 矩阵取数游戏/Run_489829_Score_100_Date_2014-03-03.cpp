#include<stdio.h>
#include<string.h>
#include<algorithm>
#define SIZE 32
#define SIZE2 81
using namespace std;
struct BigInt
{
    int a[SIZE];
    void init()
    {
        memset(a,0,sizeof(a));
    }
};
BigInt add(BigInt x,BigInt y)
{
    BigInt ans;
    ans.init();
    for(int i=0; i<SIZE; i++)
    {
        ans.a[i]=ans.a[i]+x.a[i]+y.a[i];
        if(ans.a[i]>9)
        {
            ans.a[i+1]=ans.a[i+1]+ans.a[i]/10;
            ans.a[i]=ans.a[i]%10;
        }
    }
    return ans;
}
BigInt bigint_max(BigInt x,BigInt y)
{
    for(int i=SIZE-1; i>=0; i--)
    {
        if(x.a[i]>y.a[i])return x;
        else if(x.a[i]<y.a[i])return y;
        else continue;
    }
    return x;
}
void print(BigInt x)
{
    int pos=0,i;
    for(i=SIZE-1; i>=0; i--)
    {
        if(x.a[i]>0)
        {
            pos=i;
            break;
        }
    }
    for(i=pos; i>=0; i--)
        printf("%d",x.a[i]);
    printf("\n");
}

int main()
{
    int n,m,i,j,tmp,k,l;
    BigInt dp[SIZE2][SIZE2],sum,data[SIZE2][SIZE2];
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&tmp);
            data[i][j].init();
            int pos=0;
            while(tmp)
            {
                data[i][j].a[pos++]=tmp%10;
                tmp/=10;
            }
        }
    }

    sum.init();

    for(i=1; i<=n; i++)
    {
        for(j=0;j<SIZE2;j++)
        {
            for(k=0;k<SIZE2;k++)
            {
                dp[j][k].init();
            }
        }

        for(j=1; j<=m; j++)
        {
            dp[j][j]=add(data[i][j],data[i][j]);
        }

        for(j=1; j<m; j++)
        {
            for(k=1; k<=m; k++)
            {
                if(j+k>m)break;
                BigInt tmp1= add(dp[k+1][k+j],data[i][k]);
                BigInt tmp2= add(dp[k][k+j-1],data[i][k+j]);
                dp[k][k+j]= bigint_max(tmp1,tmp2);
                dp[k][k+j]=add(dp[k][k+j],dp[k][k+j]);
            }
        }
        sum=add(sum,dp[1][m]);
    }
    print(sum);
    return 0;
}
