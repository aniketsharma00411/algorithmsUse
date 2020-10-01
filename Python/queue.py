"""
Queue is a FIFO type of structure. The `list` data type in Python allows for an easy implementation of a Queue.
"""
# create an empty queue
queue = []

# add items to the queue
queue.append(5)
queue.append(20)
queue.append(12)
print('Added items into the queue')

# print queue
print('Queue:')
print(queue) # [5, 20, 12]

# access items stored in queue [POP]
# pop(0) returns the first element in the list
print('POPing items from the queue')
print(queue.pop(0)) # 5
print(queue.pop(0)) # 20

# print queue
print('Queue:')
print(queue) # [12]
