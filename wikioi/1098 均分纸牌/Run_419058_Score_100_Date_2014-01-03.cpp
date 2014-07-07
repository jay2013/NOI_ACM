#include<cstdio>
using namespace std;
int main()
{
    int N,i,A[110],ans=0,ave=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)scanf("%d",&A[i]),ave+=A[i];
    ave/=N;
    for(i=0;i<N-1;i++)
    {
        if(A[i]!=ave)
        {
            ans++;
            A[i+1]+=(A[i]-ave);
        }
    }
    printf("%d\n",ans);
    return 0;
}
