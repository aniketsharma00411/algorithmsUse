const {binarySearch} = require('../Searching/binary_search');

  test('#1: binary search of element 2 in an empty array should be -1', () => {
    expect(binarySearch(Array(), 2)).toEqual(-1);
  });

  test('#2: binary search of element 2 in an sorted odd array should be -1', () => {
    expect(binarySearch(Array(1,3,5,7,9))).toEqual(-1);
  });

  test('#3: binary search of element 2 in an sorted even array(2,4,6,8,10) should be 0', () => {
    expect(binarySearch(Array(2,4,6,8,10), 2)).toEqual(0);
  });

  test('#4: binary search of element 5 in an sorted even array(4,7,5,9,10,11,12) should be 2', () => {
    expect(binarySearch(Array(4,7,5,9,10,11,12), 5)).toEqual(2);
  });

  test('#5: binary search of element 26 in an sorted even array(20,22,24,19,26) should be 4', () => {
    expect(binarySearch(Array(20,22,24,19,26), 26)).toEqual(4);
  });
