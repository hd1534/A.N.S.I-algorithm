# https://www.acmicpc.net/problem/2775

arr = [[i for i in range(15)]] \
    + [[0 for _ in range(15)] for _ in range(14)]


# 14개 까지만 있으니 그냥 다 구해도 시간 얼마 안걸림
i = 0
while i < 14:
    j = 1
    while j < 15:
        k = j
        while k < 15:
            arr[i+1][k] += arr[i][j]
            k += 1
        j += 1
    i += 1


for i in range(int(input())):
    k = int(input())
    n = int(input())

    print(arr[k][n])
