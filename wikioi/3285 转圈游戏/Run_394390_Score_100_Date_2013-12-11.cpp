#include<stdio.h>
long long n,m,k,x,tmp;
long long exp(long long k)
{
    if(k==0)return 1L;
    else
    {
        if(k%2==1)
        {
            tmp=exp(k/2)%n;
            return (((10*tmp)%n)*tmp)%n;
        }
        else
        {
            tmp=exp(k/2)%n;
            return tmp*tmp;
        }
    }
}
int main()
{

    scanf("%lld %lld %lld %lld",&n,&m,&k,&x);
    tmp=exp(k);
    printf("%lld\n",(x+tmp*m)%n);
    return 0;
}
