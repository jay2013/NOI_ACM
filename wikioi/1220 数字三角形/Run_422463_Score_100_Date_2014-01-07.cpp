#include<cstdio>
#include<algorithm>
using namespace std;
int N,i,j,A[110][110];
int main()
{
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        for(j=1;j<=i;j++)scanf("%d",&A[i][j]);
    for(i=2;i<=N;i++)
    {
        for(j=1;j<=i;j++)
        {
            A[i][j]+=max(A[i-1][j-1],A[i-1][j]);
        }
    }
    int ans=A[N][1];
    for(i=1;i<=N;i++)
    {
        if(A[N][i]>ans)ans=A[N][i];
    }
    printf("%d\n",ans);
    return 0;
}
