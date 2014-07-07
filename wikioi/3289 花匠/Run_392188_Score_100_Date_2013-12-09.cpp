#include<stdio.h>
int main()
{
    int n,a[100010],i,j,flg,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    ans=1;
    flg=-1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
        {
            if(flg!=1)
            {
                ans++;
                flg=1;
            }
        }
        if(a[i]<a[i-1])
        {
            if(flg!=0)
            {
                ans++;
                flg=0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
