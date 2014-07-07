#include<stdio.h>
int main()
{
    int a;
    double b;
    scanf("%d %lf",&a,&b);
    int tmp=a*b/10;
    printf("%d0\n",tmp/10+(tmp%10>=5?1:0));
    return 0;
}
