#include<iostream>
using namespace std; 
long long f[210][7]; 
int n,k,i,j; 
int main()
{ 
	cin>>n>>k; 
	f[0][0]=1;
	for(i=1;i<=n;i++)
	 for(j=1;j<=k;j++)
          if(i>=j)f[i][j]=f[i-j][j]+f[i-1][j-1];
	cout<<f[n][k];
	return 0;
} 