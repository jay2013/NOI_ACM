#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n,ans,visit[14],Fill[14];
void dfs(int pos)
{
    if(pos>n)
    {
        ans++;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!visit[i])
            {
                int flag=1;
                for(int j=1;j<pos;j++)
                {
                    if(abs(pos-j)==abs(i-Fill[j]))flag=0;
                }
                if(flag)
                {
                    visit[i]=1;
                    Fill[pos]=i;
                    dfs(pos+1);
                    visit[i]=0;

                }
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<14;i++)visit[i]=0;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
