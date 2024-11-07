#include<stdio.h>
int j=0,carry=0;
void multipalication(int arr[],int n)
{
    int mul;
    for(int i=0;n!=0;i++)
    {
        j=0;
        printf("\n%d * %d",arr[i],n);
        mul=(arr[i]*n)+carry;
        arr[j++]=mul%10;
        carry=mul/10;
        printf("\n%d %d",carry,arr[j]);
        n=n/10;
    }
    while(carry!=0)
    {
        arr[j++]=carry%10;
        carry=carry/10;
    }
}
int main()
{
    int n,*arr;
    printf("\nEnter a number : ");
    scanf("%d",&n);
    *(arr)=n;
    for(int i=1;i<n;i++)
    {
        multipalication(arr,i);
    }
    printf("\n");
    for(int i=j-1;i>=0;i--)
        printf("%d",arr[i]);
    return 0;
}

// not final