#include<cstdio>
#include<cstring>
#define SIZE 520
using namespace std;
int A[SIZE],B[SIZE],C[2*SIZE],i,len,j;
char str[SIZE];
int main()
{
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)A[len-1-i]=str[i]-'0';
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)B[len-1-i]=str[i]-'0';
    int flag=1;
    for(i=SIZE-1;i>=0;i--)
    {
        if(A[i]!=B[i])
        {
            if(A[i]>B[i])flag=1;
            else flag=-1;
            break;
        }
    }
    if(flag==1)
    {
        //结果是正的
        for(i=0;i<SIZE;i++)
        {
            if(A[i]>=B[i])
            {
                C[i]=A[i]-B[i];
            }
            else
            {
                A[i+1]--;
                C[i]=A[i]+10-B[i];
            }
        }
    }
    else
    {
        //结果是负的
        for(i=0;i<SIZE;i++)
        {
            if(B[i]>=A[i])
            {
                C[i]=B[i]-A[i];
            }
            else
            {
                B[i+1]--;
                C[i]=B[i]+10-A[i];
            }
        }
    }

    for(i=SIZE-1;i>0;i--)if(C[i]!=0)break;
    if(flag==-1)printf("-");
    for(j=i;j>=0;j--)printf("%d",C[j]);
    printf("\n");
    return 0;
}
