void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
int quick(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = (l - 1);
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
void quickSort(int *arr, int left, int right) {
    // Write your code here
    if(left<=right)
    {
        int pivot=quick(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot+1,right);
    }
}

