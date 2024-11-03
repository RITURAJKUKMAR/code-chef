#include <stdio.h>

int main() {
	// your code goes here
    int n,sum=0;
    scanf("%d",&n);
    int a[n],p[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        p[i]=sum;
    }
    for(int i=0;i<n;i++)
        printf("%d ",p[i]);

}

