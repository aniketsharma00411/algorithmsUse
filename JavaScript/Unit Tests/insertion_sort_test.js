const {insertionSort} = require("../Sorting/insertion_sort.js");
test('#1: insertion sort of array(5,4,3,2,1) should be array(1,2,3,4,5)', () => {
    expect(insertionSort(Array(5,4,3,2,1))).toEqual(Array(1,2,3,4,5));
  });

  test('#2: insertion sort of array(10,6,200,1,50) should be array(1,6,10,50,200)', () => {
    expect(insertionSort(Array(10,6,200,1,50))).toEqual(Array(1,6,10,50,200));
  });

  test('#3: insertion sort of array(20,22,24,19,26) should be array(19,20,22,24,26)', () => {
    expect(insertionSort(Array(20,22,24,19,26))).toEqual(Array(19,20,22,24,26));
  });

  test('#4: insertion sort of array(1,2,3,4,5) should be array(1,2,3,4,5)', () => {
    expect(insertionSort(Array(1,2,3,4,5))).toEqual(Array(1,2,3,4,5));
  });

  test('#5: insertion sort of array(50,35,60,44,55) should be array(35,44,50,55,60)', () => {
    expect(insertionSort(Array(50,35,60,44,55))).toEqual(Array(35,44,50,55,60));
  });

