def isAnagram(str1, str2):
  if len(str1) != len(str2):
    return False
  frequency = {}
  for val in str1:
    if val in frequency:
      frequency[val] += 1
    else:
      frequency[val] = 1
  for val in str2:
    if val not in frequency or frequency[val] == 0:
      return False
    else: 
      frequency[val] -= 1
  return True
