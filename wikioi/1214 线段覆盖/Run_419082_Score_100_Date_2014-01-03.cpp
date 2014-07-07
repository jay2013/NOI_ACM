#include<cstdio>
#include<algorithm>
using namespace std;
struct LINE
{
    int a,b;
    void swap()
    {
        if(a>b)
        {
            int tmp=a;
            a=b;
            b=tmp;
        }
    }
}line[110];
int cmp(LINE l1,LINE l2)
{
    return l1.b<l2.b;
}
int N,i,ans,now;

int main()
{
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&line[i].a,&line[i].b);
        line[i].swap();
    }
    sort(line,line+N,cmp);
    now=0;
    ans=0;
    for(i=1;i<N;i++)
    {
        if(line[i].a<line[now].b)ans++;
        else now=i;
    }
    printf("%d\n",N-ans);
    return 0;
}
