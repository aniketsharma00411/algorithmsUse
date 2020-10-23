/**
 * Tower of hanoi problem
 * @param n
 * @param srcT
 * @param desT
 * @param bufferT
 */
function tower(n, srcT, desT, bufferT) {
    if (n >= 1) {

        // Move a tower of n-1 to the buffer tower, using the destination tower.
        tower(n - 1, srcT, bufferT, desT);

        // Move the remaining disk to the destination tower.
        console.log('Move disk from Tower ', srcT, ' to Tower ', desT);

        // Move the tower of `n-1` from the `buffer tower` to the `destination tower` using the `source tower`.
        tower(n - 1, bufferT, desT, srcT);
    }
    return;
}
tower(3, "A", "C", "B");
