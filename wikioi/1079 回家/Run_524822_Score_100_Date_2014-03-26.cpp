#include<cstdio>
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
char ch1[2],ch2[2];
void init()
{
    for(int i=0;i<VERNUM;i++)ver[i].clear(),D[i]=MAXVAL,visit[i]=0;
    while(!q.empty())q.pop();
    scanf("%d",&P);
    while(P--)
    {
        scanf("%s %s %d",ch1,ch2,&len);
        if(ch1[0]==ch2[0])continue;
        else
        {
            node.init_node();
            node.val=len;
            int tmp1,tmp2;
            if(ch1[0]>='A'&&ch1[0]<='Z')
            {
                tmp1=ch1[0]-'A';
            }
            else
            {
                tmp1 = ch1[0]-'a'+26;
            }
            if(ch2[0]>='A'&&ch2[0]<='Z')
            {
                tmp2=ch2[0]-'A';
            }
            else
            {
                tmp2 = ch2[0]-'a'+26;
            }
            node.to = tmp2;
            ver[tmp1].push_back(node);
            node.to = tmp1;
            ver[tmp2].push_back(node);
        }
    }
}
void SPFA()
{
    visit[25]=1;
    q.push(25);
    D[25]=0;
    while(!q.empty())
    {
        int tmp = q.front();
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
}
int main()
{
    init();
    SPFA();
    int ans=MAXVAL,pos=-1;
    for(int i=0;i<25;i++)
    {
        if(D[i]<ans)
        {
            ans=D[i];
            pos=i;
        }
    }
    printf("%c %d\n",pos+'A',ans);
    return 0;
}
