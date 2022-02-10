class Stack:
    def __init__(self, size):
        self.max_size = size
        self.stack_list = []

    def __str__(self):
        return " ".join([str(x) for x in reversed(self.stack_list)])

    def isEmpty(self):
        return self.stack_list == []

    def isFull(self):
        return len(self.stack_list) == self.max_size

    def push(self, val):
        if not self.isFull():
            self.stack_list += [val]
            return True
        return False

    def peek(self):
        return None if self.isEmpty() else self.stack_list[-1]

    def delete(self):
        self.stack_list = []
        return True
