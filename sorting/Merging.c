#include <stdio.h>

int merge(int arr1[], int n1, int arr2[], int n2, int arr[])
{
    int index = 0, index1 = 0, index2 = 0;
    while (n1 && n2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[index] = arr1[index1];
            index1++;
            index++;
            n1--;
        }
        else
        {
            arr[index] = arr2[index2];
            index2++;
            index++;
            n2--;
        }
    }
    while (n1)
    {
        arr[index] = arr1[index1];
        index++;
        index1++;
        n1--;
    }
    while (n2)
    {
        arr[index] = arr2[index2];
        index2++;
        index++;
        n2--;
    }
}
int main()
{
    // your code goes here
    int n1;
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    int n2;
    scanf("%d", &n2);
    int arr2[n2], arr[n1 + n2];
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    merge(arr1, n1, arr2, n2, arr);

    for (int i = 0; i < (n1 + n2); i++)
        printf("%d ", arr[i]);
    return 0;
}
