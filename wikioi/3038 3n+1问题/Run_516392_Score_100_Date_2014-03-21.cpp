#include<cstdio>
#include<string.h>
using namespace std;
int T,n,cnt;
int visit[9000000];
int getAns(int n)
{
    cnt=0;
    memset(visit,0,sizeof(visit));
    while(n!=1)
    {

        if(n<9000000)
        {
            if(visit[n]==1)
            {
                cnt=-1;
                break;
            }
            else
                visit[n]=1;
        }
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
