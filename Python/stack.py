"""
Stack is a LIFO type of structure. the `list` data type in Python allows for an easy implementation of a Stack.
"""
class Stack:

    def __init__(self) -> None:
        self.stack = []

    def push(self, value) -> None:
        self.stack.append(value)

    def pop(self):
        try:
            value = self.stack.pop()
        except IndexError:
            print('Stack Underflow')
        else:
            return value

    def peek(self) -> list:
        return self.stack

if __name__ == "__main__":
    data = Stack()
    data.push(10)
    data.push(20)

    print(data.peek())

    print(data.pop())
    print(data.pop())
    print(data.pop())

    print(data.peek())
