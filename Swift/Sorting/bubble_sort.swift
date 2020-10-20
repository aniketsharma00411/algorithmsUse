func bubbleSort(_ array: [Int]) -> [Int] 
{ 
var arr = array 
for _ in 0...arr.count 
{ 
for 
value in 1...arr.count - 1 
{
 if arr[value-1] > arr[value] 
 {
  let largerValue = arr[value-1] 
  arr[value-1] = arr[value]
   arr[value] = largerValue 
   } 
  } 
  } 
  print("Sorted\(arr)") 
  return arr 
  }
