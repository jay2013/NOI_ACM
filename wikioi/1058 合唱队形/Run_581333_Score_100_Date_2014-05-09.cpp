#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N,A[120],inc[120],dec[120],i,j;
    cin>>N;
    for(i=1;i<=N;i++)cin>>A[i];
    for(i=1;i<=N;i++)
    {
        inc[i]=1;
        for(j=1;j<i;j++)
        {
            if(A[i]>A[j])inc[i]=max(inc[i],inc[j]+1);
        }
    }
    for(i=N;i>=1;i--)
    {
        dec[i]=1;
        for(j=i+1;j<=N;j++)
        {
            if(A[i]>A[j])dec[i]=max(dec[i],dec[j]+1);
        }
    }
    int ans=0;
    for(i=1;i<=N;i++)ans=max(ans,inc[i]+dec[i]-1);
    cout<<N-ans<<endl;
    return 0;
}
