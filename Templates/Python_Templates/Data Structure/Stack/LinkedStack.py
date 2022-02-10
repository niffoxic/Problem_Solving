class Node:
    def __init__(self, val=None):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None


class LinkedStack:
    def __init__(self):
        self.ll = LinkedList()

    def isEmpty(self):
        return self.ll.head is None

    def push(self, val):
        node = Node(val)
        node.next = self.ll.head
        self.ll.head = node
        return True

    def pop(self):
        if self.isEmpty():
            return None
        temp = self.ll.head.val
        self.ll.head = self.ll.head.next
        return temp

    def peek(self):
        return None if self.isEmpty() else self.ll.head.val

    def delete(self):
        self.ll.head = None
