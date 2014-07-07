#include<cstdio>
#include<cstring>
#define SIZE 1024
using namespace std;
struct BIGDATA
{
    int len,a[SIZE];
    void init()
    {
        len=1;
        for(int i=0; i<SIZE; i++)a[i]=0;
    }
    void print()
    {
        for(int i=len-1; i>=0; i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    int getLen()
    {
        for(int i=SIZE-1;i>=0;i--)if(a[i]!=0)return i+1;
        return 1;
    }
};
bool isBigger(BIGDATA x,BIGDATA y)
{
    if(x.len!=y.len)return x.len>y.len;
    else
    {
        for(int i=x.len-1; i>=0; i--)
        {
            if(x.a[i]>y.a[i])return true;
            if(x.a[i]<y.a[i])return false;
        }
        return false;
    }
}
BIGDATA multiplyDigit(BIGDATA x,int d)
{
    BIGDATA ans;
    ans.init();
    int i;
    for(i=0; i<x.len; i++)
    {
        ans.a[i]=x.a[i]*d;
    }
    for(i=0; i<x.len; i++)
    {
        if(ans.a[i]>=10)
        {
            ans.a[i+1]+=ans.a[i]/10;
            ans.a[i]%=10;
        }
    }
    i=x.len;
    while(ans.a[i]>=10)
    {
        ans.a[i+1]=ans.a[i]/10;
        ans.a[i]%=10;
        i++;
    }
    ans.len=i+1;
    for(i=ans.len-1;i>=0;i--)if(ans.a[i])break;
    if(i==-1)ans.len=1;
    else ans.len=i+1;
    return ans;
}
BIGDATA rMove(BIGDATA x)
{
    if(x.len==1&&x.a[0]==0)return x;
    for(int i=x.len-1; i>=0; i--)
    {
        x.a[i+1]=x.a[i];
    }
    x.a[0]=0;
    x.len+=1;
    return x;
}
BIGDATA minusBigDaTa(BIGDATA x,BIGDATA y)
{
    BIGDATA ans;
    ans.init();
    int i;
    for(i=0; i<x.len; i++)
    {
        if(x.a[i]<y.a[i])
        {
            x.a[i]+=10;
            x.a[i+1]--;
        }
        ans.a[i]=x.a[i]-y.a[i];
    }
    for(i=x.len-1; i>=0; i--)
    {
        if(ans.a[i]!=0)
        {
            ans.len=i+1;
            break;
        }
    }
    if(i==-1)ans.len=1;
    return ans;
}
char str[SIZE];
int len;
BIGDATA data,ans,tmp,xxx;
void input()
{
    scanf("%s",str);
    len=strlen(str);
    data.init();
    ans.init();
    tmp.init();
    xxx.init();
    for(int i=len-1; i>=0; i--)
    {
        data.a[len-1-i]=str[i]-'0';
    }
    data.len=len;
}
void work()
{
    int t=(data.len-1)/2;
    for(int i=t; i>=0; i--)
    {
        int j;
        tmp=rMove(rMove(tmp));
        tmp.a[1]=data.a[2*i+1];
        tmp.a[0]=data.a[2*i];
        tmp.len=tmp.getLen();
        //tmp.print();
        xxx=multiplyDigit(rMove(ans),2);
        //xxx.print();
        for(j=0; j<10; j++)
        {
            xxx.a[0]=j;
            xxx.len=xxx.getLen();
            BIGDATA ttmp=multiplyDigit(xxx,j);
            //printf("%d ttmp:",j);
            //ttmp.print();
            if(isBigger(ttmp,tmp))break;
        }
        if(j>=10)j=9;
        else j--;
        //printf("J=%d\n",j);
        ans=rMove(ans);
        ans.a[0]=j;
        //ans.print();
        xxx.a[0]=j;
        tmp=minusBigDaTa(tmp,multiplyDigit(xxx,j));
    }
    ans.print();
}
int main()
{
    input();
    work();
    return 0;
}
