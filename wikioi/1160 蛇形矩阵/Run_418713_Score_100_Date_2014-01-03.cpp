#include<cstdio>
#include<algorithm>
#define SIZE 110
using namespace std;
int n,MAP[SIZE][SIZE],cnt,mpx,mpy,ans;
void build(int lev)
{
    int i,j=mpy+lev;
    for(i=mpx+lev-1;i>mpx-lev;i--)
        MAP[i][j]=++cnt;
    i=mpx-lev;
    for(j=mpy+lev;j>mpy-lev;j--)
        MAP[i][j]=++cnt;
    j=mpy-lev;
    for(i=mpx-lev;i<mpx+lev;i++)
        MAP[i][j]=++cnt;
    i=mpx+lev;
    for(j=mpy-lev;j<=mpy+lev;j++)
        MAP[i][j]=++cnt;
}
void buildMap()
{
    scanf("%d",&n);
    mpx=n/2+1;
    mpy=n/2+1;
    cnt=0;
    MAP[mpx][mpy]=++cnt;
    for(int i=1;i<=(n-mpx);i++)
        build(i);
}
int main()
{
    ans=0;
    buildMap();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",MAP[i][j]);
            if(abs(i-mpx)==abs(j-mpy))ans+=MAP[i][j];
        }
        printf("\n");
    }
    printf("%d\n",ans);
    return 0;
}
