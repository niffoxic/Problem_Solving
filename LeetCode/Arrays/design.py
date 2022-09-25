class MyCircularQueue:

    def __init__(self, k: int):
        self.size = k
        self.length = 0
        self.front_pointer = 0
        self.buffer = []

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.buffer.append(value)
        self.length += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front_pointer += 1
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.buffer[self.front_pointer]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.buffer[-1]

    def isEmpty(self) -> bool:
        return (self.length - self.front_pointer) == 0

    def isFull(self) -> bool:
        return (self.length - self.front_pointer) == self.size
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
