void main(){
  List<int> arr = [10,20,30,40,50,60,70,80];          //here array is hardcoded for functioning but instead of this we can take the array 
  int x = 50;                                         // as user input as well
  int result = linearSearch(arr, x);
  print(result);
}


// This is the function with the searching algorithm
linearSearch(List<int> array, int x){

  for(int i = 0; i< array.length; i++){
    
    if(array[i] == x){
      return i;

    }
  }
}