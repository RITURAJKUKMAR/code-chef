#include <stdio.h>

int main() {
	// your code goes here
	int n,k,a,b;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++)
	    scanf("%d",&A[i]);
	scanf("%d",&k);
	while(k--)
	{
	    int sum=0;
	    scanf("%d %d",&a,&b);
	    for(int i=a-1;i<b;i++)
			sum=sum+A[i];
	    printf("%d\n",sum);
	}
}

