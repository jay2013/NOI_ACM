#include<stdio.h>
int main()
{
    int n,m,i,A[1000],pos=0;
    scanf("%d %d",&n,&m);
    while(n>0)
    {
        A[pos++]=n%m;
        n/=m;
    }
    if(pos==0)printf("0\n");
    else
    {
        for(i=pos-1;i>=0;i--)
        {
            if(A[i]>=10)
            {
                printf("%c",'A'+A[i]-10);
            }
            else
            {
                printf("%d",A[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
