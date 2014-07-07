#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,a[102400],HASH[102400],i,P;
int Binary_Search(long long val,int l,int r)
{
    if(l==r)
    {
        if(a[l]==val)return l;
        else return -1;
    }
    else if(l>r)return -1;
    else
    {
        int mid=(l+r)/2;
        if(a[mid]==val)return mid;
        else if(a[mid]<val)return Binary_Search(val,mid+1,r);
        else return Binary_Search(val,l,mid-1);
    }
}
int main()
{
    while(scanf("%d %d",&N,&P)!=EOF)
    {
        for(i=0;i<N;i++)scanf("%d",&a[i]);
        sort(a,a+N);
        memset(HASH,0,sizeof(HASH));
        for(i=0;i<N;i++)
        {
            if(HASH[i])continue;
            int tmp=Binary_Search(a[i]*P,0,N-1);
            if(tmp!=-1)
            {
                HASH[tmp]=1;
            }
        }
        int ans=0;
        for(i=0;i<N;i++)
        {
            if(HASH[i]==0)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
