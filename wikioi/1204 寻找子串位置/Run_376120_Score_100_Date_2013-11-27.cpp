#include<stdio.h>
#include<string.h>
char str[110],str2[110];

int getPos()
{
    int len1,len2,i,j;
    len1=strlen(str);
    len2=strlen(str2);
    int pos=-1;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(str[i+j]!=str2[j])
                break;
        }
        if(j==len2)
        {
            pos=i+1;
            break;
        }
    }
    return pos;
}
int main()
{
    scanf("%s %s",str,str2);
    printf("%d\n",getPos());
    return 0;
}
