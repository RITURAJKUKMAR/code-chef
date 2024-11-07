#include <stdio.h>

int main() {
    // your code goes here
    int n;
    scanf("%d", & n);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        scanf("%d%d", & a[i], & b[i]);
    int i,A, B;
    scanf("%d%d", & A, & B);
    for ( i = 0; i < n; i++)
    {
        if ((a[i] == A) && (b[i] == B))
        {
            printf("Yes\n");
            break;
        }
        else if ((b[i] == A) && (a[i] == B))
        {
            printf("Yes\n");
            break;
        }
    }
    if(i==n)
        printf("No\n");
    return 0;
}