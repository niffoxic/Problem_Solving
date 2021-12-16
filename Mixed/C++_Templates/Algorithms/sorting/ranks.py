from heapq import heappop, heapify, heappush

__all__ = ["newRankList"]


class newRankList:

    def __init__(self):
        self.data = list()

    def add_data(self, val: list):
        """
        Course_id, rating, views, reviews
        """
        self.data += [val]

    def __comp__(self, a: int, b: int):
        """
        This function will check the variables
        :return: boolean value for the comparison values
        """
        if self.data[a][1] == self.data[b][1]:
            if self.data[a][2] == self.data[b][2]:
                if self.data[a][3] == self.data[b][3]:
                    return self.data[a][0] <= self.data[b][0]
                return self.data[a][3] >= self.data[b][3]
            return self.data[a][2] > self.data[b][2]
        return self.data[a][1] > self.data[b][1]

    def __hoarse__(self, left, right):
        """
        :param left: left limit of the chunk
        :param right: right limit of the chunk
        :return: index value greater than left half and less than right half
        """
        pivot = left
        i = left - 1
        j = left

        while j <= right:
            if self.__comp__(j, pivot):
                i += 1
                self.data[j], self.data[i] = self.data[i], self.data[j]
            j += 1
        self.data[left], self.data[i] = self.data[i], self.data[left]
        return i

    def __ordering__(self, left, right):
        if left >= right:
            return
        partition = self.__hoarse__(left, right)
        self.__ordering__(left, partition - 1)
        self.__ordering__(partition + 1, right)

    def reset_rank(self):
        self.__ordering__(0, len(self.data) - 1)

    def get_rank(self):
        return self.data
