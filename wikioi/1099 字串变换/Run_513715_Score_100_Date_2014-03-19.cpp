#include<string>
#include<queue>
#include<set>
#include<iostream>
using namespace std;
struct NODE
{
    string s;
    int step;
}node;
queue<NODE>q;
string A,B,sa[10],sb[10];
int n,i,j,k;
set<string>mset;
void init()
{
    cin>>A>>B;
    n=0;
    while(cin>>sa[n])cin>>sb[n++];
    while(!q.empty())q.pop();
    node.s=A;
    node.step=0;
    q.push(node);
    //cout<<n<<endl;
    mset.clear();
    mset.insert(A);
}
int bfs()
{
    NODE tmpNode;
    while(!q.empty())
    {
        tmpNode=q.front();
        q.pop();
        int tmpStep=tmpNode.step;
        string tmpStr=tmpNode.s;
        if(tmpStr==B)
        {
            return tmpStep;
        }
        else if(tmpStep>10)
        {
            return -1;
        }
        else
        {
            int pos=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<tmpStr.size();j++)
                {
                    if((pos=tmpStr.find(sa[i],j))!=string::npos)
                    {
                        tmpNode.s=tmpStr;
                        tmpNode.s.replace(pos,sa[i].size(),sb[i]);
                        if(mset.find(tmpNode.s)==mset.end())
                        {
                            tmpNode.step=tmpStep+1;
                            q.push(tmpNode);
                            mset.insert(tmpNode.s);
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    init();
    int ans= bfs();
    if(ans == -1)cout<<"NO ANSWER!"<<endl;
    else cout<<ans<<endl;
    return 0;
}
