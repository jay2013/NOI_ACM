#include<stdio.h>
#define SIZE 110
int n,A[SIZE][SIZE],Q,a,b;
void init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(k!=i&&k!=j&&A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                    A[j][i]=A[i][k]+A[k][j];
                }
            }
        }
    }
}
void work()
{
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",A[a][b]);
    }
}

int main()
{
    init();
    work();
    return 0;
}
