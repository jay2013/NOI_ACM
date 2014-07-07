#include<stdio.h>
#include<algorithm>
using namespace std;
struct NODE
{
    int a,b,c;
}A[1010];
int cmp(const NODE a,const NODE b)
{
    return a.c<b.c;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d %d",&A[i].a,&A[i].b);
        A[i].c=A[i].a*A[i].b;
    }
    sort(A+1,A+n+1,cmp);
    int MAX = -1;
    unsigned long long S=A[0].a;
    for(i=1;i<=n;i++)
    {
        if(S/A[i].b>MAX)MAX=S/A[i].b;
        S=S*A[i].a;
    }
    printf("%d\n",MAX);
    return 0;
}
