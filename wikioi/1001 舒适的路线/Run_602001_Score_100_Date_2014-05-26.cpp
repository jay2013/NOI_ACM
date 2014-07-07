#include<cstdio>
#include<algorithm>
using namespace std;

int N,M,s,t,f[550];
struct NODE
{
    int x;
    int y,v;
} node[5050];
bool cmp(NODE nd1,NODE nd2)
{
    return nd1.v>nd2.v;
}
int gcd(int a,int b)
{
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
void init()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=M; i++)scanf("%d %d %d",&node[i].x,&node[i].y,&node[i].v);
    scanf("%d %d",&s,&t);
    sort(node+1,node+M+1,cmp);
}
int Find(int x)
{
    if(f[x]!=x)f[x]=Find(f[x]);
    return f[x];
}

void work()
{
    int isPossible=0;
    int MAX=2000000,MIN=1;
    for(int i=1;i<=M;i++)
    {
        int j;
        for(j=1; j<=N; j++)f[j]=j;
        for(j=i; j<=M; j++)
        {
            int sa=Find(node[j].x);
            int sb=Find(node[j].y);
            if(sa!=sb)f[sa]=sb;
            if(Find(s)==Find(t))break;
        }
        if(j<=M)
        {
            isPossible=1;
            if((double)node[i].v/node[j].v<(double)MAX/MIN)
            {
                MAX=node[i].v;
                MIN=node[j].v;
            }
        }
    }
    if(isPossible)
    {
        if(MAX%MIN==0)printf("%d\n",MAX/MIN);
        else printf("%d/%d\n",MAX/gcd(MAX,MIN),MIN/gcd(MAX,MIN));
    }
    else printf("IMPOSSIBLE\n");
}
int main()
{
    init();
    work();
    return 0;
}
