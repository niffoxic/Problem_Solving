class SegmentTree:
    def __init__(self, array: list):
        self.seg = [0] * (len(array) * 4)
        self.arr = array

    def build(self, left_index, right_index, index):
        """
         Change last list for required Queries / by default its summation
        :param left_index: start index
        :param right_index: end index (max size - 1)
        :param index: segment tree index
        :return: build segment tree for summation query
        """
        if left_index == right_index:
            self.seg[index] = self.arr[left_index]
            return
        mid = left_index + (right_index - left_index) // 2
        self.build(left_index, mid, index * 2 + 1)
        self.build(mid + 1, right_index, index * 2 + 2)
        self.seg[index] = self.seg[index * 2 + 1] + self.seg[index * 2 + 2]

    def get(self, qleft, qright, left, right, index):
        if qleft > right or qright < left:
            return 0
        if qleft <= left and qright >= right:
            return self.seg[index]
        mid = left + (right - left) // 2
        return self.get(qleft, qright, left, mid, index * 2 + 1) + self.get(qleft, qright, mid + 1, right, index * 2 + 2)

    def update(self, position, value, left, right, index):
        if position == left or position == right:
            self.seg[index] = value
            return
        mid = left + (right - left) // 2
        if position <= mid:
            self.update(position, value, left, mid, index * 2 + 1)
        else:
            self.update(position, value, mid + 1, right, index * 2 + 2)
        self.seg[index] = self.seg[index * 2 + 1] + self.seg[index * 2 + 2]
