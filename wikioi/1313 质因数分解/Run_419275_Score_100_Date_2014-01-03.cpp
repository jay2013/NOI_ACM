#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==0)printf("%d\n",n/2);
    else{
        for(int i=3;i<=sqrt(n);i+=2)
        {
            if(n%i==0)
            {
                printf("%d\n",n/i);
                break;
            }
        }
    }

    return 0;
}
