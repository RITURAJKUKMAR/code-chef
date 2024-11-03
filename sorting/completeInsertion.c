void insertionSort(int arr[], int n) {
    // Write your code here
    for(int i=1;i<n;i++)
    {
        int j,temp=arr[i];
        for( j=i-1;j>=0 && arr[j] > temp;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}