# https://www.acmicpc.net/problem/10250

from math import ceil

for i in range(int(input())):
    h, w, n = map(int, input().split())
    print("%d%02d" % ((n - 1) % h + 1, ceil(n / h)))
