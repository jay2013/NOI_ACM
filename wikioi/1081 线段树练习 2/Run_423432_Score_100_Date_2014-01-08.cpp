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

void update(int index,int l,int r,int val)
{
    if(segment[index].l==l&&segment[index].r==r)
    {
        segment[index].val+=val;
    }
    else
    {
        int mid=(segment[index].l+segment[index].r)/2;
        if(r<=mid) update(2*index,l,r,val);
        else if(l>mid) update(2*index+1,l,r,val);
        else update(2*index,l,mid,val),update(2*index+1,mid+1,r,val);
    }
}
int query(int index,int pos)
{
    if(segment[index].l==pos&&segment[index].r==pos)return segment[index].val;
    else
    {
        int mid=(segment[index].l+segment[index].r)/2;
        if(pos<=mid)return segment[index].val+query(2*index,pos);
        else return segment[index].val+query(2*index+1,pos);
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
        update(1,i,i,val);
    }
    scanf("%d",&M);
    for(int i=1;i<=M;i++)
    {
        scanf("%d",&flag);
        if(flag==1)
        {
            scanf("%d %d %d",&l,&r,&val);
            update(1,l,r,val);
        }
        else
        {
            scanf("%d",&l);
            printf("%d\n",query(1,l));
        }
    }
    return 0;
}
