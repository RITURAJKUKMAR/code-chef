#include<stdio.h>

int search_insert_position(int arr[], int n, int k) {
    int i,h=n,l=0,mid;
    for( i=0;l<=h;i++)
    {
        mid=(h+l)/2;
        if(arr[mid]==k)
            break;
        else if(arr[mid]<k)
            l=mid+1;
        else if(arr[mid]>k)
            h=mid-1;
    }
    if(arr[mid]==k)
        return mid;
    else
        return mid+1;
}
int main()
{
    int n,k;
    printf("Enter size and ele : ");
    scanf("%d%d",&n,&k);
    int arr[n];
    printf("\nEnter array data : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nArray data : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nindex : %d",search_insert_position(arr,n,k));
    return 0;
}