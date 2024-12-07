#include<stdio.h>
int search(int arr[],int n,int k)
{
    int h=n-1,l=0,mid;
    while(l<=h)
    {
        mid=(h+l)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k)
            l=mid+1;
        else
            h=mid+1;
    }
    return -1;
}
int main()
{
    int n,ele;
    printf("Enter the size of arrray : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the find elemetn : ");
    scanf("%d",&ele);
    printf("\nSearch elements : %d",search(arr,n,ele));
    return 0;
}