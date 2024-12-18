int search_insert_position(int arr[], int n, int k) {
    int l = 0, h = n-1, m = (l + h) / 2;
    while (l <= h){
        m=(l+h)/2;
        if (arr[m] == k)
            return m;
        else if (arr[m] < k)
            l = m + 1;
        else
            h = m - 1;
    }
    return l;
}