#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int min=arr[0],before=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<k && min<arr[i])
            min=arr[i];
    }
    printf("%d",min);
    return 0;
}

// not final