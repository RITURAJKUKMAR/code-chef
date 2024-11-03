#include <stdio.h>

int main()
{
	// your code goes here
	int n, sum = 0;
	scanf("%d", &n);
	int a[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				sum = sum + a[i][j];
			else if (n - i - 1 == j)
				sum = sum + a[i][j];

	printf("%d", sum);
}
