#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", & n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    int input[n];
    int l, m;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", & l, & m);
        arr[l][m]=1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}