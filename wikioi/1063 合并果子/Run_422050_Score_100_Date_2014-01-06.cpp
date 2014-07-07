#include<cstdio>
#define MAXVAL 400000048
int n,heap[10240];
void adjust(int pos)
{
    if(2*pos+1<=n)
    {
        int tmpPos;
        if(heap[2*pos]<heap[2*pos+1])
            tmpPos=2*pos;
        else
            tmpPos=2*pos+1;
        if(heap[pos]<heap[tmpPos])return;
        else
        {
            int tmp=heap[tmpPos];
            heap[tmpPos]=heap[pos];
            heap[pos]=tmp;
            adjust(tmpPos);
        }
    }
    else if(2*pos<=n)
    {
        if(heap[pos]<heap[2*pos])return;
        int tmp=heap[2*pos];
        heap[2*pos]=heap[pos];
        heap[pos]=tmp;
        adjust(2*pos);
    }
    else
    {
        return;
    }
}
void BuildHeap()
{
    for(int i=n/2;i>=1;i--)adjust(i);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&heap[i]);
    BuildHeap();
    int ans=0;
    for(int i=1;i<=n-1;i++)
    {
        int tmp1=heap[1];
        heap[1]=MAXVAL;
        adjust(1);
        int tmp2=heap[1];
        ans+=(tmp1+tmp2);
        heap[1]=tmp1+tmp2;
        adjust(1);
    }
    printf("%d\n",ans);
    return 0;
}
