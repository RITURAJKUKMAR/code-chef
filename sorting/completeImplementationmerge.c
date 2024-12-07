void merge(int arr[], int l, int m, int h)
{
    int n1 = (m - l + 1), n2 = (h - m);
    int index = l, index1 = 0, index2 = 0;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[i + l];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[m + i + 1];
    while (n1 && n2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[index] = arr1[index1];
            index1++;
            n1--;
        }
        else
        {
            arr[index] = arr2[index2];
            index2++;
            n2--;
        }
        index++;
    }
    while (n1)
    {
        arr[index] = arr1[index1];
        index1++;
        index++;
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
void mergeSort(int *arr, int left, int right) {
    // Write your code here
    if(left<right)
    {
        int m=(left+right)/2;
        mergeSort(arr,left,m);
        mergeSort(arr,m+1,right);
        merge(arr,left,m,right);
    }
}

