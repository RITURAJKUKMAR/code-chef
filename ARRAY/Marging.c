#include <stdio.h>

int main() {
    int arr1[100] = {2, 4, 6}; // First array
    int size1 = 3;

    int arr2[100] = {8, 10, 12, 14}; // Second array
    int size2 = 4;

    // Update the code below to solve the problem
    
    int mergedSize=size1+size2;
    int merged[mergedSize];

    for(int i=0;i<size1;i++)
        merged[i]=arr1[i];
    
    int j=0;
    for( int i=size1;i<mergedSize;i++)
    {
        merged[i]=arr2[j];
        j++;
    }

    
    // Print the merged array
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
