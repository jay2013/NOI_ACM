#include<cstdio>
using namespace std;
struct MATRIX
{
    int a[2][2];
    void init()
    {
        a[0][0]=a[0][1]=a[1][0]=1;
        a[1][1]=0;
    }
};
MATRIX powerMatrix(MATRIX mx,int n,int mod)
{
    if(n==1)return mx;
    MATRIX tmp=powerMatrix(mx,n/2,mod);
    MATRIX ans;
    ans.a[0][0]=(tmp.a[0][0]*tmp.a[0][0]+tmp.a[0][1]*tmp.a[1][0])%mod;
    ans.a[0][1]=(tmp.a[0][0]*tmp.a[0][1]+tmp.a[0][1]*tmp.a[1][1])%mod;
    ans.a[1][0]=(tmp.a[1][0]*tmp.a[0][0]+tmp.a[1][1]*tmp.a[1][0])%mod;
    ans.a[1][1]=(tmp.a[1][0]*tmp.a[0][1]+tmp.a[1][1]*tmp.a[1][1])%mod;
    if (n%2==1)
    {
        tmp.a[0][0]=(ans.a[0][0]+ans.a[0][1])%mod;
        tmp.a[0][1]=ans.a[0][0];
        tmp.a[1][0]=(ans.a[1][0]+ans.a[1][1])%mod;
        tmp.a[1][1]=ans.a[1][0];
        ans.a[0][0]=tmp.a[0][0];
        ans.a[0][1]=tmp.a[0][1];
        ans.a[1][0]=tmp.a[1][0];
        ans.a[1][1]=tmp.a[1][1];
    }
    return ans;
}
int main()
{
    int T,n,q;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&q);
        MATRIX tmp;
        tmp.init();
        MATRIX ans=powerMatrix(tmp,n,q);
        printf("%d\n",ans.a[0][0]);
    }
    return 0;
}
