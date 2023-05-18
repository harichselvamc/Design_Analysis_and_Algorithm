#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to exchange the values of two integers
void Exch(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to perform the QuickSort algorithm
void QuickSort(int a[], int low, int high)
{
    int i, j, key, k;
    
    // Base case: If the range is invalid or has only one element, return
    if (low >= high)
        return;
    
    key = low;  // Set the first element as the pivot
    i = low + 1;  // Initialize the left pointer
    j = high;  // Initialize the right pointer
    
    // Partition the array based on the pivot
    while (i <= j)
    {
        // Move the left pointer to the right until a value greater than the pivot is found
        while (a[i] <= a[key])
            i = i + 1;
        
        // Move the right pointer to the left until a value smaller than or equal to the pivot is found
        while (a[j] > a[key])
            j = j - 1;
        
        // Swap the elements at i and j if i is less than j
        if (i < j)
            Exch(&a[i], &a[j]);
    }
    
    // Swap the pivot with the element at position j (pivot's correct position)
    Exch(&a[j], &a[key]);
    
    // Recursively sort the subarrays on the left and right of the pivot
    QuickSort(a, low, j - 1);
    QuickSort(a,high,j+1);
}

int main()
{
    int n, a[1000], k;
    clock_t st, et;
    double ts;
    
    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);
    
    printf("\nThe Random Numbers are:\n");
    
    // Generate and print random numbers
    for (k = 1; k <= n; k++)
    {
        a[k] = rand();
        printf("%d\t", a[k]);
    }
    
    st = clock();  // Start the clock
    
    // Sort the array using QuickSort algorithm
    QuickSort(a, 1, n);
    
    et = clock();  // Stop the clock
    
    ts = (double)(et - st) / CLOCKS_PER_SEC;  // Calculate the elapsed time
    
    printf("\nSorted Numbers are: \n");
    
    // Print the sorted numbers
    for (k = 1; k <= n; k++)
        printf("%d\t", a[k]);
    
    printf("\nThe time taken is %e", ts);
    
    return 0;
}
