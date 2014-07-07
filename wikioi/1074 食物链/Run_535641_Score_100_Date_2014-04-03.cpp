#include<stdio.h>
int N,K,D,X,Y;
int root[50500],R[50500],ans=0;
void init()
{
    for(int i=0;i<=N;i++)
    {
        root[i]=i;
        R[i]=0;
    }
}
int Find(int x)
{
    if(x==root[x])return x;
    else
    {
        int tmp = root[x];
        root[x]=Find(tmp);
        R[x]=(R[tmp]+R[x])%3;
        return root[x];
    }
}
void Union(int x,int y,int z)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy)
    {
        root[fy]=fx;
        R[fy]=(3+z+R[x]-R[y])%3;
    }
}
int main()
{
    scanf("%d %d",&N,&K);
    ans=0;
    init();
    while(K--)
    {
        scanf("%d %d %d",&D,&X,&Y);
        if(X>N||Y>N)ans++;
        else if(X==Y&&D==2)ans++;
        else
        {
            int FX=Find(X);
            int FY=Find(Y);
            if(FX!=FY)Union(X,Y,D-1);
            else if(D==1&&R[X]!=R[Y])ans++;
            else if(D==2&&(R[Y]-R[X]+3)%3!=1)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
