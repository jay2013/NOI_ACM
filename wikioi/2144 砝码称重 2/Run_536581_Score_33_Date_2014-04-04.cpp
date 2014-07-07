#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m,len1,len2,w[40],sum,cnt;
struct NODE
{
    int num,val;
} A[35000],B[3500];
void dfs1(int pos)
{   if(pos>n/2)
    {
        len1++;
        A[len1].num=cnt;
        A[len1].val=sum;
        return;
    }
    else
    {
        dfs1(pos+1);
        sum+=w[pos];
        cnt++;
        dfs1(pos+1);
        sum-=w[pos];
        cnt--;
    }
}
void dfs2(int pos)
{   if(pos>n)
    {
        len2++;
        B[len2].num=cnt;
        B[len2].val=sum;
        return;
    }
    else
    {
        dfs2(pos+1);
        sum+=w[pos];
        cnt++;
        dfs2(pos+1);
        sum-=w[pos];
        cnt--;
    }
}
int cmp(NODE node1,NODE node2)
{
    return node1.val<node2.val;
}
int binary_search(int val,int l,int r)
{
    if(l>r)return -1;
    int mid = (l+r)/2;
    if(B[mid].val==val)return B[mid].num;
    else if(val<B[mid].val) return binary_search(val,l,mid-1);
    else return binary_search(val,mid+1,r);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int j=1; j<=n; j++)scanf("%d",&w[j]);
    len1=sum=cnt=0;
    dfs1(1);
    sort(A+1,A+len1+1,cmp);
    len2=sum=cnt=0;
    dfs2(n/2+1);
    sort(B+1,B+len2+1,cmp);
    int ans=n;
    for(int i=1;i<=len1;i++)
    {
        int tmp=binary_search(m-A[i].val,1,len2);
        if(tmp!=-1&&ans>A[i].num+tmp)
        {
            ans = A[i].num+tmp;
        }
    }
    printf("%d\n",ans);
    return 0;
}
