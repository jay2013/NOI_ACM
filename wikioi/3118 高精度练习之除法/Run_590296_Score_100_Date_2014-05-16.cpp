#include<stdio.h>
#include<string.h>

int lenA,lenB,i,j;
int A[1024],B[1024],ans[1024];

void init()
{
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(ans,0,sizeof(ans));
    char str_A[1024],str_B[1024];
    scanf("%s %s",str_A,str_B);
    lenA=strlen(str_A);
    lenB=strlen(str_B);
    for(i=lenA-1;i>=0;i--)A[lenA-1-i]=str_A[i]-'0';
    for(i=lenB-1;i>=0;i--)B[lenB-1-i]=str_B[i]-'0';
}
int isBigger(int pos)
{
    for(i=pos;i>=0;i--)
    {
        if(A[i]>B[i])return 1;
        if(A[i]<B[i])return 0;
    }
    return 1;
}

int main()
{
    init();
    if(lenA<lenB)printf("0\n");
    else if(isBigger(lenA-1)==0)printf("0\n");
    else
    {
        int tmp=lenA-lenB;
        for(i=lenB-1;i>=0;i--)B[i+tmp]=B[i];
        for(i=tmp-1;i>=0;i--)B[i]=0;
        while(1)
        {
            while(isBigger(lenA-1))
            {
                ans[tmp]++;
                for(i=0;i<lenA;i++)
                {
                    if(A[i]>=B[i])A[i]-=B[i];
                    else
                    {
                        A[i+1]--;
                        A[i]=A[i]+10-B[i];
                    }
                }
            }
            tmp--;
            if(tmp<0)break;
            for(i=0;i<lenA;i++)B[i]=B[i+1];
        }
        int pos=0;
        for(i=lenA-lenB;i>=0;i--)if(ans[i]!=0){pos=i;break;}
        for(i=pos;i>=0;i--)
            printf("%d",ans[i]);
        printf("\n");
    }
    return  0;
}
