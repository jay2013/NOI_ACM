#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,heap[1024],A[1024],B[1024],i,j;
struct NODE
{
    int t,v;
}node[1024];
int cmp(NODE x,NODE y)
{
    return x.t>y.t;
}
int main()
{
    priority_queue<int>qu;
    scanf("%d",&n);
    int MAX=-1;
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    for(i=0;i<n;i++)scanf("%d",&B[i]);
    for(i=0;i<n;i++)
    {
        node[i].t=A[i];
        node[i].v=B[i];
        if(A[i]>MAX)MAX=A[i];
    }
    sort(node,node+n,cmp);
    while(!qu.empty())qu.pop();
    int ans=0,pos=0;
    for(i=MAX;i>0;i--)
    {
        for(j=pos;node[j].t>=i;j++)
        {
            qu.push(node[j].v);
        }
        if(!qu.empty())
        {
            ans+=qu.top();
            qu.pop();
        }
        pos=j;
    }
    printf("%d\n",ans);
    return 0;
}
