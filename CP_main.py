# Coded BY NIFFOXIC

# Modules Start
from __future__ import division, print_function
import sys
import os
import time
from functools import reduce, cache, lru_cache
from io import BytesIO, IOBase
import math
import operator
from collections import defaultdict
# Modules End


def main():
    a = sliding_window([2, 3, 2, 4], 2, "*")
    print(a)


# Settings
sys.setrecursionlimit(10000000)
# Settings End

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


def sieve(n: int) -> list:
    sieve_arr = [True] * n
    sieve_arr[0] = sieve_arr[1] = False
    sieve_arr[4::2] = [False] * len(range(4, len(sieve_arr), 2))
    for i in range(3, int(math.sqrt(len(sieve_arr))) + 1, 2):
        if sieve_arr[i]:
            sieve_arr[i * i::i] = [False] * len(range(i * i, len(sieve_arr), i))
    return sieve_arr
def sliding_window(array: list, window_size: int, operator_string: str) -> int:
    """
    :param array:
    :param window_size:
    :param operator_string: work well with only + - and * for now ( need to update )
    :return: max_value found only ( need to update )
    """
    ops = {
        '+': operator.add,
        '-': operator.sub,
        '*': operator.mul,
        '^': operator.xor,
    }
    ops_back = {
        '+': operator.sub,
        '-': operator.add,
        '*': operator.truediv,
        '^': operator.xor,
    }
    initial = 1 if operator_string == "*" else 0
    for i in range(window_size):
        initial = ops[operator_string](initial, array[i])
    result = initial
    for i in range(window_size, len(array)):
        initial = ops[operator_string](initial, array[i])
        initial = ops_back[operator_string](initial, array[i - window_size])
        result = max(initial, result)
    return int(result) if operator_string == "*" else result


if __name__ == '__main__':
    main()
