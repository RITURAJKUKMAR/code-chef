#include <stdio.h>

int main() {
	// your code goes here
	int m,n;
	scanf("%d %d",&m,&n);
	int a[m][n];
	for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++)
	        scanf("%d",&a[i][j]);
	int p;
	scanf("%d %d",&n,&p);
	int b[n][p];
	for(int i=0;i<n;i++)
	    for(int j=0;j<p;j++)
	        scanf("%d",&b[i][j]);
	int c[m][n],sum=0;
	for(int i=0;i<m;i++)
	{
	    for(int j=0;j<p;j++)
	    {
	        sum=0;
	        for(int k=0;k<n;k++)
	        {
	            sum=sum+a[i][k]*b[k][j];
	        }
            c[i][j]=sum;
	        printf("%d ",c[i][j]);
	    }
	    printf("\n");
	}

}

