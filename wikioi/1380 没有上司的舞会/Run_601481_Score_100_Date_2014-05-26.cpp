#include<cstdio>
#include<vector>
#include<algorithm>
#define SIZE 6010
using namespace std;
vector<int> v[SIZE];
int happy[SIZE],N,root;
int f[SIZE][2];
void init(){
    for(int i=0;i<SIZE;i++)v[i].clear();
    scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%d",&happy[i]);
    int L,K;
    int tmp[SIZE];
    for(int i=1;i<=N;i++)tmp[i]=0;
    for(int i=1;i<N;i++){
        scanf("%d %d",&L,&K);
        v[K].push_back(L);
        tmp[L]=1;
    }
    scanf("%d %d",&L,&K);
    for(int i=1;i<=N;i++){
        if(tmp[i]==0){
            root=i;
            break;
        }
    }
}

void dp(int root){
    if(v[root].size()==0){
        f[root][0]=0;
        f[root][1]=happy[root];
    }
    else{
        for(int i=0;i<v[root].size();i++){
            dp(v[root][i]);
        }
        f[root][0]=0;
        f[root][1]=happy[root];
        for(int i=0;i<v[root].size();i++){
            int tmp=v[root][i];
            f[root][0]+=max(f[tmp][0],f[tmp][1]);
            f[root][1]+=f[tmp][0];
        }
    }
}
int main()
{
    init();
    dp(root);
    printf("%d\n",max(f[root][0],f[root][1]));
    return 0;
}