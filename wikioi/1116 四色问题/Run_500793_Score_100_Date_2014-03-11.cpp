#include<stdio.h>
int n,a[10][10],Fill[10],cnt;
void dfs(int pos)
{
    if(pos>n)cnt++;
    else
    {
        for(int i=1;i<=4;i++)
        {
            int flag=1;
            for(int j=0;j<pos;j++)
                if(i==Fill[j]&&a[pos][j]==1)flag=0;
            if(flag==1)
            {
                Fill[pos]=i;
                dfs(pos+1);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    printf("%d\n",cnt);
    return 0;
}
