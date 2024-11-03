#include <stdio.h>
int max(int arr[],int n,int i)
{
    int a=arr[i];
    for(i;i<n;i++)
    {
        if(a<arr[i])
            return arr[i];
    }
    if(i==n)
        return -1;
}

int main() {
	// your code goes here
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        printf("%d ",max(arr,n,i));
    }
    return 0;
}

