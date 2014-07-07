#include<stdio.h>
int a[100010],n,i;
int getAns(int l,int r)
{
    if(l>r)return 0;
    int MIN=10010,pos=-1;
    for(i=l;i<=r;i++)
    {
        if(a[i]<MIN)
        {
            MIN=a[i];
            pos=i;
        }
    }
    for(i=l;i<=r;i++)a[i]-=MIN;
    return MIN+getAns(l,pos-1)+getAns(pos+1,r);
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("%d\n",getAns(1,n));
    return 0;
}
