#include<stdio.h>
#define SIZE 100000
int main()
{
    int n,a[SIZE],S[SIZE][2],i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    S[1][0]=1;
    S[1][1]=1;
    for(i=2;i<=n;i++)
    {
        int tmp1=-1,tmp2=-1;
        for(j=1;j<i;j++)
        {
            if(a[j]>a[i]&& S[j][0]>tmp1)
            {
                tmp1 = S[j][0];
            }
            if(a[j]<a[i]&&S[j][1]>tmp2)
            {
                tmp2=S[j][1];
            }
        }
        S[i][0]=tmp2+1;
        S[i][1]=tmp1+1;
    }
    printf("%d\n",S[n][1]>S[n][0]?S[n][1]:S[n][0]);
    return 0;
}
