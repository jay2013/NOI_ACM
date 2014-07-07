#include<stdio.h>
int n,m,k,x,tmp;
int exp(int k)
{
    if(k==0)return 1;
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

    scanf("%d %d %d %d",&n,&m,&k,&x);
    tmp=exp(k);
    printf("%d\n",(x+tmp*m)%n);
    return 0;
}
