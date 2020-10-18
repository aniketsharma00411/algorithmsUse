// test file using jest

const{
    bubbleSort
} = require("../Sorting/bubble_sort")

test('Bubble sort of array(1,5,3,6,4) should be array(1,3,4,5,6)', ()=>{
    expect(bubbleSort(Array(1,5,3,6,4))).toEqual(Array(1,3,4,5,6));
});
