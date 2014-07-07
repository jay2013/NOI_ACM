#include<stdio.h>
int main()
{
    int n,MIN,MAX,i,tmp;
    scanf("%d",&n);
    scanf("%d",&tmp);
    MIN=tmp;
    MAX=tmp;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&tmp);
        if(tmp<MIN)MIN=tmp;
        if(tmp>MAX)MAX=tmp;
    }
    printf("%d %d\n",MIN,MAX);
    return 0;
}
