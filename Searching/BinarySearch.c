#include <stdio.h>

int binary_search(int arr[], int n, int k) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (k==arr[middle]) {
            return middle;
        } else if (arr[middle] > k) {
            right=middle-1;
        } else {
            left=middle+1;
        }
    }
    return -1; // k not found
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", binary_search(arr, n, k));
    return 0;
}
