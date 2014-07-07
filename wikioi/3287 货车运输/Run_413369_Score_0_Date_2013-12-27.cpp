#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10010
#define MAXM 50010
#define MAXD 22
#define inf 200000
using namespace std;
int father[MAXN],n,m,q;
int visit[MAXN];
int f[MAXN][MAXD],g[MAXN][MAXD],h[MAXN];
struct saver
{
    int s,t,d;
} e[MAXM];

int cmp(saver a,saver b)
{
    return a.d>b.d;
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
    visit[v]=1;
    for(edge *p=head[v]; p; p=p->next)
    {
        if(!visit[p->t])
        {
            f[p->t][0]=v;
            g[p->t][0]=p->d;
            h[p->t]=h[v]+1;
            BuildTree(p->t);
        }
    }
}
//使两节点分支高度持平
int Move(int &v,int H)
{
    int ans = inf;
    for(int i=MAXD-1; i>=0; i--)
    {
        if(h[f[v][i]]>=H)
        {
            ans=min(ans,g[v][i]);
            v=f[v][i];
        }
    }
    return ans;
}
//处理询问u和v路径上最小值，倍增法处理
int Query(int u,int v)
{
    if(Find(u)!=Find(v))return -1;
    int ans = inf;
    if(h[u]!=h[v])ans=h[u]>h[v]?Move(u,h[v]):Move(v,h[u]);
    if(u==v) return ans;
    for(int i=MAXD-1; i>=0; i--)
    {
        if(f[u][i]!=f[v][i])
        {
            ans=min(ans,min(g[u][i],g[v][i]));
            u=f[u][i];
            v=f[v][i];
        }
    }
    ans=min(ans,min(g[u][0],g[v][0]));
    return ans;
}
int main()
{
    //处理输入
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
    memset(visit,0,sizeof(visit));
    memset(head,0,sizeof(head));
    memset(f,0,sizeof(f));
    for(int i=1; i<=n; i++)
    {
        if(!visit[i])
        {
            h[i]=0;
            BuildTree(i);
            g[i][0]=inf;
            f[i][0]=i;
        }
    }
    //预处理出up[i][j]和Min[i][j]数组
    for(int i=1; i<MAXD; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
            g[j][i]=min(g[j][i-1],g[f[j][i-1]][i-1]);
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
