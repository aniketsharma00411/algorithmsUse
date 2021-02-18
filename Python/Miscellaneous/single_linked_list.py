class Node():
    
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList():

    def __init__(self):
        self.head = None

    def append(self,data):
        new_node = Node(data)
        cur_node = self.head

        if self.head is None:
            self.head = new_node
            return
        
        while cur_node.next:
            cur_node = cur_node.next
        cur_node.next = new_node

    def prepend(self,data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
    
    def print_node(self):
        cur_node = self.head
        while cur_node:
            print(cur_node.data)
            cur_node = cur_node.next
    
    def insert_nextto_node(self,prev_node, data):
        new_node = Node(data)
        new_node.next = prev_node.next
        prev_node.next = new_node

    def delete_node(self,key):
        cur_node = self.head
        if cur_node and cur_node.data == key:
            self.head = cur_node.next
            cur_node = None
            return 

        prev = None
        while cur_node and cur_node.data != key:
            prev = cur_node
            cur_node = cur_node.next
        if cur_node is None:
            return
        prev.next = cur_node.next
        cur_node = None



sll = LinkedList()
sll.append('A')
sll.append('B')
sll.append('C')
sll.prepend('E')
sll.delete_node('A')
sll.print_node()