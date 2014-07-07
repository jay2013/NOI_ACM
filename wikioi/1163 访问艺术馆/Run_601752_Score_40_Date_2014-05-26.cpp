#include<cstdio>
#include<algorithm>
#define SIZE 102
#define T 650
using namespace std;
struct node
{
    int left,right,value,cost;
}tree[SIZE];
struct data
{
    int t,v;
}buf[SIZE];
int n,m,dp[SIZE][T],Time;
void init()
{
    scanf("%d",&Time);
    n=1,m=1;
    while(scanf("%d %d",&buf[n].t,&buf[n].v)!=EOF)n++;
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<T;j++)
            dp[i][j]=-1;//no value now.
}
void buildTree(int &x)
{
    int root=x;
    tree[root].cost=2*buf[x].t;
    tree[root].value=buf[x].v;
    if(buf[x].v){
        tree[root].left=tree[root].right=-1;//means it has no child.
        return;
    }
    tree[root].left= x+1;
    buildTree(++x);
    tree[root].right=x+1;
    buildTree(++x);
}

void dfs(int root,int time)
{
    if(time==0)dp[root][time]=0;
    else if(tree[root].left==-1)
    {
        int cnt;
        if(tree[root].value*5<=time-tree[root].cost)cnt=tree[root].value;
        else cnt=(time-tree[root].cost)/5;
        dp[root][time]=cnt;
    }
    else
    {
        dp[root][time]=0;
        int remain=time-tree[root].cost;
        for(int i=0;i<=remain;i++)
        {
            int tleft=tree[root].left,tright=tree[root].right;
            dfs(tleft,i);
            dfs(tright,remain-i);
            dp[root][time]=max(dp[root][time],dp[tleft][i]+dp[tright][remain-i]);
        }
    }
}
int main()
{
    init();
    buildTree(m);
    dfs(1,Time);
    printf("%d",dp[1][Time]);
    return 0;
}
