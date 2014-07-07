#include<cstdio>
using namespace std;
int HASH[102400],n,m,i,tmp;
int main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        HASH[tmp]=1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&tmp);
        if(HASH[tmp])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
