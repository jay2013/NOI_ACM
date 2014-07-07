#include<cstdio>
using namespace std;
long long m,b,c,x0,n,g;
struct MATRIX
{
    int a[2][2];
    void init()
    {
        a[0][0]=b;
        a[0][1]=0;
        a[1][0]=1;
        a[1][1]=1;
    }
};
MATRIX powerMatrix(MATRIX mx,int n,int mod)
{
    if(n==1)return mx;
    MATRIX tmp=powerMatrix(mx,n/2,mod);
    MATRIX ans;
    ans.a[0][0]=((tmp.a[0][0]*tmp.a[0][0])%mod+(tmp.a[0][1]*tmp.a[1][0])%mod)%mod;
    ans.a[0][1]=((tmp.a[0][0]*tmp.a[0][1])%mod+(tmp.a[0][1]*tmp.a[1][1])%mod)%mod;
    ans.a[1][0]=((tmp.a[1][0]*tmp.a[0][0])%mod+(tmp.a[1][1]*tmp.a[1][0])%mod)%mod;
    ans.a[1][1]=((tmp.a[1][0]*tmp.a[0][1])%mod+(tmp.a[1][1]*tmp.a[1][1])%mod)%mod;
    if (n%2==1)
    {
        tmp.a[0][0]=((ans.a[0][0]*b)%mod+ans.a[0][1])%mod;
        tmp.a[0][1]=ans.a[0][1];
        tmp.a[1][0]=((ans.a[1][0]*b)%mod+ans.a[1][1])%mod;
        tmp.a[1][1]=ans.a[1][1];
        ans.a[0][0]=tmp.a[0][0];
        ans.a[0][1]=tmp.a[0][1];
        ans.a[1][0]=tmp.a[1][0];
        ans.a[1][1]=tmp.a[1][1];
    }
    return ans;
}
int main()
{
    scanf("%lld %lld %lld %lld %lld %lld",&m,&b,&c,&x0,&n,&g);
    MATRIX tmp;
    tmp.init();
    MATRIX ans=powerMatrix(tmp,n,m);
    long long myans=(x0*ans.a[0][0]%m+c*ans.a[1][0]%m)%m;
    printf("%lld\n",myans%g);
    return 0;
}
