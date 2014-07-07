#include<stdio.h>
#include<algorithm>
using namespace std;
struct NODE
{
    unsigned long long a,b,c;
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
        scanf("%llu %llu",&A[i].a,&A[i].b);
        A[i].c=A[i].a*A[i].b;
    }
    sort(A+1,A+n+1,cmp);
    unsigned long long MAX = 0l;
    unsigned long long S=A[0].a;
    for(i=1;i<=n;i++)
    {
        if(S/A[i].b>MAX)MAX=S/A[i].b;
        S=S*A[i].a;
    }
    printf("%llu\n",MAX);
    return 0;
}
