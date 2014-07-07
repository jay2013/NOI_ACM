#include<cstdio>
#include<string.h>
using namespace std;
int T,n,cnt;
int getAns(int n)
{
    cnt=0;
    while(n!=1)
    {
        if(n%2==1)n=3*n+1;
        else n=n/2;
        cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ans=getAns(n);
        printf("%d\n",ans);
    }
    return 0;
}
