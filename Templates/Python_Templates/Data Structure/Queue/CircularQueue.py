class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.item = [None] * size
        self.start = -1
        self.top = -1

    def __str__(self):
        return " ".join([str(i) for i in range(self.item)])

    def isFull(self):
        if self.top + 1 == self.start:
            return True
        elif self.start == 0 and self.top + 1 == self.size:
            return True
        return False

    def isEmpty(self):
        return self.top == -1

    def enqueue(self, val):
        if self.isFull():
            return None
        if self.top + 1 == self.size:
            self.top = 0
        else:
            self.top += 1
            if self.top == -1:
                self.start = 0
            self.item[self.top] = val
            return True

    def dequeue(self):
        if self.isEmpty():
            return None
        else:
            delete_current = self.item[self.start]
            self.item[self.start] = None
            if self.start == self.top:
                self.start = -1
                self.top = -1
            elif self.start + 1 == self.size:
                self.start = 0
            else:
                self.start += 1
            return delete_current

    def peek(self):
        return None if self.isEmpty() else self.item[self.start]

    def delete(self):
        self.item = [None] * self.size
        self.top = self.start = -1
