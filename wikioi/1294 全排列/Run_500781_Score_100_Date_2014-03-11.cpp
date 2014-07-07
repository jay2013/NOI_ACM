#include<iostream>
#include<stdio.h>
using namespace std;
int visit[11],n,Fill[11];
void print()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",Fill[i]);
    }
    printf("\n");
}
void dfs(int pos)
{
    if(pos>n)
    {
        print();
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!visit[i])
            {
                visit[i]=1;
                Fill[pos]=i;
                dfs(pos+1);
                visit[i]=0;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<11;i++)visit[i]=0;
    dfs(1);
    return 0;
}