#include<cstdio>
#include<cstring>
#define SIZE 520
using namespace std;
int A[SIZE],B[SIZE],i,len,j;
char str[SIZE];
int main()
{
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)A[len-1-i]=str[i]-'0';
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)B[len-1-i]=str[i]-'0';
    for(i=0;i<SIZE;i++)A[i]=A[i]+B[i];
    for(i=0;i<SIZE;i++)
    {
        if(A[i]>=10)
        {
            A[i+1]+=A[i]/10;
            A[i]%=10;
        }
    }
    for(i=SIZE-1;i>0;i--)if(A[i]!=0)break;
    for(j=i;j>=0;j--)printf("%d",A[j]);
    printf("\n");
    return 0;
}
