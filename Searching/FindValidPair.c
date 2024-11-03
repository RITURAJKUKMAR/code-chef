#include <stdio.h>

int main()
{
    // your code goes here
    int n;
    scanf("%d", &n);
    n = n * 2;
    int arr[n], sum, pro, min, max;
    for (int i = 0; i < n; i = i + 2)
        scanf("%d%d", &arr[i],&arr[i+1]);
    scanf("%d%d", &min, &max);
    for (int i = 0; i < n; i = i + 2)
    {
        sum = arr[i] + arr[i + 1];
        pro = arr[i] * arr[i + 1];
        if ((min <= sum && max >= pro) && (min <= pro && max >= sum))
            printf("%d %d\n", arr[i], arr[i + 1]);
    }
    return 0;
}
