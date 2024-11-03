#include <stdio.h>

int main() {
	// your code goes here
    int n,k=0,l;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        l=a[i];
        for(int j=i;j<n;j++)
            if(l<a[j])
                l=a[j];
        b[k]=l;
        k++;
    }
    b[k]=a[n-1];
    k++;
    for(int i=0;i<k;i++)
        if(b[i]!=b[i+1])
            printf("%d ",b[i]);
    
}

