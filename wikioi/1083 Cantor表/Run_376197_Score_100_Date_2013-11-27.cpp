#include<stdio.h>
int main()
{
    int N,SUM=0,i=1;
    scanf("%d",&N);
    while(SUM+i<N)
    {
        SUM+=i;
        i++;
    }
    N=N-SUM;
    if(i%2==0)
    {
        printf("%d/%d\n",N,i+1-N);
    }
    else
    {
        printf("%d/%d\n",i+1-N,N);
    }
    return 0;
}
