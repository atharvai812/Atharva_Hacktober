#include <stdio.h>

void merge(int arr[], int p, int q, int r) {
  // Find the sizes of the two subarrays to be merged
  int n1 = q - p + 1;
  int n2 = r - q;

  // Create two temporary arrays
  int L[n1], M[n2];

  // Copy the data from the array arr to the temporary arrays L and M
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Initialize the indexes of the first and second subarrays
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Merge the two subarrays L and M into the array arr
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L to arr
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of M to arr
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point of the array
    int m = (l + r) / 2;

    // Recursively sort the first and second halves of the array
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the two halves of the array
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver code
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted Array: \n");
  printArray(arr, size);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
  return 0;
}
