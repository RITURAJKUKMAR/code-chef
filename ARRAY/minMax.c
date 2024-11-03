#include <stdio.h>

int main() {
    int t,m;
    scanf("%d", &t);

    while (t--) {
        int n,M=0;
        scanf("%d", &n);
        int a[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        m=a[0];
        // Your code goes here
        for(int i=0;i<n;i++)
            if(m>a[i])
                m=a[i];
        
        for(int i=0;i<n;i++)
            if(m!=a[i])
                M++;

        printf("%d\n",M);
    }

    return 0;
}
