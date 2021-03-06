#include<cstdio>
using namespace std;
long long m,b,c,x0,n,g;
struct MATRIX
{
    long long a[2][2];
    void init()
    {
        a[0][0]=b;
        a[0][1]=0;
        a[1][0]=1;
        a[1][1]=1;
    }
};
long long Multiply(long long x, long long y,long long mod)
{
    long long ans = 0;
    while(y)
    {
        if(y & 1) ans = (ans + x) % mod;
        x = (x << 1) % mod;
        y >>= 1;
    }
    return ans;
}
MATRIX powerMatrix(MATRIX mx,long long n,long long mod)
{
    if(n==1)return mx;
    MATRIX tmp=powerMatrix(mx,n/2,mod);
    MATRIX ans;
    ans.a[0][0]=(Multiply(tmp.a[0][0],tmp.a[0][0],mod)+Multiply(tmp.a[0][1],tmp.a[1][0],mod))%mod;
    ans.a[0][1]=(Multiply(tmp.a[0][0],tmp.a[0][1],mod)+Multiply(tmp.a[0][1],tmp.a[1][1],mod))%mod;
    ans.a[1][0]=(Multiply(tmp.a[1][0],tmp.a[0][0],mod)+Multiply(tmp.a[1][1],tmp.a[1][0],mod))%mod;
    ans.a[1][1]=(Multiply(tmp.a[1][0],tmp.a[0][1],mod)+Multiply(tmp.a[1][1],tmp.a[1][1],mod))%mod;
    if (n%2==1)
    {
        tmp.a[0][0]=(Multiply(ans.a[0][0],b,mod)+ans.a[0][1])%mod;
        tmp.a[0][1]=ans.a[0][1];
        tmp.a[1][0]=(Multiply(ans.a[1][0],b,mod)+ans.a[1][1])%mod;
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
    long long myans=(Multiply(x0,ans.a[0][0],m)+Multiply(c,ans.a[1][0],m))%m;
    printf("%lld\n",myans%g);
    return 0;
}
