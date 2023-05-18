#include <stdio.h>

// Function to perform binary search on an array
int binarysearch(int arr[], int low, int high, int x) {
    if (high >= low) {  // Check if the range is valid
        int mid = (high+low) / 2;  // Calculate the middle index

        if (arr[mid] == x)
            return mid;  // Element found at the middle index

        if (arr[mid] > x)
            return binarysearch(arr, low, mid - 1, x);  // Recursively search the left half of the array

        return binarysearch(arr, mid + 1, high, x);  // Recursively search the right half of the array
    }

    return -1;  // Element not found in the array
}


int main(void) {
    int arr[10], n, x, i, result;// arr of 10 elements, n is number of elements in array,x element to be searched,i loop counter,result store binary search


    n = 10;
    printf("Enter 10 array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Read array elements from the user
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &x);  // Read the element to be searched

    result = binarysearch(arr, 0, n - 1, x);  // Call binary search function

    if (result == -1)
        printf("Element is not present in the array");
    else
        printf("Element is present at index %d", result);

    return 0;
}
