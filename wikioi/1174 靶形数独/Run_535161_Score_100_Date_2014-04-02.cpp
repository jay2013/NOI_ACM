#include<stdio.h>
#include<math.h>
int row_fill[10]= {0},row_status[10]= {0},col_status[10]= {0};
int m_sudo[5][5]= {0},row_lack[10]= {0};
int ans=-1,s_order[10],map[10][10];
void score()
{
    int sum=0,i,j;
    for(i=1;i<5;i++)
    {
        for(j=i;j<11-i;j++)sum+=(map[i][j]+map[10-i][j])*(5+i);
        for(j=i+1;j<10-i;j++)sum+=(map[j][i]+map[j][10-i])*(5+i);
    }
    sum +=map[5][5]*10;
    if(sum > ans) ans = sum;
}
void dfs(int k)
{
    if(k==10)score();
    else
    {
        int x,y,j,pos,p,i=s_order[k];
        x = 511 - row_fill[i];
        y = x & -x;
        row_fill[i] |= y;
        j = (int)log2(y) + 1;
        pos = 511 - (row_status[i] | col_status[j]|m_sudo[(i-1)/3][(j-1)/3]);
        while(pos>0)
        {
            p = pos & -pos;
            pos -= p;
            map[i][j] = int(log2(p))+1;
            row_status[i] |= p;
            col_status[j] |= p;
            m_sudo[(i-1)/3][(j-1)/3] |= p;
            if(x==y)dfs(k+1);
            else dfs(k);
            row_status[i] -=p;
            col_status[j] -=p;
            m_sudo[(i-1)/3][(j-1)/3] -= p;
        }
        row_fill[i] -=y;
    }
}
int main()
{
    int i,j,used_n;
    for(i=1; i<=9; i++)
    {
        for(j=1; j<=9; j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]>0)
            {
                row_fill[i] |= 1 << (j-1);
                used_n = 1 << (map[i][j]-1);
                if(((row_status[i] & used_n)!=0)||((col_status[j] & used_n)!=0)||((m_sudo[(i-1)/3][(j-1)/3] & used_n)!=0))
                {
                    printf("-1\n");
                    return 0;
                }
                row_status[i] |= used_n;
                col_status[j] |= used_n;
                m_sudo[(i-1)/3][(j-1)/3] |= used_n;
            }
            else
                row_lack[i]++;
        }
    }
    for(i=1;i<=9;i++)s_order[i] = i;
    for(i=1;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(row_lack[s_order[i]] > row_lack[s_order[j]])
            {
                s_order[i] ^= s_order[j];
                s_order[j] ^= s_order[i];
                s_order[i] ^= s_order[j];
            }
        }
    }
    for(i=1;row_lack[s_order[i]]==0;i++);
    dfs(i);
    printf("%d\n",ans);
    return 0;
}
