#include <iostream>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void maxHeapify(int arr[], int parent, int n) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int largest = parent;

    if (left < n && arr[left] > arr[largest])  // Fixed condition
        largest = left;
    if (right < n && arr[right] > arr[largest]) // Fixed condition
        largest = right;

    if (largest != parent) {
        swap(&arr[parent], &arr[largest]);  // Fixed swap function call
        maxHeapify(arr, largest, n);
    }
}

int main() {
    int arr[] = {10, 5, 3, 15, 23, 14, 26, 18, 1, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Build Max Heap (Heapify process)
    for (int parent = n / 2 - 1; parent >= 0; parent--)
       maxHeapify(arr, parent, n);
        
    //heap sort
    int scope = n;
    while(scope>0)
    {
        swap(arr,arr+scope-1);
        maxHeapify(arr,0,scope-1);
        scope--;
    }
  printf("Sorted: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);  // Fixed formatting
    printf("\n");
    return 0;
}
