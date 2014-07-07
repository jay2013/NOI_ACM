#include<stdio.h>
#define SIZE 20
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
int n,root;
void buildTree()
{
    int l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&l,&r);
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
void PreorderTraversal(int root)
{
    printf("%d ",root);
    if(node[root].leftS!=0)
        PreorderTraversal(node[root].leftS);
    if(node[root].rightS!=0)
        PreorderTraversal(node[root].rightS);
}
void InorderTraversal(int root)
{
    if(node[root].leftS!=0)
        InorderTraversal(node[root].leftS);
    printf("%d ",root);
    if(node[root].rightS!=0)
        InorderTraversal(node[root].rightS);
}
void PostorderTraversal(int root)
{
    if(node[root].leftS!=0)
        PostorderTraversal(node[root].leftS);
    if(node[root].rightS!=0)
        PostorderTraversal(node[root].rightS);
    printf("%d ",root);
}
int main()
{
    buildTree();
    PreorderTraversal(root);
    printf("\n");
    InorderTraversal(root);
    printf("\n");
    PostorderTraversal(root);
    printf("\n");
    return 0;
}
