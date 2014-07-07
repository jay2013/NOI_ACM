#include<stdio.h>
#include<math.h>
int isprime(int n)
{
    if(n==0||n==1)return 0;
    else if(n==2||n==3)return 1;
    else
    {
        int i,t=sqrt(n);
        for(i=2;i<=t;i++)
        {
            if(n%i==0)return 0;
        }
        return 1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%s\n",isprime(n)?"\\t":"\\n");
    return 0;
}
