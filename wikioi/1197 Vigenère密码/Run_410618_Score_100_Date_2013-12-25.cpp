#include<stdio.h>
#include<string.h>
char str[30][30]={
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "BCDEFGHIJKLMNOPQRSTUVWXYZA",
    "CDEFGHIJKLMNOPQRSTUVWXYZAB",
    "DEFGHIJKLMNOPQRSTUVWXYZABC",
    "EFGHIJKLMNOPQRSTUVWXYZABCD",
    "FGHIJKLMNOPQRSTUVWXYZABCDE",
    "GHIJKLMNOPQRSTUVWXYZABCDEF",
    "HIJKLMNOPQRSTUVWXYZABCDEFG",
    "IJKLMNOPQRSTUVWXYZABCDEFGH",
    "JKLMNOPQRSTUVWXYZABCDEFGHI",
    "KLMNOPQRSTUVWXYZABCDEFGHIJ",
    "LMNOPQRSTUVWXYZABCDEFGHIJK",
    "MNOPQRSTUVWXYZABCDEFGHIJKL",
    "NOPQRSTUVWXYZABCDEFGHIJKLM",
    "OPQRSTUVWXYZABCDEFGHIJKLMN",
    "PQRSTUVWXYZABCDEFGHIJKLMNO",
    "QRSTUVWXYZABCDEFGHIJKLMNOP",
    "RSTUVWXYZABCDEFGHIJKLMNOPQ",
    "STUVWXYZABCDEFGHIJKLMNOPQR",
    "TUVWXYZABCDEFGHIJKLMNOPQRS",
    "UVWXYZABCDEFGHIJKLMNOPQRST",
    "VWXYZABCDEFGHIJKLMNOPQRSTU",
    "WXYZABCDEFGHIJKLMNOPQRSTUV",
    "XYZABCDEFGHIJKLMNOPQRSTUVW",
    "YZABCDEFGHIJKLMNOPQRSTUVWX",
    "ZABCDEFGHIJKLMNOPQRSTUVWXY"
};
int main()
{
    char str1[200],str2[1024];
    int i,len1,len2,j;
    scanf("%s %s",str1,str2);
    len1=strlen(str1);
    len2=strlen(str2);
    for(i=0;i<len2;i++)
    {
        int b;
        if(str1[i%len1]>='a'&&str1[i%len1]<='z')
        {
            b=str1[i%len1]-'a';
        }
        else
        {
            b=str1[i%len1]-'A';
        }
        for(j=0;j<28;j++)
        {
            if(str[b][j]==str2[i])
            {
                printf("%c",'A'+j);
                break;
            }
            if(str[b][j]==(str2[i]-'a'+'A'))
            {
                printf("%c",'a'+j);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
