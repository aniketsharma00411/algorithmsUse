# Python program for implementation of Level Order Traversal

# Structure of a node
class Node:
    def __init__(self ,key):
        self.data = key
        self.left = None
        self.right = None
        
# print level order traversal
def printLevelOrder(root):
    if root is None:
        return
# create an empty node_queue for Level order Traversal   
    node_queue = [] 
    node_queue.append(root)
    
#print Front of the queue and pop it from the queue
    while(len(node_queue) > 0):
        print (node_queue[0].data)
        node = node_queue.pop(0)
        
# Enqueue left child
        if node.left is not None:
            node_queue.append(node.left)
            
# Enqueue right child
        if node.right is not None:
            node_queue.append(node.right)
 
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print ("Binary tree's level order traversal is :")
printLevelOrder(root)
