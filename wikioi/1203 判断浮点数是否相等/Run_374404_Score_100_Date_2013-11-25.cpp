#include<stdio.h>
#include<math.h>
#define eps 1e-8
int main()
{
    double x,y;
    scanf("%lf %lf",&x,&y);
    printf("%s\n",fabs(x-y)<=eps?"yes":"no");
    return 0;
}
