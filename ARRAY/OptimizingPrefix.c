#include <stdio.h>

int main() {
    int N, K, i, a, b;
    
    scanf("%d", &N);
    
    long int A[N], prefix[N+1];
    
    for(i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }
    
    prefix[0] = 0;
    for(i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + A[i-1];
    }
    
    scanf("%d", &K);
    
    for(i = 0; i < K; i++) {
        scanf("%d %d", &a, &b);
        printf("%ld\n", prefix[b] - prefix[a-1]);
    }
    
    return 0;
}