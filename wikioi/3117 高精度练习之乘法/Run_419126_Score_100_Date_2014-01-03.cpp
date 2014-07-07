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
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            C[i+j]+=A[i]*B[j];
        }
    }
    for(i=0;i<2*SIZE;i++)
    {
        if(C[i]>=10)
        {
            C[i+1]+=C[i]/10;
            C[i]%=10;
        }
    }
    for(i=2*SIZE-1;i>0;i--)if(C[i]!=0)break;
    for(j=i;j>=0;j--)printf("%d",C[j]);
    printf("\n");
    return 0;
}
