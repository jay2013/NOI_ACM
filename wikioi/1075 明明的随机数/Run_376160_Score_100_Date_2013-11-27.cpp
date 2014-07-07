#include<stdio.h>

int main()
{
    int N,M,a[110],b[1010],i,cnt=0;
    scanf("%d",&N);
    for(i=1;i<=N;i++)scanf("%d",&a[i]);
    for(i=0;i<1010;i++)b[i]=0;
    for(i=1;i<=N;i++)b[a[i]]=1;
    M=0;
    for(i=0;i<1010;i++)if(b[i]==1)M++;
    printf("%d\n",M);
    for(i=0;i<1010;i++)
    {
        if(b[i]==1)
        {
            cnt++;
            printf("%d%c",i,cnt==M?'\n':' ');
        }
    }
    return 0;
}
