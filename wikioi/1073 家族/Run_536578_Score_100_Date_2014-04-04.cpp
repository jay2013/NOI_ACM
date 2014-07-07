#include<stdio.h>
int n,m,p,x,y,root[5050];
void init()
{
    for(int i=1;i<=n;i++)root[i]=i;
}
int Find(int x)
{
    if(root[x]!=x)
        root[x]=Find(root[x]);
    return root[x];
}
void Union(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fx!=fy)root[fx]=fy;
}

int main()
{
    scanf("%d %d %d",&n,&m,&p);
    init();
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        Union(x,y);
    }
    for(int i=1;i<=p;i++)
    {
        scanf("%d %d",&x,&y);
        if(Find(x)==Find(y))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
