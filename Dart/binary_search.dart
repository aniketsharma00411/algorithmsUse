
// main function
void main() {
  List<int> arr = [0, 1, 3, 4, 5, 8, 9, 22];
  int userValue = 3;
  int min = 0;
  int max = arr.length - 1;
  //Here a hard-coded array is used instead of this we can even take array as an input and search an inputted element
  binarySearchAlgo(arr, userValue, min, max);

}

binarySearchAlgo(List<int> arr, int userValue, int min, int max) {
  if (max >= min) {

    // If the element is present at the middle
    int mid = ((max + min) / 2).floor();
    if (userValue == arr[mid]) {
      print('your item is at index: ${mid}');
    }

// If element is bigger than mid, then
    // it can only be present in right subarray

    else if (userValue > arr[mid]) {
      binarySearchAlgo(arr, userValue, mid + 1, max);
    }
// Else the element can only be present
    // in right subarray

    else {
      binarySearchAlgo(arr, userValue, min, mid - 1);
    }
  }
  return null;
}