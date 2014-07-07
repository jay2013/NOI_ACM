#include<cstdio>
#include<algorithm>
using namespace std;
struct LINE
{
    int a,b,c;
    void input()
    {
        scanf("%d %d %d",&a,&b,&c);
    }
    void output()
    {
        printf("%d %d %d\n",a,b,c);
    }
}line[1024];
int cmp(LINE l1,LINE l2)
{
    return l1.b<l2.b;
}
int n,i,j,dp[1024];
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)line[i].input();
    sort(line,line+n,cmp);
    //for(i=0;i<n;i++)line[i].output();
    dp[0]=line[0].c;
    for(i=1;i<n;i++)
    {
        int MAX=0;
        for(j=0;j<i;j++)
        {
            if(line[j].b<=line[i].a)
            {
                MAX=max(MAX,dp[j]);
            }
        }
        dp[i]=MAX+line[i].c;
    }
    int MAX=0;
    for(i=0;i<n;i++)MAX=max(MAX,dp[i]);
    printf("%d\n",MAX);
    return 0;
}
