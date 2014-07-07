#include<cstdio>
#include<algorithm>
#define SIZE 102400
using namespace std;
struct EDGE
{
    int x,y,val;
}edge[SIZE];
int father[SIZE],N,i,j,M;
int Find(int x)
{
    if(x!=father[x])father[x]=Find(father[x]);
    return father[x];
}
void Union(int x,int y)
{
    int rx=Find(x);
    int ry=Find(y);
    if(rx!=ry)father[rx]=ry;
}
int cmp(EDGE e1,EDGE e2)
{
    return e1.val<e2.val;
}
int main()
{
    scanf("%d %d",&N,&M);
    int cnt=0;
    for(j=1;j<=M;j++)
    {
        scanf("%d %d %d",&edge[j].x,&edge[j].y,&edge[j].val);
    }
    sort(edge+1,edge+M+1,cmp);
    for(i=1;i<=N;i++)father[i]=i;
    long long ans=0L;
    for(i=1;i<=M;i++)
    {
        if(Find(edge[i].x)!=Find(edge[i].y))
        {
            Union(edge[i].x,edge[i].y);
            ans+=edge[i].val;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
