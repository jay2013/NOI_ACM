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
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d %d",&A[i].a,&A[i].b);
        A[i].c=A[i].a*A[i].b;
    }
    sort(A+1,A+n+1,cmp);
    long long MAX = 0l;
    int S[1000],pos=0;
    while(A[0].a>0)
    {
        S[pos++]=A[0].a%10;
        A[0].a/=10;
    }
    S[pos]=0;
    for(i=1;i<=n;i++)
    {
        long long tmpAns=0l,tmpVal=0l;
        for(j=pos-1;j>=0;j--)
        {
            tmpVal=tmpVal*10l + S[j];
            tmpAns=tmpAns*10l+tmpVal/A[i].b;
            tmpVal%=A[i].b;
        }
        if(tmpAns>MAX)MAX=tmpAns;
        for(j=0;j<pos;j++)
        {
            S[j]=S[j]*A[i].a;
        }
        for(j=0;j<pos;j++)
        {
            S[j+1]+=S[j]/10;
            S[j]%=10;
        }
        while(S[pos]>0)
        {
            S[pos+1]=S[pos]/10;
            S[pos]=S[pos]%10;
            pos++;
        }
    }
    printf("%lld\n",MAX);
    return 0;
}
