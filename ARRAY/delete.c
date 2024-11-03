#include <stdio.h>

int main() {
    int arr[100] = {2, 4, 6, 8, 10}; // Initial array
    int size = 5; // Current size of the array

    int positionToDelete = 2; // Index of the element to delete

    // Update the code to shift elements to fill the gap left by the deleted element
    
    
    

    // Update the size of the array
    for(int i=positionToDelete;i<size;i++)
        arr[i]=arr[i+1];
    size--;
    

    // Print the updated array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
