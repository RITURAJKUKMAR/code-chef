#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int ar[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + ar[j];
            if (sum == k)
            {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}