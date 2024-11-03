#include <stdio.h>
int main()
{
    // write your code here
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,r,c=0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            r=i%10;
            if(r==2 || r==3 ||r==9)
                c++;
        }
        printf("%d\n",c);
    }
    return 0;
}