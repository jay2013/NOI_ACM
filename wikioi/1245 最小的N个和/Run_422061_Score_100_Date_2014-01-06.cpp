#include<cstdio>
#include<algorithm>
#define SIZE 102400
using namespace std;
struct NODE
{
    int val,x,y;
}heap[SIZE];
int n,A[SIZE],B[SIZE];
void Adjust(int pos)
{
    int tmp=heap[pos].val;
    int chd=2*pos;
    if(chd<=n)
    {
        if(chd<n&&heap[chd].val>heap[chd+1].val)chd++;
        if(tmp>heap[chd].val)
        {
            NODE tmpNode;
            tmpNode.val=heap[chd].val;
            tmpNode.x=heap[chd].x;
            tmpNode.y=heap[chd].y;
            heap[chd].val=heap[pos].val;
            heap[chd].x=heap[pos].x;
            heap[chd].y=heap[pos].y;
            heap[pos].val=tmpNode.val;
            heap[pos].x=tmpNode.x;
            heap[pos].y=tmpNode.y;
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    for(int i=1;i<=n;i++)scanf("%d",&B[i]);
    sort(A+1,A+n+1);
    sort(B+1,B+n+1);
    for(int i=1;i<=n;i++)
    {
        heap[i].val=A[1]+B[i];
        heap[i].x=1;
        heap[i].y=i;
    }
    BuildHeap();
    for(int i=1;i<=n;i++)
    {
        printf("%d ",heap[1].val);
        heap[1].val=A[heap[1].x+1]+B[heap[1].y];
        heap[1].x++;
        Adjust(1);
    }
    printf("\n");
    return 0;
}
