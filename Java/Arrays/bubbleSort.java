public static void bubbleSort(int[] array){
    int len = array.length;
    for(int i=0;i<len-1;i++){
            for(int j=0;j<len-i-1;j++){
                if(array[j]>array[j+1]){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
            }
        }
    }
}