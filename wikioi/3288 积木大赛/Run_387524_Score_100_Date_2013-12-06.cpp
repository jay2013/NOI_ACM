#include<stdio.h>
#define MIN(x,y) (x>y?y:x)
int main()
{
    int A[100002],i,ans,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)scanf("%d",&A[i]);
    ans=A[1];
    for(i=2; i<=n; i++)
    {
        ans+=A[i];
        ans-=MIN(A[i],A[i-1]);
    }
    printf("%d\n",ans);
    return 0;
}
