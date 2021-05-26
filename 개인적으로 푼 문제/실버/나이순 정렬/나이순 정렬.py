# https://www.acmicpc.net/problem/10814


def sol():
    arr = []
    for i in range(int(input())):
        a, b = input().split()
        arr.append((int(a), i, b))

    for i, _, j in sorted(arr):
        print(i, j)


if __name__ == "__main__":
    sol()
