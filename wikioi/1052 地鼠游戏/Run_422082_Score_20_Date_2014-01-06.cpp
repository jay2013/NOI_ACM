#include<cstdio>
#include<algorithm>
#define SIZE 102400
using namespace std;
struct NODE
{
    int val,x;
}heap[SIZE];
int n,A[SIZE],B[SIZE];
void Adjust(int pos)
{
    int tmpVal=heap[pos].val;
    int tmpX=heap[pos].x;
    int chd=2*pos;
    if(chd<=n)
    {
        if(chd<n&&heap[chd].x>heap[chd+1].x)chd++;
        else if(chd<n&&heap[chd].x==heap[chd+1].x&&heap[chd].val<heap[chd+1].val)chd++;
        if(tmpX>heap[chd].x||(tmpX==heap[chd].x&&tmpVal<heap[chd].val))
        {
            NODE tmpNode;
            tmpNode.val=heap[chd].val;
            tmpNode.x=heap[chd].x;
            heap[chd].val=heap[pos].val;
            heap[chd].x=heap[pos].x;
            heap[pos].val=tmpNode.val;
            heap[pos].x=tmpNode.x;
            Adjust(chd);
        }
    }
}
void BuildHeap()
{
    for(int i=n/2;i>=1;i--)Adjust(i);
}
int main()
{
    int MAX=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    for(int i=1;i<=n;i++)scanf("%d",&B[i]);
    for(int i=1;i<=n;i++)
    {
        if(A[i]>MAX)MAX=A[i];
        heap[i].val=B[i];
        heap[i].x=A[i];
    }
    BuildHeap();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(heap[1].x<i)
        {
            heap[1].val=0;
            heap[1].x=2*MAX;
            Adjust(1);
        }
        ans+=heap[1].val;
        heap[1].val=-1;
        heap[1].x=2*MAX;
        Adjust(1);
    }
    printf("%d\n",ans);
    return 0;
}
