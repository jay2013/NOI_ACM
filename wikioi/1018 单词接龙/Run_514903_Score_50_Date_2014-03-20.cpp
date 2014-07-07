#include<iostream>
#include<string.h>
#include<string>
using namespace std;
string dic[24],root;
int visit[24];
int n;
void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>dic[i];
    cin>>root;
    memset(visit,0,sizeof(visit));
}
int check(int index1,int index2)
{
    if(dic[index1].find(dic[index2])!=string::npos||dic[index2].find(dic[index1])!=string::npos)return -1;
    int len1=dic[index1].size();
    int len2=dic[index2].size();
    for(int i=0;i<=len2-1;i++)
    {
        if(dic[index2][i]==dic[index1][len1-1])
        {
            int flag=1;
            for(int j=i;j>=0;j--)
            {
                if(dic[index2][j]!=dic[index1][len1+j-i-1])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)return i+1;
        }
    }
    return -1;
}

int dfs(int index)
{
    visit[index]++;
    int len;
    int ans=dic[index].size();
    for(int i=1;i<=n;i++)
    {
        len=check(index,i);
        if(len!=-1&&visit[i]<2)
        {
            int tmpStr=dfs(i);
            if(tmpStr+dic[index].size()-len>ans)ans=tmpStr+dic[index].size()-len;
        }
    }
    visit[index]--;
    return ans;
}
int main()
{
    init();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dic[i][0]==root[0])
        {
            int tmp = dfs(i);
            if(tmp>ans)ans=tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}