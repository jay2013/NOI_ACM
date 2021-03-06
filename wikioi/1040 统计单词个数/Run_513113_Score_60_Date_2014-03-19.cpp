#include<stdio.h>
#include<string.h>
int n,p,k,s,len,i,j,pos,cnt,t;
char su[30],dic[8][40],str[300];
int dp[300][50],x[300][300];
int max(int a,int b)
{
    return a>b?a:b;
}
void init_x()
{
    memset(x,0,sizeof(x));
    for(i=len; i>0; i--)
    {
        for(j=i; j<=len; j++)
        {
            if(j<i)break;
            cnt=0;
            for(t=0; t<s; t++)
            {
                int tmplen = strlen(dic[t]);
                if(tmplen>(j-i+1))break;
                else
                {
                    int flag = 1;
                    for(int tt=0; tt<tmplen; tt++)
                    {
                        if(dic[t][tt]!=str[i+tt-1])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag==1)cnt++;
                }
            }
            x[i][j]=x[i+1][j]+cnt;
        }
    }
}

void init_dp()
{
    memset(dp,0,sizeof(dp));
    for(i=1; i<=len; i++)
    {
        for(j=1; j<=k; j++)
        {
            dp[i][j]=0;
            for(t=0; t<i; t++)
                dp[i][j]=max(dp[i][j],dp[t][j-1]+x[t+1][i]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&p,&k);
        pos=0;
        for(i=0; i<p; i++)
        {
            scanf("%s",su);
            for(j=0; j<20; j++)
            {
                str[pos++]=su[j];
            }
        }
        str[pos]='\0';
        len = 20*p;
        scanf("%d",&s);
        for(i=0; i<s; i++)scanf("%s",dic[i]);
        init_x();
        init_dp();
        printf("%d\n",dp[len][k]);
    }
    return 0;
}
