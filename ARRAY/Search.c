#include <stdio.h>

int main() {
	// your code goes here
    int N,X,f=0;
    scanf("%d%d",&N,&X);
    int A[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<N;i++)
        if(A[i]==X)
        {
            f=1;
            break;
        }
    if(f)
        printf("YES");
    else
        printf("NO");
}

