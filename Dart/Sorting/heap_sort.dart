//Algorithm
//# heapify
//for i = n/2:1, sink(a,i,n)
//-> invariant: a[1,n] in heap order
//
//# sortdown
//for i = 1:n,
//    swap a[1,n-i+1]
//    sink(a,1,n-i)
//    -> invariant: a[n-i+1,n] in final position
//end
//
//# sink from i in a[1..n]
//function sink(a,i,n):
//    # {lc,rc,mc} = {left,right,max} child index
//    lc = 2*i
//    if lc > n, return # no children
//    rc = lc + 1
//    mc = (rc > n) ? lc : (a[lc] > a[rc]) ? lc : rc
//    if a[i] >= a[mc], return # heap ordered
//    swap a[i,mc]
//    sink(a,mc,n)

//Properties
//Not stable
//O(1) extra space (see discussion)
//O(n*lg(n)) time
//Not really adaptive

//Discussion
//Heap sort is simple to implement, performs an O(n*lg(n)) in-place sort, but is not stable.
//
//The first loop, the Theta(n) "heapify" phase, puts the array into heap order. The second loop, 
//the O(n*lg(n)) "sortdown" phase, repeatedly extracts the maximum and restores heap order.
//
//The sink function is written recursively for clarity. Thus, as shown, the code requires 
//Theta(lg(n)) space for the recursive call stack. However, the tail recursion in sink() is easily 
//converted to iteration, which yields the O(1) space bound.
//
//Both phases are slightly adaptive, though not in any particularly useful manner. In the nearly sorted case, 
//the heapify phase destroys the original order. In the reversed case, the heapify phase is as fast as possible 
//since the array starts in heap order, but then the sortdown phase is typical. In the few unique keys case, 
//there is some speedup but not as much as in shell sort or 3-way quicksort.


class HeapSort {

  static void sort(List<Comparable> pq) { 
    
    int N = pq.length;
    for (int k = (N/2).toInt(); k >= 1; k--) {
      _sink(pq, k, N);
    }
    
    while (N > 1) {
      _exch(pq, 1, N--);
      _sink(pq, 1, N);
    }
  }
  
  //Helper functions to restore the heap invariant.
  static void _sink(List<Comparable> pq, int k, int N) {
    while (2*k <= N) {
      int j = 2*k;
      if (j < N && _lessWithComparable(pq, j, j+1)) {
        j++;
      }
      
      if (!_lessWithComparable(pq, k, j)) {
        break;
      }
      
      _exch(pq, k, j);
      k = j;
    }
  }
  
  //
  //Helper functions for comparisons and swaps.
  //Indices are "off-by-one" to support 1-based indexing.
  static bool _lessWithComparable(List<Comparable> pq, int i, int j) {
    return pq[i-1].compareTo(pq[j-1]) < 0;
  }
  
  static void _exch(List pq, int i, int j) {
    var swap = pq[i-1];
    pq[i-1] = pq[j-1];
    pq[j-1] = swap;
  }
  
  // is v < w ?
  static bool _less(Comparable v, Comparable w) {
    return (v.compareTo(w) < 0);
  }
  
  // Check if array is sorted - useful for debugging
  static bool _isSorted(List<Comparable> a) { 
    for(int i=1; i<a.length; i++) {
      if (_less(a[i], a[i-1])) {
        return false;
      }
    }
    
    return true; 
  }
  
  // print to standard output
  static show(List<Comparable> a) {
    for (int i = 0; i < a.length; i++) {
      print(a[i]);
    }
  }
}