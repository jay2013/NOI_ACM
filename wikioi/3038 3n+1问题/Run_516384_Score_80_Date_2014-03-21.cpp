#include<iostream>
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
    cin>>T;
    while(T--)
    {
        cin>>n;
        int ans=getAns(n);
        cout<<ans<<endl;
    }
    return 0;
}
