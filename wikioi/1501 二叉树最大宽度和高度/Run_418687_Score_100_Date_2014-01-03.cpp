#include<stdio.h>
#define SIZE 20
#include<algorithm>
using namespace std;
struct NODE
{
    int father,leftS,rightS;
    void init()
    {
        father=0;
        leftS=0;
        rightS=0;
    }
}node[SIZE];
int n,root,HIGHT[SIZE];
void buildTree()
{
    int l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&l,&r);
        HIGHT[i]=0;
        node[i].init();
        node[i].leftS=l;
        node[i].rightS=r;
        node[l].father=i;
        node[r].father=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(node[i].father==0){
            root=i;
            break;
        }
    }
}
int getHight(int root,int h)
{
    int ans=1,left=0,right=0;
    if(node[root].leftS!=0)
        left=getHight(node[root].leftS,h+1);
    if(node[root].rightS!=0)
        right=getHight(node[root].rightS,h+1);
    ans+=max(left,right);
    HIGHT[root]=h;
    return ans;
}
int main()
{
    buildTree();
    int hh=getHight(root,1);
    sort(HIGHT+1,HIGHT+1+n);
    int width=1,cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(HIGHT[i]==HIGHT[i-1])
        {
            cnt++;
        }
        else
        {
            if(cnt>width)width=cnt;
            cnt=1;
        }
    }
    if(cnt>width)width=cnt;
    printf("%d %d\n",width,hh);
    return 0;
}
