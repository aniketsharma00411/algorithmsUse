function mergeSort(list) {
    // Getting the half part of the list
    let half = list.length / 2;
    if (list.length < 2) {
        return list;
    }

    // Getting the left part of the list, by default the other part will be the right
    const left = list.splice(0, half);

    // Call merge function and mergeSort recursively to solve the sorting
    return merge(mergeSort(left), mergeSort(list));
}

function merge(left, right) {

    let list = [];

    // Main loop through the left and right parts to merge them sorted
    while (left.length && right.length) {
        // Execute the comparison statement
        if (left[0] < right [0]) {
            list.push(left.shift());
        } else {
            list.push(right.shift());
        }
    }

    // Return the list sorted and merged with the rest operator.
    return [...list, ...left, ...right];
}


const array = [4, 7, 2, 3, 6, 8, 0, 3, 2, 7, 56, 23, 12, 43];

console.log(mergeSort(array));
