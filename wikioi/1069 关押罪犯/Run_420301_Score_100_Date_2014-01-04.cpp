#include<cstdio>
#include<algorithm>
#define SIZE 102400
using namespace std;
int N,M,father[40100];
struct NODE
{
    int a,b,c;
}node[SIZE];
int cmp(NODE node1,NODE node2)
{
    return node1.c>node2.c;
}
int Find(int x)
{
    if(father[x]!=x)
    {
        father[x]=Find(father[x]);
    }
    return father[x];
}
void Union(int x,int y)
{
    int rx=Find(x);
    int ry=Find(y);
    if(rx!=ry)father[rx]=ry;
}
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<=2*N;i++)father[i]=i;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d %d",&node[i].a,&node[i].b,&node[i].c);
    }
    sort(node,node+M,cmp);
    int flag=0;
    for(int i=0;i<M;i++)
    {
        int rx=Find(node[i].a);
        int ry=Find(node[i].b);
        if(rx==ry)
        {
            flag=i;
            break;
        }
        else
        {
            Union(rx,node[i].b+N);
            Union(ry,node[i].a+N);
        }
    }
    if(flag==0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",node[flag].c);
    }
    return 0;
}
