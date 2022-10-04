public class HeapSort{
    public void sort(int array[]){
        int len=array.length;
        for(int i=len/2-1;i>=0;i--)
            heapify(array,len,i);

        for(int i=len-1;i>0;i--){
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            heapify(array,i,0);
        }
    }

    public void heapify(int array[], int len, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < len && array[l] > array[largest])
            largest = l;

        if (r < len && array[r] > array[largest])
            largest = r;

        if (largest != i) {
            int swap = array[i];
            array[i] = array[largest];
            array[largest] = swap;

            heapify(array, len, largest);
        }
    }
}