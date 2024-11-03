int Min(int arr[],int n,int i)
{
    int min=arr[i],index=i;
    for(i+1;i<n;i++)
        if(min>arr[i])
        {
            index=i;
            min=arr[i];
        }
    return index;
}

void selectionSort(int arr[], int n) {
    // Write your code here
    int minIndex,temp;
    for(int i=0;i<n-1;i++)
    {
        minIndex=Min(arr,n,i);
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}