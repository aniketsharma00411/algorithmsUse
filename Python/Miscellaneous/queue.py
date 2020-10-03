"""
Queue is a FIFO type of structure. The `list` data type in Python allows for an easy implementation of a Queue.
"""
class Queue:

    def __init__(self) -> None:
        self.queue = []

    def enqueue(self, value) -> None:
        self.queue.append(value)

    def dequeue(self):
        try:
            value = self.queue.pop(0)
        except IndexError:
            print('Queue Underflow')
        else:
            return value

    def peek(self) -> list:
        return self.queue

if __name__ == "__main__":
    data = Queue()
    data.enqueue(10)
    data.enqueue(20)

    print(data.peek())

    print(data.dequeue())
    print(data.dequeue())
    print(data.dequeue())

    print(data.peek())
