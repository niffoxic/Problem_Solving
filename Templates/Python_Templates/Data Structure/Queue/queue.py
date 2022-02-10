class Queue:
    def __init__(self):
        self.items = []

    def __str__(self):
        return " ".join([str(x) for x in self.items])

    def isEmpty(self):
        return self.items == []

    def enqueue(self, val):
        self.items += [val]
        return True

    def dequeue(self):
        if not self.isEmpty():
            return self.items.pop(0)
        return False

    def peek(self):
        if not self.isEmpty():
            return self.items[0]
        return None

    def delete(self):
        self.items = []
        return True
