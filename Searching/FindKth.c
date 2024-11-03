#include <stdio.h>
#include<string.h>
int main() {
	// your code goes here
    char str[100],c;
    int n,f=0,pos;
    fflush(stdin);
    scanf("%s %c%d",&str,&c,&n);
    int l= strlen(str);
    for(int i=0;i<l;i++)
    {
        if(str[i]==c)
        {
            f++;
            pos=i;
        }
    }
    if(f==n)
        printf("%d",pos);
    else
        printf("-1");
    return 0;
}

