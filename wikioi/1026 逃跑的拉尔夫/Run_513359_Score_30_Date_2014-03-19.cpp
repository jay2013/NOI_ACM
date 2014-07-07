#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct NODE
{
    int x,y,step;
}node;
queue<NODE> q;
int R,C,N,i,j,k;
char Map[60][60];
char direction[1024][6];
void init()
{
    scanf("%d %d",&R,&C);
    for(i=0;i<R;i++)scanf("%s",Map[i]);
    scanf("%d",&N);
    for(i=1;i<=N;i++)scanf("%s",direction[i]);
    while(!q.empty())q.pop();
    node.step=0;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(Map[i][j]=='*')
            {
                node.x=i;
                node.y=j;
                q.push(node);
                Map[i][j]='.';
                return;
            }
        }
    }
}
void work()
{
    NODE tmpNode;
    while(!q.empty())
    {
        tmpNode=q.front();
        q.pop();
        if(tmpNode.step==N)
        {
            Map[tmpNode.x][tmpNode.y]='*';
        }
        else
        {
            int tmpStep=tmpNode.step;
            int pos_x = tmpNode.x;
            int pos_y = tmpNode.y;
            char tmpStr[100];
            strcpy(tmpStr,direction[tmpStep+1]);
            if(strcmp(tmpStr,"NORTH")==0)
            {
                while(pos_x-1>=0&&Map[pos_x-1][pos_y]!='X')
                {
                    tmpNode.step = tmpStep+1;
                    tmpNode.x=pos_x-1;
                    tmpNode.y=pos_y;
                    q.push(tmpNode);
                    pos_x--;
                }
            }
            else if(strcmp(tmpStr,"SOUTH")==0)
            {
                    while(pos_x+1<R&&Map[pos_x+1][pos_y]!='X')
                    {
                        tmpNode.step = tmpStep+1;
                        tmpNode.x=pos_x+1;
                        tmpNode.y=pos_y;
                        q.push(tmpNode);
                        pos_x++;
                    }
            }
            else if(strcmp(tmpStr,"WEST")==0)
            {
                    while(pos_y-1>=0&&Map[pos_x][pos_y-1]!='X')
                    {
                        tmpNode.step = tmpStep+1;
                        tmpNode.x=pos_x;
                        tmpNode.y=pos_y-1;
                        q.push(tmpNode);
                        pos_y--;
                    }
            }
            else if(strcmp(tmpStr,"EAST")==0)
            {
                    while(pos_y+1<C&&Map[pos_x][pos_y+1]!='X')
                    {
                        tmpNode.step = tmpStep+1;
                        tmpNode.x=pos_x;
                        tmpNode.y=pos_y+1;
                        q.push(tmpNode);
                        pos_y++;
                    }
            }
        }
    }
    for(i=0;i<R;i++)printf("%s\n",Map[i]);
}
int main()
{
    init();
    work();
    return 0;
}
