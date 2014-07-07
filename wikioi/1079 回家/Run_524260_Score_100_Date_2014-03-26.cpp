#include<iostream>
#include<queue>
#include<vector>
#define MAXVAL 900000000
#define VERNUM 60
using namespace std;
struct NODE
{
    int to;
    int val;
    void init_node()
    {
        to = -1;
        val = MAXVAL;
    }
}node;
vector<NODE>ver[VERNUM];
queue<int>q;
int D[VERNUM],P,len;
int visit[VERNUM];
char ch1,ch2;
void init()
{
    for(int i=0;i<VERNUM;i++)ver[i].clear(),D[i]=MAXVAL,visit[i]=0;
    while(!q.empty())q.pop();
    cin>>P;
    while(P--)
    {
        cin>>ch1>>ch2>>len;
        if(ch1==ch2)continue;
        else
        {
            node.init_node();
            node.val=len;
            int tmp1,tmp2;
            if(ch1>='A'&&ch1<='Z')
            {
                tmp1=ch1-'A';
            }
            else
            {
                tmp1 = ch1-'a'+26;
            }
            if(ch2>='A'&&ch2<='Z')
            {
                tmp2=ch2-'A';
            }
            else
            {
                tmp2 = ch2-'a'+26;
            }
            node.to = tmp2;
            ver[tmp1].push_back(node);
            node.to = tmp1;
            ver[tmp2].push_back(node);
        }
    }
}
void work()
{
    visit[25]=1;
    q.push(25);
    D[25]=0;
    while(!q.empty())
    {
        int tmp = q.front();
        //cout<<tmp<<endl;
        q.pop();
        visit[tmp]=0;
        for(int i=0;i<ver[tmp].size();i++)
        {
            node=ver[tmp][i];
            int tmpTo=node.to;
            if(D[tmpTo]>D[tmp]+node.val)
            {
                D[tmpTo]=D[tmp]+node.val;
                if(visit[tmpTo]==0)
                {
                    visit[tmpTo]=1;
                    q.push(tmpTo);
                }
            }
        }
    }
    int ans=MAXVAL,pos=-1;
    for(int i=0;i<25;i++)
    {
        //cout<<D[i]<<endl;
        if(D[i]<ans)
        {
            ans=D[i];
            pos=i;
        }
    }
    ch1=pos+'A';
    cout<<ch1<<" "<<ans<<endl;
}
int main()
{
    init();
    work();
    return 0;
}
