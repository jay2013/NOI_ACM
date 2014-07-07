#include<cstdio>
#include<algorithm>
#define SIZE 110
using namespace std;
struct NODE
{
    int x,y,val;
}edge[SIZE*SIZE];
int father[SIZE],N,i,j;
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
int cmp(NODE e1,NODE e2)
{
    return e1.val<e2.val;
}
int main()
{
    scanf("%d",&N);
    int cnt=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            scanf("%d",&edge[cnt].val);
            edge[cnt].x=i;
            edge[cnt].y=j;
            cnt++;
        }
    }
    sort(edge,edge+cnt,cmp);
    for(i=1;i<=N;i++)father[i]=i;
    int ans=0;
    for(i=0;i<cnt;i++)
    {
        if(Find(edge[i].x)!=Find(edge[i].y))
        {
            Union(edge[i].x,edge[i].y);
            ans+=edge[i].val;
        }
    }
    printf("%d\n",ans);
    return 0;
}
