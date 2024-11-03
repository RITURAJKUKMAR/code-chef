#include <stdio.h>

int main() {
	// your code goes here
    int T,f;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long int N;
        scanf("%d",&N);
        int A[N];
        for(int i=0;i<N;i++)
            scanf("%d",&A[i]);
        f=A[0];
        for(int i=0;i<N;i++)
            if(f<A[i])
                f=A[i];
        printf("%d\n",f);
    }
}

