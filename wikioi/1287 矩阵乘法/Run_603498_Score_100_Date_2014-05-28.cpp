#include<cstdio>
#define SIZE 210
using namespace std;
struct MATRIX
{
    int r,c,data[SIZE][SIZE];
    void input()
    {
        scanf("%d %d",&r,&c);
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                scanf("%d",&data[i][j]);
    }
    void output()
    {
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
                printf("%d ",data[i][j]);
            printf("\n");
        }
    }
}A,B,C;
int main()
{
    A.input();
    B.input();
    for(int i=1;i<=A.r;i++)
    {
        for(int j=1;j<=B.c;j++)
        {
            C.data[i][j]=0;
            for(int k=1;k<=A.c;k++)
                C.data[i][j]+=A.data[i][k]*B.data[k][j];
        }
    }
    C.r=A.r;
    C.c=B.c;
    C.output();
    return 0;
}
