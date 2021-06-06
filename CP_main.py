# Coded BY NIFFOXIC

# Modules Start
from __future__ import division, print_function
import sys
import os
from io import BytesIO, IOBase
# Modules End


def greedy_time(arr):
    res = 1
    index = 0
    for i in range(1, len(arr)):
        if arr[index][1] <= arr[i][0]:
            index = i
            res += 1
    return res


def main():
    t = int(input())
    while t:
        t -= 1
        g = []
        for _ in range(int(input())):
            g += [list(map(int, input().split()))]
        g.sort(key=lambda key: key[1])
        print(greedy_time(g))


# region fast_io

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion


# Templates Start
def upper_bound(checking_on_the_arr: list, size_of_the_arr: int, key_we_need: int) -> int:
    index_locally = 0
    while index_locally < size_of_the_arr and checking_on_the_arr[index_locally] <= key_we_need:
        index_locally += 1
    return index_locally
# Templates End


if __name__ == '__main__':
    main()
