"""
Stack is a LIFO type of structure. the `list` data type in Python allows for an easy implementation of a Stack.
"""
# create an empty stack
stack = []

# add items to the stack [PUSH]
stack.append(5)
stack.append(20)
stack.append(12)
print('PUSHed into the stack')

# print stack
print('Stack:')
print(stack) # [5, 20, 12]

# access items stored in stack [POP]
print('POPing items from the stack')
print(stack.pop()) # 12
print(stack.pop()) # 20

# print stack
print('Stack:')
print(stack) # [5]
