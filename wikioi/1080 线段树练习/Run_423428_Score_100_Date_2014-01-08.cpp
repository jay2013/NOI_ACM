#include<cstdio>
#define SIZE 102400
using namespace std;
struct SEGMENT
{
    int l,r,val;
}segment[4*SIZE];
void BuildTree(int index,int l,int r)
{
    segment[index].l=l;
    segment[index].r=r;
    segment[index].val=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        BuildTree(2*index,l,mid);
        BuildTree(2*index+1,mid+1,r);
    }
}
void update(int index,int pos,int val)
{
    int l=segment[index].l;
    int r=segment[index].r;
    if(l<=pos&&pos<=r)
    {
        segment[index].val+=val;
    }
    if(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)update(2*index,pos,val);
        else update(2*index+1,pos,val);
    }
}
int getSum(int index,int l,int r)
{
    if(segment[index].l==l&&segment[index].r==r)return segment[index].val;
    else
    {
        int mid=(segment[index].l+segment[index].r)/2;
        if(r<=mid)return getSum(2*index,l,r);
        else if(l>mid) return getSum(2*index+1,l,r);
        else return getSum(2*index,l,mid)+getSum(2*index+1,mid+1,r);
    }
}
int main()
{
    int N,M,val,l,r,flag;
    scanf("%d",&N);
    BuildTree(1,1,N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&val);
        update(1,i,val);
    }
    scanf("%d",&M);
    for(int i=1;i<=M;i++)
    {
        scanf("%d %d %d",&flag,&l,&r);
        if(flag==1)
        {
            update(1,l,r);
        }
        else
        {
            printf("%d\n",getSum(1,l,r));
        }
    }
    return 0;
}
