#include<cstdio>
#include<cstring>
#define SIZE 1024
using namespace std;
struct BIGDATA
{
    int len,a[SIZE];
    void init()
    {
        len=0;
        for(int i=0;i<SIZE;i++)a[i]=0;
    }
};
char str[SIZE];
int len;
BIGDATA data,ans;
void input()
{
    scanf("%s",str);
    len=strlen(str);
    data.init();
    ans.init();
    for(int i=len-1;i>=0;i--)
    {
        data.a[len-1-i]=str[i]-'0';
    }
    data.len=len;
}
void work()
{
    int t=(data.len-1)/2;
    int tmp=0;
    int ans=0;
    int xxx;
    for(int i=t;i>=0;i--)
    {
        tmp=tmp*100+data.a[2*i+1]*10+data.a[2*i];
        xxx=ans*20;
        int j;
        for(j=0;j<10;j++)
        {
            if((xxx+j)*j>tmp)break;
        }
        if(j>=10)j=9;
        else j--;
        ans=ans*10+j;
        tmp=tmp-(xxx+j)*j;
    }
    printf("%d\n",ans);
}
int main()
{
    input();
    work();
    return 0;
}
