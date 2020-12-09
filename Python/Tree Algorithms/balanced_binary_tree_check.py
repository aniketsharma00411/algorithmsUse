# Python program for implementation of Balanced Binary Tree Check

class Node: 
    def __init__(self, data): 
        self.data = data 
        self.left = None
        self.right = None
        
# compute tree's height
def height(root): 
    if root is None: 
        return 0
    return max(height(root.left), height(root.right)) + 1
  
def isBalanced(root): 
# For a None tree balance
    if root is None: 
        return True
    
# compute left root height
    left_height = height(root.left) 
# compute right root height
    right_height = height(root.right) 
    
# if the left height and right height of tree is more than 1, then the tree is not balanced
    if (abs(leftheight - rightheight) <= 1) and isBalanced(root.left) is True 
    
# if the right subtree is not balanced, this tree is not balanced then also     
    and isBalanced( root.right) is True: 
        return True
    return False
  
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
root.left.left.left = Node(8) 

print("Is the given tree balanced? ")
result = "True" if isBalanced(root) else "False"
print(result)
