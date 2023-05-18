#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void Merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[20];
    i = low;
    j = mid + 1;
    k = low;

    // Merge two sorted subarrays into a temporary array b[]
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++]; // Copy element from the first subarray
        else
            b[k++] = a[j++]; // Copy element from the second subarray
    }

    // Copy any remaining elements from the first subarray
    while (i <= mid)
        b[k++] = a[i++];

    // Copy any remaining elements from the second subarray
    while (j <= high)
        b[k++] = a[j++];

    // Copy the sorted elements from the temporary array back to the original array a[]
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void MergeSort(int a[], int low, int high)
{
    int mid;

    // Base case: If the array has only one element or is empty, return
    if (low >= high)
        return;

    // Find the middle index
    mid = (low + high) / 2;

    // Recursively sort the first and second halves of the array
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);

    // Merge the sorted subarrays
    Merge(a, low, mid, high);
}

int main()
{
    int n, a[2000], k;
    clock_t st, et;
    double ts;

    // clrscr(); // Clear the console screen (this line is specific to certain compilers)

    printf("\n Enter How many Numbers: ");
    scanf("%d", &n);

    printf("\nThe Random Numbers are:\n");

    // Generate random numbers and print them
    for (k = 1; k <= n; k++)
    {
        a[k] = rand(); // Generate a random number
        printf("%d\t", a[k]); // Print the random number
    }

    st = clock(); // Start the timer

    // Sort the array using Merge Sort
    MergeSort(a, 1, n);

    et = clock(); // Stop the timer

    ts = (double)(et - st) / CLOCKS_PER_SEC; // Calculate the time taken in seconds

    printf("\nSorted Numbers are: \n");

    // Print the sorted array
    for (k = 1; k <= n; k++)
        printf("%d\t", a[k]);

    printf("\nThe time taken is %e", ts);

    getch(); // Wait for a key press (this line is specific to certain compilers)

    return 0;
}
