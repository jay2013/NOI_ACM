#include<stdio.h>
#include<algorithm>
using namespace std; 
const int maxn=1000; 
int H[maxn],hash[maxn],Rec[maxn];
int main() 
{
   
    int pos=0,MAX,ans1,ans2; while(scanf("%d",&H[pos])!=EOF)pos++;
    for(int i=0;i<pos;i++)Rec[i]=0,hash[i]=0; Rec[0]=1;
    for(int i=1;i<pos;i++){ 
MAX=0;
        for(int j=i-1;j>=0;j--){   
if(H[i]<=H[j])MAX=max(MAX,Rec[j]);
}  
Rec[i]=MAX+1;
   
} 
MAX=-1;
    for(int i=0;i<pos;i++){      
MAX=max(MAX,Rec[i]);
    }
ans1=MAX; hash[0]=1;
    for(int i=1;i<pos;i++){   
MAX=0;
        for(int j=i-1;j>=0;j--){
            if(H[i]>=H[j])MAX=max(MAX,hash[j]);     
} 
hash[i]=MAX+1;
    }
    MAX=0;
    for(int i=0;i<pos;i++){  
MAX=max(MAX,hash[i]); }
 
ans2=MAX;  
printf("%d\n%d\n",ans1,ans2); 
return 0;
}