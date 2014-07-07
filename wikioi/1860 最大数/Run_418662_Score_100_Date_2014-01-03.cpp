#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int cmp(string str1,string str2)
{
    return (str1+str2)>(str2+str1);
}
int main()
{
    int n;
    string num[30];
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num,num+n,cmp);
    for(int i=0;i<n;i++)cout<<num[i];
    cout<<endl;
    return 0;
}
