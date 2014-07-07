#include<cstdio>
#include<algorithm>
using namespace std;
struct NODE
{
    int t,v;
}node[110];
int cmp(NODE x,NODE y)
{
    if(x.t<y.t)return 1;
    else if(x.t==y.t&&x.v>y.v)return 1;
    else return 0;
}
int n,A[110],B[110],i;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    for(i=0;i<n;i++)scanf("%d",&B[i]);
    for(i=0;i<n;i++){
        node[i].t=A[i];
        node[i].v=B[i];
    }
    sort(node,node+n,cmp);
    int ans=0,cnt=0;
    for(i=0;i<n;i++)
    {
        if(node[i].t>cnt)
        {
            ans+=node[i].v;
            cnt++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
