#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int N,M;
    vector<int>v;
    scanf("%d %d",&N,&M);
    v.clear();
    for(int i=1;i<=N;i++)v.push_back(i);
    int before=0;
    while(!v.empty())
    {
        before=(before+M-1)%v.size();
        printf("%d ",v[before]);
        v.erase(v.begin()+before);
    }
    return 0;
}
