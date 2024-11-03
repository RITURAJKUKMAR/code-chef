#include <stdio.h>

int main() {
	// your code goes here
	int n,m,in=0,ij=0,z;
	scanf("%d %d",&n,&m);
	int a[n][m],r,c1;
	for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++)
	        scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
		if(a[i][0]==0)
			r=1;
}

// not final

// pk
/*

#include <stdio.h>

int main()
{
    // your code goes here
    int r, c;
    scanf("%d", &r);
    scanf("%d", &c);
    int A[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    int fr = 0, fc = 0;
    for (int j = 0; j < c; j++)
    {
        if (A[0][j] == 0)
        {
            fr = 1;
            break;
        }
    }
    for (int i = 0; i < r; i++)
    {
        if (A[i][0] == 0)
        {
            fc = 1;
            break;
        }
    }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (A[i][j] == 0)
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (A[i][0] == 0 || A[0][j] == 0)
            {
                A[i][j] = 0;
            }
        }
    }
    if (fr)
    {
        for (int j = 0; j < c; j++)
        {
            A[0][j] = 0;
        }
    }
    if (fc)
    {
        for (int i = 0; i < r; i++)
        {
            A[i][0] = 0;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}

*/