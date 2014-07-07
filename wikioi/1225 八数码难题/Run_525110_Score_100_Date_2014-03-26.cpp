#include<iostream>
#include<queue>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
using namespace std;
struct NODE
{
    int a[3][3];
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
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(nd.a[i][j]!=target.a[i][j])ans++;
        }
    }
    return ans;
}
string toString(NODE node)
{
    string str="";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            str+=char(node.a[i][j]+'0');
        }
    }
    return str;
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
    //initial the targe status.
    target.a[0][0]=1;
    target.a[0][1]=2;
    target.a[0][2]=3;
    target.a[1][0]=8;
    target.a[1][1]=0;
    target.a[1][2]=4;
    target.a[2][0]=7;
    target.a[2][1]=6;
    target.a[2][2]=5;
    target.x=1;
    target.y=1;
    target.val=0;
    //initial the start status.
    for(int i=0;i<9;i++)
    {
        node.a[i/3][i%3]=str[i]-'0';
        if(str[i]=='0')
        {
            node.x=i/3;
            node.y=i%3;
        }
    }
    node.val = Astar(node);
    node.step = 0;
    //empty the priority_queue
    while(!q.empty())q.pop();
    q.push(node);
    s.clear();
    s.insert(toString(node));
}
void work()
{
    NODE tmpNode;
    while(!q.empty())
    {
        tmpNode = q.top();
        q.pop();
        //cout<<tmpNode.step<<" "<<tmpNode.val<<endl;
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
                node.a[tmpx][tmpy]=node.a[tmpx-1][tmpy];
                node.a[tmpx-1][tmpy]=0;
                node.x=tmpx-1;
                node.y=tmpy;
                node.step++;
                node.val = Astar(node);
                if(check(toString(node)))
                {
                    q.push(node);
                    s.insert(toString(node));
                }
            }
            if(tmpx<2)
            {
                node = tmpNode;
                node.a[tmpx][tmpy]=node.a[tmpx+1][tmpy];
                node.a[tmpx+1][tmpy]=0;
                node.x=tmpx+1;
                node.y=tmpy;
                node.step++;
                node.val = Astar(node);
                if(check(toString(node)))
                {
                    q.push(node);
                    s.insert(toString(node));
                }
            }
            if(tmpy>0)
            {
                node = tmpNode;
                node.a[tmpx][tmpy]=node.a[tmpx][tmpy-1];
                node.a[tmpx][tmpy-1]=0;
                node.x=tmpx;
                node.y=tmpy-1;
                node.step++;
                node.val = Astar(node);
                if(check(toString(node)))
                {
                    q.push(node);
                    s.insert(toString(node));
                }
            }
            if(tmpy<2)
            {
                node = tmpNode;
                node.a[tmpx][tmpy]=node.a[tmpx][tmpy+1];
                node.a[tmpx][tmpy+1]=0;
                node.x=tmpx;
                node.y=tmpy+1;
                node.step++;
                node.val = Astar(node);
                if(check(toString(node)))
                {
                    q.push(node);
                    s.insert(toString(node));
                }
            }
        }
    }
    cout<<"-1"<<endl;
}
int main()
{
    while(cin>>str)
    {
        init();
        work();
    }
    return 0;
}
