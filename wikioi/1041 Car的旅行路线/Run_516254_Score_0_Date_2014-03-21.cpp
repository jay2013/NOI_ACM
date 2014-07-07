#include<iostream>
#include<cmath>
#define infinite 1e8
using namespace std;
int n,s,t,A,B,x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4,ti,len;
struct NODE
{
	int x,y,index,f;
}node[500];
double Map[500][500];
void init()
{
	cin>>s>>t>>A>>B;
    node[0].x=-1;
    node[0].y=-1;
    node[0].index=A;
    node[0].f=0;
    node[4*s+1].x=-2;
    node[4*s+1].y=-2;
    node[4*s+1].index=B;
    node[4*s+1].f=0;
    len=4*s+2;
    for(int i=1;i<=s;i++)
    {
    	cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3>>ti;
        if((x_1-x_2)*(x_3-x_2)+(y_1-y_2)*(y_3-y_2)==0)
        {
        	x_4=x_1-x_2+x_3;
            y_4=y_1-y_2+y_3;
        }
        else if((x_1-x_3)*(x_2-x_3)+(y_1-y_3)*(y_2-y_3)==0)
        {
        	x_4=x_1+x_2-x_3;
            y_4=y_1+y_2-y_3;
        }
        else
        {
        	x_4=x_2+x_3-x_1;
            y_4=y_2+y_3-y_1;
        }
        node[4*i-3].x=x_1;
        node[4*i-3].y=y_1;
        node[4*i-3].index=i;
        node[4*i-3].f=ti;
        node[4*i-2].x=x_2;
        node[4*i-2].y=y_2;
        node[4*i-2].index=i;
        node[4*i-2].f=ti;
        node[4*i-1].x=x_3;
        node[4*i-1].y=y_3;
        node[4*i-1].index=i;
        node[4*i-1].f=ti;
        node[4*i-0].x=x_4;
        node[4*i-0].y=y_4;
        node[4*i-0].index=i;
        node[4*i-0].f=ti;
    }
    //³õÊ¼»¯Map
    for(int i=0;i<500;i++)
        for(int j=0;j<500;j++)
        	Map[i][j]=infinite;
    //¼ÆËã¾àÀë
    for(int i=0;i<len;i++)
    {
    	if(node[i].index==node[0].index)
        {
        	Map[0][i]=0;
            Map[i][0]=0;
        }
        if(node[i].index==node[len-1].index)
        {
        	Map[i][len-1]=0;
            Map[len-1][i]=0;
        }
    }
    for(int i=1;i<len-1;i++)
    {
    	for(int j=1;j<len-1;j++)
        {
        	if(i==j)
            {
            	Map[i][j]=0;
            }
            else
            {
                double distance = sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
            	if(node[i].index==node[j].index)
                {
                	Map[i][j]=distance*node[i].f;
                    Map[j][i]=distance*node[i].f;
                }
                else
                {
                	Map[i][j]=distance*t;
                    Map[j][i]=distance*t;
                }
            }
        }
    }
}
void work()
{
	for(int i=0;i<len;i++)
    {
    	for(int j=0;j<len;j++)
        {
        	for(int k=0;k<len;k++)
            {
            	if(Map[i][j]>Map[i][k]+Map[k][j])
                {
                	Map[i][j]=Map[i][k]+Map[k][j];
                    Map[j][i]=Map[k][i]+Map[k][j];
                }
            }
        }
    }
}
int main()
{
    cin>>n;
    while(n--)
    {
    	init();
        work();
        cout<<Map[0][len-1]<<endl;
    }
	return 0;
}
