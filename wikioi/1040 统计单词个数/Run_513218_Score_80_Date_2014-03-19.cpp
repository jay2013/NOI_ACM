#include<stdio.h>
#include<string.h>
int n,p,k,s,len,i,j,pos,cnt,t;
char su[100],dic[8][300],str[300];
int dp[300][50],x[300][300];
int max(int a,int b)
{
    return a>b?a:b;
}
void init_x()
{
    memset(x,0,sizeof(x));
    x[len][len]=0;
    for(t=0;t<s;t++)
    {
        if(strlen(dic[t])==1&&dic[t][0]==str[len-1])x[len][len]++;
    }
    for(i=len-1; i>0; i--)
    {
        for(j=i; j<=len; j++)
        {
            if(j<i)break;
            cnt=0;
            for(t=0; t<s; t++)
            {
                int tmplen = strlen(dic[t]);
                if(tmplen>(j-i+1))continue;
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
            x[i][j]=x[i+1][j]+(cnt>0?1:0);
        }
    }  
}

void init_dp()
{
    memset(dp,0,sizeof(dp));
    for(i=1;i<=len;i++)dp[i][1]=x[1][i];
    for(i=1; i<=len; i++)
    {
        for(j=2; j<=k; j++)
        {
            if(j>i)
            {
                dp[i][j]=0;
                break;
            }
            else if(j==i)
            {
                dp[i][j]=0;
                for(t=1;t<=i;t++)dp[i][j]+=x[t][t];
            }
            else
            {
                dp[i][j]=0;
                for(t=1; t<i; t++)
                    dp[i][j]=max(dp[i][j],dp[t][j-1]+x[t+1][i]);
            }
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
