#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>

using namespace std;
int dx[5]= {0,-1,0,1,0},dy[5]= {0,0,-1,0,1},a[10][10];
struct bign
{
    int x1,y1,x2,y2,b,a[10][10],ans;
};//词汇量有限，不知道要取什么，不要吐槽。。。。
queue<bign>d;
void get(bign &x,int x1,int y1,int x2,int y2,int b,int a[10][10],int ans)
{
    x.x1=x1;
    x.x2=x2;
    x.y1=y1;
    x.y2=y2;
    x.b=b;
    x.ans=ans;
    for(int i=0; i<=4; i++)
        for(int j=0; j<=4; j++) x.a[i][j]=a[i][j];
}//这个函数是用来把所有的状态快速复制到x这个结构里面用的。

bool pd(const bign &x)
{
    int k;
    for(int i=1; i<=4; i++)
    {
        k=x.a[i][1];
        for(int j=2; j<=4; j++) if(x.a[i][j]!=k)break;
            else if(j==4) return 1;
        k=x.a[1][i];
        for(int j=2; j<=4; j++) if(x.a[j][i]!=k)break;
            else if(j==4) return 1;
    }
    if(x.a[1][1]==x.a[2][2] && x.a[2][2]==x.a[3][3] && x.a[3][3]==x.a[4][4]) return 1;
    if(x.a[4][1]==x.a[3][2] && x.a[3][2]==x.a[2][3] && x.a[2][3]==x.a[1][4]) return 1;
    return 0;
}//判断x这个状态是否到达目标。
int bfs()
{
    bign temp,t,tem;
    int tx1,tx2,ty1,ty2,next;
    while(!d.empty())
    {
        temp=d.front();
        next=(temp.b==1)?2:1;//next表示的是temp这个状态下一步走的是白棋还是黑棋。
        if(pd(temp))return(temp.ans);//一旦发现目标就返还答案，这个答案一定是最优的。
        for(int i=1; i<=4; i++)
        {
            tx1=temp.x1+dx[i];
            tx2=temp.x2+dx[i];
            ty1=temp.y1+dy[i];
            ty2=temp.y2+dy[i];
            if(temp.a[tx1][ty1]==next) //这里不用判断是否出界，为什么呢？因为出界了 temp.a[tx1][ty1]肯定不是next，而是0。下同。
            {
                tem=temp;
                tem.a[tem.x1][tem.y1]=next;
                tem.a[tx1][ty1]=0;
                get(t,tx1,ty1,tem.x2,tem.y2,next,tem.a,tem.ans+1);
                d.push(t);
            }
            if(temp.a[tx2][ty2]==next)
            {
                tem=temp;
                tem.a[tem.x2][tem.y2]=next;
                tem.a[tx2][ty2]=0;
                get(t,tem.x1,tem.y1,tx2,ty2,next,tem.a,tem.ans+1);
                d.push(t);
            }
        }
        d.pop();
    }
}

int main()
{
    char temp;
    bool b=false;
    int x1,x2,y1,y2,tx1,tx2,ty1,ty2;
    bign t,t1,tem;
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            cin>>temp;
            if (temp=='O')
            {
                if (!b)
                {
                    x1=i;
                    y1=j;
                }
                else
                {
                    x2=i;
                    y2=j;
                }
                b=!b;
                a[i][j]=0;
            }
            else a[i][j]=temp=='B'?1:2;
        }
    }
    get(t,x1,y1,x2,y2,0,a,0);
    if(pd(t))
    {
        cout<<0;
        return 0;
    }
    for(int i=1; i<=4; i++)
    {
        tx1=t.x1+dx[i];
        tx2=t.x2+dx[i];
        ty1=t.y1+dy[i];
        ty2=t.y2+dy[i];
        if(tx1!=t.x2 || ty1!=t.y2 &&tx1>0 && tx1<=4 &&ty1>0&&ty1<=4)
        {
            tem=t;
            tem.a[tem.x1][tem.y1]=tem.a[tx1][ty1];
            tem.a[tx1][ty1]=0;
            get(t1,tx1,ty1,tem.x2,tem.y2,tem.a[tem.x1][tem.y1],tem.a,1);
            d.push(t1);
        }
        if(tx2!=t.x1 || ty2!=t.y1 &&tx2>0 && tx2<=4 &&ty2>0&&ty2<=4)
        {
            tem=t;
            tem.a[tem.x2][tem.y2]=tem.a[tx2][ty2];
            tem.a[tx2][ty2]=0;
            get(t1,tem.x1,tem.y1,tx2,ty2,tem.a[tem.x2][tem.y2],tem.a,1);
            d.push(t1);
        }//初始化状态
    }
    cout<<bfs();
    return 0;
}
