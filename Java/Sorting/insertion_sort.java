public class InsertionSort {

    /**
     * Time Complexity: O(n*2)
     * Auxiliary Space: O(1)
     * Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.
     * Stable: Yes
     * Optimisation - Binary Insertion Sort
     *
     * @param array
     */
    static void insertionSort(int array[]) {
        int n = array.length;
        for (int i = 1; i < n; i++) {
            int elem = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > elem) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = elem;
        }
    }

    static void insertionSortRecursive(int array[], int n) {
        if (n == 0 || n == 1)
            return;
        insertionSortRecursive(array, n - 1);
        int elem = array[n - 1];
        int j = n - 2;
        while (j >= 0 && array[j] > elem) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = elem;
    }
}
