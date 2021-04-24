# https: // www.acmicpc.net/problem/2447
# 사실상 시에르핀스키 카펫이다

arr = [[]]


def block(i, j, n):
    if n < 3:
        return

    n //= 3

    for a in range(n):
        for b in range(n):
            arr[i+n+a][j+n+b] = " "

    for a in range(3):
        for b in range(3):
            block(i + n*a, j + n*b, n)


def sol():
    global arr

    n = int(input())

    arr = [["*" for _ in range(n)] for _ in range(n)]

    block(0, 0, n)

    for i in arr:
        print("".join(i))


if __name__ == "__main__":
    sol()
