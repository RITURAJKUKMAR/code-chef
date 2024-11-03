#include <stdio.h>
int main()
{
    // your code goes here
    int n,k;
    scanf("%d%d",&n,&k);
    int a,b;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if((a+b)%k==0)
            printf("(%d, %d)\n",a,b);
    }
    return 0;
}