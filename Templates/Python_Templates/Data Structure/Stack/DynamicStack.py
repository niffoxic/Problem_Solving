class DynamicStack:
    def __init__(self):
        self.stack_list = []

    def __str__(self):
        return " ".join([str(x) for x in reversed(self.stack_list)])

    def isEmpty(self):
        return self.stack_list == []

    def push(self, val):
        self.stack_list += [val]
        return True

    def pop(self):
        if self.isEmpty():
            return False
        return self.stack_list.pop()

    def peek(self):
        return None if self.isEmpty() else self.stack_list[-1]
