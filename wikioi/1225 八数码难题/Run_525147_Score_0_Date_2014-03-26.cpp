#include<iostream>
#include<queue>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
using namespace std;
struct NODE
{
    string str;
    int x,y;
    int val,step;
    bool operator < (const NODE &nd)const
    {
        if(step >nd.step)return true;
        else if(step==nd.step&&val>nd.val)return true;
        else return false;
    }
}target,node;
set<string>s;
int len=0;
priority_queue<NODE>q;
int Astar(NODE nd)
{
    int ans=0;
    for(int i=0;i<9;i++)
    {
        if(nd.str[i]!=target.str[i])ans++;
    }
    return ans;
}

bool check(string str)
{
    if(s.find(str)==s.end())
        return true;
    else
        return false;
}
string str;
void init()
{
    target.str="123804765";
    target.x=1;
    target.y=1;
    target.val=0;
    for(int i=0;i<9;i++)
    {
        if(str[i]=='0')
        {
            node.x=i/3;
            node.y=i%3;
        }
    }
    cin>>str;
    node.str=str;
    node.val = Astar(node);
    node.step = 0;
    while(!q.empty())q.pop();
    q.push(node);
    s.clear();
    s.insert(node.str);
}
void work()
{
    NODE tmpNode;
    while(!q.empty())
    {
        tmpNode = q.top();
        q.pop();
        if(tmpNode.val==0)
        {
            cout<<tmpNode.step<<endl;
            return;
        }
        else
        {
            int tmpx=tmpNode.x;
            int tmpy=tmpNode.y;
            if(tmpx>0)
            {
                node = tmpNode;
                int pos1=tmpx*3+tmpy;
                int pos2=(tmpx-1)*3+tmpy;
                swap(node.str[pos1],node.str[pos2]);
                node.x=tmpx-1;
                node.y=tmpy;
                node.step++;
                node.val = Astar(node);
                if(check(node.str))
                {
                    q.push(node);
                    s.insert(node.str);
                }
            }
            if(tmpx<2)
            {
                node = tmpNode;
                int pos1=tmpx*3+tmpy;
                int pos2=(tmpx+1)*3+tmpy;
                swap(node.str[pos1],node.str[pos2]);
                node.x=tmpx+1;
                node.y=tmpy;
                node.step++;
                node.val = Astar(node);
                if(check(node.str))
                {
                    q.push(node);
                    s.insert(node.str);
                }
            }
            if(tmpy>0)
            {
                node = tmpNode;
                int pos1=tmpx*3+tmpy;
                int pos2=tmpx*3+tmpy-1;
                swap(node.str[pos1],node.str[pos2]);
                node.x=tmpx;
                node.y=tmpy-1;
                node.step++;
                node.val = Astar(node);
                if(check(node.str))
                {
                    q.push(node);
                    s.insert(node.str);
                }
            }
            if(tmpy<2)
            {
                node = tmpNode;
                int pos1=tmpx*3+tmpy;
                int pos2=tmpx*3+tmpy+1;
                swap(node.str[pos1],node.str[pos2]);
                node.x=tmpx;
                node.y=tmpy+1;
                node.step++;
                node.val = Astar(node);
                if(check(node.str))
                {
                    q.push(node);
                    s.insert(node.str);
                }
            }
        }
    }
    cout<<"-1"<<endl;
}
int main()
{
    init();
    work();
    return 0;
}
