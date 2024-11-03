#include <stdio.h>
int main()
{
    int r, c, fr = 0, fc = 0;
    printf("Enter value of row and column\n ");
    scanf("%d%d", &r, &c);
    int arr[r][c];
    printf("Enter array elements\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
    for (int i = 0; i < r; i++)
        if (arr[i][0] == 0)
        {
            fr = 1;
            break;
        }
    for (int j = 0; j < c; j++)
        if (arr[0][j] == 0)
        {
            fc = 1;
            break;
        }
    for (int i = 1; i < r; i++)
        for (int j = 1; j < c; j++)
            if (arr[i][j] == 0)
            {
                arr[0][i] = 0;
                arr[j][0] = 0;
            }
    for (int i = 1; i < r; i++)
        for (int j = 1; j < c; j++)
            if (arr[0][j] == 0 || arr[i][0]==0)
                arr[i][j]=0;
    if (fr)
        for (int i = 0; i < r; i++)
            arr[i][0] = 0;
    if (fc)
        for (int j = 0; j < c; j++)
            arr[0][j] = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}
// not final