#include<stdio.h>
int N,K,D,X,Y,root[160000],ans;
void init()
{
     scanf("%d %d",&N,&K);
     for(int i=1;i<=3*N;i++)root[i]=i;
     ans=0;
}
int Find(int x)
{
    if(root[x]!=x)
        root[x]=Find(root[x]);
    return root[x];
}
void Union(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)root[fx]=fy;
}
void solve()
{
    while(K--)
    {
        scanf("%d %d %d",&D,&X,&Y);
        if(X>N||Y>N)ans++;
        else if(D==2&&X==Y)ans++;
        else
        {
            if(D==1)
            {
                if(Find(X)==Find(Y+N)||Find(X)==Find(Y+2*N))ans++;
                else
                {
                    Union(X,Y);
                    Union(X+N,Y+N);
                    Union(X+2*N,Y+2*N);
                }
            }
            else
            {
                if(Find(X)==Find(Y)||Find(X)==Find(Y+N))ans++;
                else
                {
                    Union(X,Y+2*N);
                    Union(X+N,Y);
                    Union(X+2*N,Y+N);
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    init();
    solve();
    return 0;
}
