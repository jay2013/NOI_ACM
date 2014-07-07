#include<stdio.h>
#define SIZE 100002
int main()
{
    int A[SIZE],B[SIZE],C[SIZE],i,MAX=0,MIN=0,r=1,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)scanf("%d",&A[i]);
    for(i=2; i<=n; i++)
        if(A[i-1]>A[i])
        {
            C[r+1]=A[i];
            B[r++]=A[i-1];
        }
    B[r]=A[n];
    for(i=1; i<=r; i++)MAX+=B[i];
    for(i=2; i<=r; i++)MIN+=C[i];
    printf("%d\n",MAX-MIN);
    return 0;
}
