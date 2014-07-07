#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10010
#define MAXM 50010
#define MAXD 22
#define inf 200000
using namespace std;
int father[MAXN],n,m,q;
bool f[MAXN];
int up[MAXN][MAXD],Min[MAXN][MAXD],h[MAXN];
struct saver
{
    int s,t,d;
} e[MAXM];

int cmp(saver a,saver b)
{
    return a.d>b.d;
}
int min(int a,int b)
{
    return a<b?a:b;
}
//并查集
void init()
{
    for(int i=0; i<MAXN; i++)father[i]=i;
}
int Find(int x)
{
    if(x==father[x])return father[x];
    else
    {
        father[x]=Find(father[x]);
        return father[x];
    }
}
void Union(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        father[fx]=fy;
    }
}
//处理最大生成树后的边的关系
struct edge
{
    edge *next;
    int t,d;
    edge()
    {
        next=NULL;
    }
}*head[MAXN];
void Add(int s,int t,int d)
{
    edge *p=new(edge);
    p->t=t,p->d=d,p->next=head[s];
    head[s]=p;
}
void AddEdge(int s,int t,int d)
{
    Add(s,t,d);
    Add(t,s,d);
}
//一个dfs过程，对于和v在一棵树上的所有结点计算其在树中的高度以及up[i][0]和Min[i][0]
void BuildTree(int v)
{
    f[v]=false;
    for(edge *p=head[v]; p; p=p->next)
    {
        if(f[p->t])
        {
            up[p->t][0]=v;
            Min[p->t][0]=p->d;
            h[p->t]=h[v]+1;
            BuildTree(p->t);
        }
    }
}
//处理询问u和v路径上最小值

int Query(int u,int v)
{
    if(Find(u)!=Find(v))return -1;
    int rec = inf;
    for(int i=MAXD-1; i>=0; i--)
    {
        if(up[u][i]!=up[v][i])
        {
            rec=min(rec,min(Min[u][i],Min[v][i]));
            u=up[u][i];
            v=up[v][i];
        }
    }
    rec=min(rec,min(Min[u][0],Min[v][0]));
    return rec;
}
int main()
{
    //输入
    memset(head,0,sizeof(head));
    memset(up,0,sizeof(up));
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)scanf("%d %d %d",&e[i].s,&e[i].t,&e[i].d);
    //排序后生产最大生成树构成的森林
    sort(e,e+m,cmp);
    init();
    for(int i=0; i<m; i++)
    {
        if(Find(e[i].s)!=Find(e[i].t))
        {
            Union(e[i].s,e[i].t);
            AddEdge(e[i].s,e[i].t,e[i].d);
        }
    }
    //初始化每一个结点的up[i][0]和Min[i][0],并计算结点在树中高度
    memset(f,true,sizeof(f));
    for(int i=1; i<=n; i++)
    {
        if(f[i])
        {
            h[i]=0;
            BuildTree(i);
            Min[i][0]=inf;
            up[i][0]=i;
        }
    }
    //预处理出up[i][j]和Min[i][j]数组
    for(int i=1; i<MAXD; i++)
    {
        for(int j=1; j<=n; j++)
        {
            up[j][i]=up[up[j][i-1]][i-1];
            Min[j][i]=min(Min[j][i-1],Min[up[j][i-1]][i-1]);
        }
    }
    //处理询问
    scanf("%d",&q);
    while(q--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        printf("%d\n",Query(u,v));
    }
    return 0;
}
