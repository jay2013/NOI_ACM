#include<stdio.h>
#include<algorithm>
#define SIZE 1000
using namespace std;
struct NODE
{
    int a,b,c;
}A[1010];
int cmp(const NODE a,const NODE b)
{
    return a.c<b.c;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d %d",&A[i].a,&A[i].b);
        A[i].c=A[i].a*A[i].b;
    }
    sort(A+1,A+n+1,cmp);
    int MAX[SIZE] = {0};
    int S[SIZE],pos=0;
    while(A[0].a>0)
    {
        S[pos++]=A[0].a%10;
        A[0].a/=10;
    }
    S[pos]=0;
    for(i=1;i<=n;i++)
    {
        int tmpAns[SIZE]={0},cnt=0;
        unsigned long long tmpVal=0l;
        for(j=pos-1;j>=0;j--)
        {
            tmpVal=tmpVal*10l + S[j];
            tmpAns[cnt++]=tmpVal/A[i].b;
            //tmpAns=tmpAns*10+tmpVal/A[i].b;
            tmpVal%=A[i].b;
        }

        int tmpAns2[SIZE]={0};
        for(j=cnt-1;j>=0;j--)
        {
            tmpAns2[cnt-1-j]=tmpAns[j];
        }

        //for(j=cnt-1;j>=0;j--)printf("%d",tmpAns2[j]);
        //printf("\n");

        int flag=1;
        for(j=SIZE-1;j>=0;j--)
        {
            if(tmpAns2[j]>MAX[j])break;
            else if(tmpAns2[j]<MAX[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            for(j=SIZE-1;j>=0;j--)
            {
                MAX[j]=tmpAns2[j];
            }
        }
         //for(j=SIZE-1;j>=0;j--)printf("%d",MAX[j]);
         //printf("\n");
        //if(tmpAns>MAX)MAX=tmpAns;
        for(j=0;j<pos;j++)
        {
            S[j]=S[j]*A[i].a;
        }
        for(j=0;j<pos;j++)
        {
            S[j+1]+=S[j]/10;
            S[j]%=10;
        }
        while(S[pos]>0)
        {
            S[pos+1]=S[pos]/10;
            S[pos]=S[pos]%10;
            pos++;
        }
    }
    for(i=SIZE-1;i>=1;i--)if(MAX[i]!=0)break;
    for(j=i;j>=0;j--)
        printf("%d",MAX[j]);
    printf("\n");
    return 0;
}
