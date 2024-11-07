#include<stdio.h>

int main()
{
    int n, k;
    scanf("%d%d", & n, & k);
    int arr[n], diff[n];
    for (int i = 0; i < n; i++)
        scanf("%d", & arr[i]);
    for (int i = 0; i < n; i++)
    {
        if (0 > arr[i] - k)
            diff[i] = -(arr[i] - k);
        else
            diff[i] = arr[i] - k;
    }
    int i = 0, min = diff[0];
    for (i = 0; i < n; i++)
    {
        if (min > diff[i])
            min = diff[i];
    }
    int ans, index = 0;
    for (i = 0; i < n; i++)
    {
        if (min == diff[i])
        {
            index = i;
            break;
        }
    }
    printf("%d",arr[index]);
    return 0;
}