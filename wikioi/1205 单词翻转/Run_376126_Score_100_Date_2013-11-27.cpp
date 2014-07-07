#include<stdio.h>
#include<string.h>
char str[1000][100];
int main()
{
    int i=0;
    while(scanf("%s",str[i])!=EOF)i++;
    for(int j=i-1;j>=0;j--)
    {
        printf("%s%c",str[j],j==0?'\n':' ');
    }
    return 0;
}
