void main() {
  List<int> array = [5, 1, 4, 2, 8];
  //  We Can take the array as an input also , rather than declaring it here.
  // See the Algorithm in bubleSort Function
  List<int> sortedarray = bubbleSort(array);
  print(sortedarray);
}

// Sorting is done here
bubbleSort(List<int> array) {
  int lengthOfArray = array.length;
  for (int i = 0; i < lengthOfArray - 1; i++) {
    print('Index i at pos: ${i}');
    for (int j = 0; j < lengthOfArray - i - 1; j++) {

      print('Loop:${i}');
      print('index i and j at pos: ${i}  &  ${j}');

      if (array[j] > array[j + 1]) {
        // Swapping using temporary variable temp


        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;

        print(
            'Element at pos j and j+1 after swap: ${array[j]} & ${array[j + 1]}');
      }
    }
  }
  return (array);
}