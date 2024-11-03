#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int max = arr[0],m=arr[0];
    for (int i = 0; i < n; i++)
    {
        // for (int j = i; j < n; j++)
        {
            if(max<arr[i]+m)
            {
                printf(" %d ",max);
                max=m+arr[i];
            }
        }
        if(max>m)
            m=max;
    }
    printf("\n%d",max);
}
// not final