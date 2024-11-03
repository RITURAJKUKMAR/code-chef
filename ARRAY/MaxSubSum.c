#include <stdio.h>

int main() {
	// your code goes here
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
	    int N;
	    scanf("%d",&N);
	    int a[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&a[i]);
        int max=a[0],m=a[0];
        for(int i=1;i<N;i++)
        {
            if(a[i]>max+a[i])
                max=a[i];
            else
                max=max+a[i];
            if(max>m)
                m=max;
        }
	    printf("\n%d\n",m);
	}
}

