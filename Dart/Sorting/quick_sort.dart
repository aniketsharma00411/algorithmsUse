/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(List<int> arr, int low, int high) {
  int pivot = arr[high]; // pivot
  int i = (low - 1); // Index of smaller element
  int temp;

  for (int j = low; j <= high - 1; j++) {
// If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element

      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(List<int> arr, int low, int high) {
  if (low < high) {
/* pi is partitioning index, arr[p] is now
		at right place */
    int pi = partition(arr, low, high);

// Separately sort elements before
// partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

/* Function to print an array */
void printArray(List<int> arr) {
  int i;
  int size = arr.length;
  for (i = 0; i < size; i++) print("${arr[i]} ");
  print("\n");
}

// Driver Code
int main() {
  List<int> arr = [10, 7, 8, 9, 1, 5];
  int n = arr.length;
  quickSort(arr, 0, n - 1);
  print("Sorted array: \n");
  printArray(arr);
  return 0;
}
